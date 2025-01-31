/**
 * @file       TransactionVerifierCircuitTOTP.cpp
 * @brief      Source file of the circuit that validate the transaction as well as TOTP
 * @date       2025-01-30
 * @author     Henrique A. Klein (hklein@gnus.ai)
 */
#include "TransactionVerifierCircuitTOTP.hpp"

using namespace nil::crypto3::algebra::curves;

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
    [[private_input]] pallas::scalar_field_type::value_type                                           provided_totp )
{

    bool ret = false;
    // Only perform TOTP validation if base_seed is not zero
    if ( base_seed != 0 )
    {
        // Generate elliptic curve point from seed and provided TOTP
        auto generated_point = GeneratePointFromSeedAndTotp( base_seed, provided_totp, generator );

        // Validate if generated point corresponds to some valid criteria
        ret = ( generated_point == ( base_seed * generator + ( provided_totp * generator ) ) ); // Example check
    }

    if ( ret )
    {
        ret = ValidateTransactionValues( balance, amount, balance_scalar, amount_scalar, balance_commitment, amount_commitment,
                                      expected_new_balance_commitment, generator, ranges );
    }

    return ret;
}
