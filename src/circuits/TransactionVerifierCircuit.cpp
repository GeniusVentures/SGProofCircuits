
#include "TransactionVerifierCircuit.hpp"

using namespace nil::crypto3::algebra::curves;

[[circuit]] bool ValidateTransaction(
    [[private_input]] uint64_t                                                                        balance,                         //
    [[private_input]] uint64_t                                                                        amount,                          //
    [[private_input]] pallas::scalar_field_type::value_type                                           balance_scalar,                  //
    [[private_input]] pallas::scalar_field_type::value_type                                           amount_scalar,                   //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type balance_commitment,              //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type amount_commitment,               //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type expected_new_balance_commitment, //
    typename pallas::template g1_type<nil::crypto3::algebra::curves::coordinates::affine>::value_type generator,                       //
    std::array<pallas::scalar_field_type::value_type, MAX_RANGES>                                     ranges )
{
    return ValidateTransactionValues( balance, amount, balance_scalar, amount_scalar, balance_commitment, amount_commitment,
                                      expected_new_balance_commitment, generator, ranges );
}
