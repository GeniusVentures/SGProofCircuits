#include "MPCVerifierCircuit.hpp"

using namespace nil::crypto3::algebra::curves;

// Function to validate the total aggregate against the expected total value
[[circuit]] bool MPCValidateTransaction(
    [[private_input]] typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type
                                                                   total_random_sum, // Sum of all node random numbers
    [[private_input]] typename pallas::scalar_field_type::value_type balance, [[private_input]] typename pallas::scalar_field_type::value_type amount,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type        balance_commitment,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type        amount_commitment,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type        expected_new_balance_commitment,
    const typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type &generator,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type
        total_aggregate // Sum of the final values from all nodes
)
{
    // Check if the total aggregate equals the expected total
    bool aggregate_validity = ( total_aggregate == total_random_sum ); // Expecting the total_random_sum to be precomputed with * 2

    // Validate balance conditions
    bool balance_conditions = ( balance >= amount );

    // Validate commitments
    bool valid_balance_commitment     = ( balance_commitment == ( generator * balance ) );
    bool valid_amount_commitment      = ( amount_commitment == ( generator * amount ) );
    bool valid_new_balance_commitment = ( expected_new_balance_commitment == ( generator * ( balance - amount ) ) );

    // Ensure all conditions are met
    return aggregate_validity && balance_conditions && valid_balance_commitment && valid_amount_commitment && valid_new_balance_commitment;
}