//
// Created by Kenneth Hurley on 9/24/24.
//

#ifndef TRANSACTIONVERIFIERCIRCUIT_HPP
#define TRANSACTIONVERIFIERCIRCUIT_HPP

#include <nil/crypto3/algebra/curves/pallas.hpp>
#include <nil/crypto3/algebra/random_element.hpp>
#include <cstdint>
#include <array>

static constexpr std::size_t MAX_RANGES = 4;

using namespace nil::crypto3::algebra::curves;

[[circuit]] bool ValidateTransaction(
    [[private_input]] typename pallas::scalar_field_type::value_type balance, [[private_input]] typename pallas::scalar_field_type::value_type amount,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type        balance_commitment,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type        amount_commitment,
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type        expected_new_balance_commitment,
    const typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type &generator,
    std::array<typename pallas::scalar_field_type::value_type, MAX_RANGES> ranges,       // Public parameter for upper bounds
    [[private_input]] typename pallas::scalar_field_type::value_type       base_seed,    // Base seed for TOTP as a field element
    [[private_input]] typename pallas::scalar_field_type::value_type       provided_totp // Provided TOTP to validate
);

#endif //TRANSACTIONVERIFIERCIRCUIT_HPP
