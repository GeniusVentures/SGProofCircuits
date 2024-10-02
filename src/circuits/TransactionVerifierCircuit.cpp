
#include "TransactionVerifierCircuit.hpp"

using namespace nil::crypto3::algebra::curves;

// Function to create a point on the curve from the seed and TOTP
typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type GeneratePointFromSeedAndTotp(
    typename pallas::scalar_field_type::value_type seed,          // The base seed for TOTP as a field element
    typename pallas::scalar_field_type::value_type provided_totp, // Provided TOTP to validate
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type generator // The curve generator
)
{
    // Create a point on the curve using the seed
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type point = seed * generator; // Seed as a point

    // Use provided TOTP directly to create an offset
    typename pallas::scalar_field_type::value_type totp_offset = provided_totp; // Use by value

    // Adjust the point with TOTP offset
    point = point + ( totp_offset * generator ); // Add TOTP offset to the point

    return point; // Return the new point
}

[[circuit]] bool ValidateTransaction(
    [[private_input]] uint64_t                                                                        balance,                         //
    [[private_input]] uint64_t                                                                        amount,                          //
    [[private_input]] pallas::scalar_field_type::value_type                                           balance_scalar,                  //
    [[private_input]] pallas::scalar_field_type::value_type                                           amount_scalar,                   //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type balance_commitment,              //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type amount_commitment,               //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type expected_new_balance_commitment, //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type generator,                       //
    std::array<pallas::scalar_field_type::value_type, MAX_RANGES>                                     ranges, // Public parameter for upper bounds
    [[private_input]] typename pallas::scalar_field_type::value_type base_seed,                               // Base seed for TOTP as a field element
    [[private_input]] typename pallas::scalar_field_type::value_type provided_totp                            // Provided TOTP to validate
)
{
    //TODO Arithmetic operations are not supported with scalar_field_type and curve multiplication is not supported with int
    // Initialize low bounds
    //typename pallas::scalar_field_type::value_type lowBounds = 0;

    // Determine the transfer amount range
    //for ( uint64_t i = 0; i < MAX_RANGES; i++ )
    //{
    // if ((amount_scalar >= lowBounds) && (amount_scalar < ranges[i])) {
    //     break; // Exit loop once the range is found
    // }
    //lowBounds = ranges[i]; // Update low bounds for the next range check
    //}
    //typename pallas::template g1_type<coordinates::affine>::value_type generator( X_generator, Y_generator );
    //The
    auto calculated_balance_point = balance_scalar * generator;
    auto calculated_amount_point  = amount_scalar * generator;
    //auto                                         calculated_balance_point = balance_scalar * generator;

    // Flag to determine if TOTP should be checked
    bool is_totp_valid = true; // Assume TOTP is valid if not checked

    // Only perform TOTP validation if base_seed is not zero
    if ( base_seed != 0 )
    {
        // Generate elliptic curve point from seed and provided TOTP
        auto generated_point = GeneratePointFromSeedAndTotp( base_seed, provided_totp, generator );

        // Validate if generated point corresponds to some valid criteria
        is_totp_valid = ( generated_point == ( base_seed * generator + ( provided_totp * generator ) ) ); // Example check
    }

    if ( balance >= amount && is_totp_valid )
    {

        // Verify that the commitments match the expected values
        bool valid_balance_commitment = ( calculated_balance_point == balance_commitment );
        bool valid_amount_commitment  = ( calculated_amount_point == amount_commitment );
        //bool valid_new_balance_commitment = ( expected_new_balance_commitment == ( generator * new_balance ) );
        if ( valid_balance_commitment && valid_amount_commitment /* && valid_new_balance_commitment*/ )
        {
            return true;
        }
    }

    return false;
}
