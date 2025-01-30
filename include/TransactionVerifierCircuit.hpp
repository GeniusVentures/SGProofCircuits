//
// Created by Kenneth Hurley on 9/24/24.
//

#ifndef TRANSACTIONVERIFIERCIRCUIT_HPP
#define TRANSACTIONVERIFIERCIRCUIT_HPP

#include <nil/crypto3/algebra/curves/pallas.hpp>
#include <nil/crypto3/algebra/random_element.hpp>
#include <cstdint>
#include <array>
#include "TransactionValidator.hpp"

using namespace nil::crypto3::algebra::curves;


/**
 * @brief       Circuit that validates the transaction
 * @param[in]   balance The raw balance in integer form
 * @param[in]   amount The raw amount in integer form
 * @param[in]   balance_scalar The raw balance in scalar form
 * @param[in]   amount_scalar The raw amount in scalar form
 * @param[in]   balance_commitment The balance multiplied by a generator (mapped to a curve)
 * @param[in]   amount_commitment The amount multiplied by a generator (mapped to a curve)
 * @param[in]   expected_new_balance_commitment  The new balance multiplied by a generator (mapped to a curve)
 * @param[in]   generator  The generator that is used to map values to the curve
 * @param[in]   ranges Array of possible ranges of the amount
 * @return      True if transaction is valid, false otherwise
 */
[[circuit]] bool ValidateTransaction(
    [[private_input]] uint64_t                                                                        balance,                         //
    [[private_input]] uint64_t                                                                        amount,                          //
    [[private_input]] pallas::scalar_field_type::value_type                                           balance_scalar,                  //
    [[private_input]] pallas::scalar_field_type::value_type                                           amount_scalar,                   //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type balance_commitment,              //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type amount_commitment,               //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type expected_new_balance_commitment, //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type generator,                       //
    std::array<pallas::scalar_field_type::value_type, MAX_RANGES>                                     ranges );

#endif //TRANSACTIONVERIFIERCIRCUIT_HPP
