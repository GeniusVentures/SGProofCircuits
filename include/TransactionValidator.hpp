/**
 * @file       TransactionValidator.hpp
 * @brief      Header file of functions used to validate a transaction
 * @date       2025-01-29
 * @author     Henrique A. Klein (hklein@gnus.ai)
 */
#ifndef _TRANSACTION_VALIDATOR_HPP_
#define _TRANSACTION_VALIDATOR_HPP_

#include <nil/crypto3/algebra/curves/pallas.hpp>
#include <nil/crypto3/algebra/random_element.hpp>
#include <cstdint>
#include <array>

static constexpr std::size_t MAX_RANGES = 4;

using namespace nil::crypto3::algebra::curves;


/**
 * @brief       Generates a point from the seed, TOTP and generator 
 * @param[in]   seed The seed to be used
 * @param[in]   provided_totp The TOTP to be used
 * @param[in]   generator The generator point to be used
 * @return      A point that represents the mapping of TOTP and seed combined
 */
typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type
GeneratePointFromSeedAndTotp( pallas::scalar_field_type::value_type                                                             seed,          //
                              pallas::scalar_field_type::value_type                                                             provided_totp, //
                              typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type generator      //
);

/**
 * @brief       Validates the transaction values
 * @param[in]   balance The raw balance in integer form
 * @param[in]   amount The raw amount in integer form
 * @param[in]   balance_scalar The raw balance in scalar form
 * @param[in]   amount_scalar The raw amount in scalar form
 * @param[in]   balance_commitment The balance multiplied by a generator (mapped to a curve)
 * @param[in]   amount_commitment The amount multiplied by a generator (mapped to a curve)
 * @param[in]   expected_new_balance_commitment  The new balance multiplied by a generator (mapped to a curve)
 * @param[in]   generator  The generator that is used to map values to the curve
 * @param[in]   ranges Array of possible ranges of the amount
 * @return      True if transaction values are valid, false otherwise
 */
bool ValidateTransactionValues(
    uint64_t                                                                                          balance,                         //
    uint64_t                                                                                          amount,                          //
    pallas::scalar_field_type::value_type                                                             balance_scalar,                  //
    pallas::scalar_field_type::value_type                                                             amount_scalar,                   //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type balance_commitment,              //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type amount_commitment,               //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type expected_new_balance_commitment, //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type generator,                       //
    std::array<pallas::scalar_field_type::value_type, MAX_RANGES>                                     ranges                           //
);

#endif //_TRANSACTION_VALIDATOR_HPP_
