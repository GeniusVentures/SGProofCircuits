/**
 * @file       TransactionVerifierCircuitTOTP.hpp
 * @brief      Header file of the circuit that validate the transaction as well as TOTP
 * @date       2025-01-30
 * @author     Henrique A. Klein (hklein@gnus.ai)
 */

#ifndef _TRANSACTION_VERIFIER_CIRCUIT_TOTP_HPP_
#define _TRANSACTION_VERIFIER_CIRCUIT_TOTP_HPP_

#include <nil/crypto3/algebra/curves/pallas.hpp>
#include <nil/crypto3/algebra/random_element.hpp>
#include <cstdint>
#include <array>
#include "TransactionValidator.hpp"

using namespace nil::crypto3::algebra::curves;


/**
 * @brief       Validates the transaction and TOTP
 * @param[in]   balance The raw balance in integer form
 * @param[in]   amount The raw amount in integer form
 * @param[in]   balance_scalar The raw balance in scalar form
 * @param[in]   amount_scalar The raw amount in scalar form
 * @param[in]   balance_commitment The balance multiplied by a generator (mapped to a curve)
 * @param[in]   amount_commitment The amount multiplied by a generator (mapped to a curve)
 * @param[in]   expected_new_balance_commitment  The new balance multiplied by a generator (mapped to a curve)
 * @param[in]   generator  The generator that is used to map values to the curve
 * @param[in]   ranges Array of possible ranges of the amount
 * @param[in]   base_seed The base seed used by TOTP
 * @param[in]   provided_totp The TOTP 
 * @return      True if transaction and TOTP are valid, false otherwise
 */
[[circuit]] bool ValidateTransactionTOTP(
    [[private_input]] uint64_t                                                                        balance,                         //
    [[private_input]] uint64_t                                                                        amount,                          //
    [[private_input]] pallas::scalar_field_type::value_type                                           balance_scalar,                  //
    [[private_input]] pallas::scalar_field_type::value_type                                           amount_scalar,                   //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type balance_commitment,              //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type amount_commitment,               //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type expected_new_balance_commitment, //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type generator,                       //
    std::array<pallas::scalar_field_type::value_type, MAX_RANGES>                                     ranges,                          //
    [[private_input]] pallas::scalar_field_type::value_type                                           base_seed,                       //
    [[private_input]] pallas::scalar_field_type::value_type                                           provided_totp );

#endif //_TRANSACTION_VERIFIER_CIRCUIT_TOTP_HPP_
