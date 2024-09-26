//
// Created by Your Name on 10/04/24.
//

#ifndef MPCVERIFIERCIRCUIT_HPP
#define MPCVERIFIERCIRCUIT_HPP

#include <nil/crypto3/algebra/curves/pallas.hpp>

using namespace nil::crypto3::algebra::curves;

// Function to validate the total aggregate against the expected total value
[[circuit]] bool MPCValidateTransaction(
    [[private_input]] typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type total_random_sum, // Sum of all node random numbers
    [[private_input]] typename pallas::base_field_type::value_type balance,
    [[private_input]] typename pallas::base_field_type::value_type amount,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type balance_commitment,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type amount_commitment,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type expected_new_balance_commitment,
    const typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type& generator,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type total_aggregate // Sum of the final values from all nodes
);

#endif //MPCVERIFIERCIRCUIT_HPP