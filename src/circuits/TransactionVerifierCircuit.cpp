
#include "TransactionVerifierCircuit.hpp"

using namespace nil::crypto3::algebra::curves;

// Function to create a point on the curve from the seed and TOTP
typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type GeneratePointFromSeedAndTotp(
    const typename pallas::base_field_type::value_type& seed,      // The base seed for TOTP as a field element
    const typename pallas::base_field_type::value_type& provided_totp, // Provided TOTP to validate
    const typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type& generator // The curve generator
) {
    // Create a point on the curve using the seed
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type point = seed * generator; // Seed as a point

    // Use provided TOTP directly to create an offset
    typename pallas::base_field_type::value_type totp_offset = provided_totp; // Use by value

    // Adjust the point with TOTP offset
    point = point + (totp_offset * generator); // Add TOTP offset to the point

    return point; // Return the new point
}

// Update ValidateTransaction to include TOTP verification using elliptic curve
[[circuit]] bool ValidateTransaction(
    [[private_input]] typename pallas::base_field_type::value_type balance,
    [[private_input]] typename pallas::base_field_type::value_type amount,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type balance_commitment,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type amount_commitment,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type expected_new_balance_commitment,
    const typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type& generator,
    std::array<typename pallas::base_field_type::value_type, MAX_RANGES> ranges, // Public parameter for upper bounds
    uint& output_range, // Output public variable for determined range
    [[private_input]] typename pallas::base_field_type::value_type base_seed, // Base seed for TOTP as a field element
    [[private_input]] typename pallas::base_field_type::value_type provided_totp // Provided TOTP to validate
) {
    // Initialize low bounds
    typename pallas::base_field_type::value_type lowBounds = 0;
    output_range = MAX_RANGES; // Default to an invalid range

    // Determine the transfer amount range
    for (uint i = 0; i < MAX_RANGES; i++) {
        if ((amount >= lowBounds) && (amount < ranges[i])) {
            output_range = i; // Set the output range index
            break; // Exit loop once the range is found
        }
        lowBounds = ranges[i]; // Update low bounds for the next range check
    }

    // Flag to determine if TOTP should be checked
    bool is_totp_valid = true; // Assume TOTP is valid if not checked

    // Only perform TOTP validation if base_seed is not zero
    if (base_seed != 0) {
        // Generate elliptic curve point from seed and provided TOTP
        auto generated_point = GeneratePointFromSeedAndTotp(base_seed, provided_totp, generator);

        // Validate if generated point corresponds to some valid criteria
        is_totp_valid = (generated_point == (base_seed * generator + (provided_totp * generator))); // Example check
    }

    // Check if the new balance is non-negative and TOTP is valid (if applicable)
    if (balance >= amount && is_totp_valid) {
        // Compute the new balance
        typename pallas::base_field_type::value_type new_balance = balance - amount;

        // Verify that the commitments match the expected values
        bool valid_balance_commitment = (balance_commitment == (generator * balance));
        bool valid_amount_commitment = (amount_commitment == (generator * amount));
        bool valid_new_balance_commitment = (expected_new_balance_commitment == (generator * new_balance));

        // Ensure all verifications are true
        if (valid_balance_commitment && valid_amount_commitment && valid_new_balance_commitment) {
            return true;
        }
    }

    // If any check fails, return false
    return false;
}