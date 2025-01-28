/**
 * @file       RecursiveTransactionCircuit.cpp
 * @brief      Automatically generated circuit with the TransactionVerifierCircuit as an input
 * @date       2025-01-28
 * @author     Henrique A. Klein (hklein@gnus.ai)
 * @note       This file was generated using a combo of assigner + recursive_gen tools from zkLLVM
 */

#include <nil/crypto3/hash/algorithm/hash.hpp>
#include <nil/crypto3/hash/poseidon.hpp>
#include <nil/crypto3/algebra/curves/pallas.hpp>

using namespace nil::crypto3;
using namespace nil::crypto3::algebra::curves;

const size_t                                       witness_amount         = 15;
const size_t                                       public_input_amount    = 1;
const size_t                                       constant_amount        = 35;
const size_t                                       selector_amount        = 56;
const std::array<std::size_t, public_input_amount> public_input_sizes     = { 50 };
const std::size_t                                  full_public_input_size = 50;

namespace placeholder_verifier
{

    const bool                              use_lookups                        = false;
    const size_t                            batches_num                        = 4;
    const size_t                            commitments_num                    = 3;
    const size_t                            points_num                         = 328;
    const size_t                            poly_num                           = 166;
    const size_t                            initial_proof_points_num           = 332;
    const size_t                            round_proof_points_num             = 18;
    const size_t                            fri_roots_num                      = 9;
    const size_t                            initial_merkle_proofs_num          = 36;
    const size_t                            initial_merkle_proofs_position_num = 11;
    const size_t                            initial_merkle_proofs_hash_num     = 44;
    const size_t                            round_merkle_proofs_position_num   = 63;
    const size_t                            round_merkle_proofs_hash_num       = 63;
    const size_t                            final_polynomial_size              = 2;
    const size_t                            lambda                             = 9;
    const size_t                            rows_amount                        = 1024;
    const size_t                            rows_log                           = 10;
    const size_t                            total_columns                      = 107;
    const size_t                            sorted_columns                     = 0;
    const size_t                            permutation_size                   = 18;
    const std::array<size_t, total_columns> zero_indices                       = {
        261, 264, 267, 270, 273, 276, 279, 282, 285, 288, 291, 294, 297, 300, 303, 305, 78,  80,  82,  84,  86,  88,  90,  92,  94,  96,  98,
        100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152,
        154, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 184, 186, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206,
        208, 210, 212, 214, 216, 218, 220, 222, 224, 226, 228, 230, 232, 234, 236, 238, 240, 242, 244, 246, 248, 250, 252, 254, 256, 258 };
    const size_t                                    table_values_num          = 228;
    const size_t                                    gates_amount              = 7;
    constexpr std::array<std::size_t, gates_amount> gates_selector_indices    = { 0, 1, 2, 3, 4, 5, 6 };
    const size_t                                    constraints_amount        = 77;
    const size_t                                    quotient_polys_start      = 308;
    const size_t                                    quotient_polys_amount     = 20;
    const size_t                                    lookup_sorted_polys_start = 328;
    const size_t                                    D0_size                   = 4096;
    const size_t                                    D0_log                    = 12;
    const pallas::base_field_type::value_type       D0_omega =
        pallas::base_field_type::value_type( 0x291917312f33e5239161008fab331deeb7292c5c6cf6e088c29b8d7491fcb2a4_cppui255 );
    const pallas::base_field_type::value_type omega =
        pallas::base_field_type::value_type( 0x2ebbfd0093d6cb763b4ade66b66e653bd9786c8a7b47604b73e211ee3dd8df75_cppui255 );
    const size_t                               fri_rounds          = 9;
    const std::array<int, gates_amount>        gates_sizes         = { 21, 34, 3, 12, 3, 3, 1 };
    const size_t                               unique_points       = 4;
    const size_t                               singles_amount      = 4;
    const std::array<std::size_t, batches_num> batches_amount_list = { 129, 16, 1, 20 };

    struct placeholder_proof_type
    {
        std::array<pallas::base_field_type::value_type, commitments_num>                                    commitments;
        pallas::base_field_type::value_type                                                                 challenge;
        std::array<pallas::base_field_type::value_type, points_num>                                         z;
        std::array<pallas::base_field_type::value_type, fri_roots_num>                                      fri_roots;
        std::array<std::array<pallas::base_field_type::value_type, initial_proof_points_num>, lambda>       initial_proof_values;
        std::array<std::array<pallas::base_field_type::value_type, round_proof_points_num>, lambda>         round_proof_values; // lambda times
        std::array<std::array<int, initial_merkle_proofs_position_num>, lambda>                             initial_proof_positions;
        std::array<std::array<pallas::base_field_type::value_type, initial_merkle_proofs_hash_num>, lambda> initial_proof_hashes;
        std::array<std::array<int, round_merkle_proofs_position_num>, lambda> round_merkle_proof_positions;                   // lambda times
        std::array<std::array<pallas::base_field_type::value_type, round_merkle_proofs_hash_num>, lambda> round_proof_hashes; // lambda times
        std::array<pallas::base_field_type::value_type, final_polynomial_size>                            final_polynomial;
    };

    struct placeholder_challenges_type
    {
        pallas::base_field_type::value_type                            eta;
        pallas::base_field_type::value_type                            perm_beta;
        pallas::base_field_type::value_type                            perm_gamma;
        pallas::base_field_type::value_type                            lookup_theta;
        pallas::base_field_type::value_type                            lookup_gamma;
        pallas::base_field_type::value_type                            lookup_beta;
        std::array<pallas::base_field_type::value_type, 1>             lookup_alphas;
        pallas::base_field_type::value_type                            gate_theta;
        std::array<pallas::base_field_type::value_type, 8>             alphas;
        std::array<pallas::base_field_type::value_type, fri_roots_num> fri_alphas;
        std::array<pallas::base_field_type::value_type, lambda>        fri_x_indices;
        pallas::base_field_type::value_type                            lpc_theta;
        pallas::base_field_type::value_type                            xi;
    };

    typedef __attribute__( ( ext_vector_type( 2 ) ) ) typename pallas::base_field_type::value_type permutation_argument_thetas_type;
    typedef __attribute__( ( ext_vector_type( 3 ) ) ) typename pallas::base_field_type::value_type permutation_argument_output_type;

    struct placeholder_permutation_argument_input_type
    {
        std::array<typename pallas::base_field_type::value_type, permutation_size> xi_values;
        std::array<typename pallas::base_field_type::value_type, permutation_size> id_perm;
        std::array<typename pallas::base_field_type::value_type, permutation_size> sigma_perm;
        permutation_argument_thetas_type                                           thetas;
    };

    struct transcript_state_type
    {
        std::array<pallas::base_field_type::value_type, 3> state;
        std::size_t                                        cur;
    };

    void transcript( transcript_state_type &tr_state, pallas::base_field_type::value_type value )
    {
        if ( tr_state.cur == 3 )
        {
            tr_state.state[0] = __builtin_assigner_poseidon_pallas_base( { tr_state.state[0], tr_state.state[1], tr_state.state[2] } )[2];
            tr_state.state[1] = pallas::base_field_type::value_type( 0 );
            tr_state.state[2] = pallas::base_field_type::value_type( 0 );
            tr_state.cur      = 1;
        }
        tr_state.state[tr_state.cur] = value;
        tr_state.cur++;
    }

    pallas::base_field_type::value_type transcript_challenge( transcript_state_type &tr_state )
    {
        tr_state.state[0] = __builtin_assigner_poseidon_pallas_base( { tr_state.state[0], tr_state.state[1], tr_state.state[2] } )[2];
        tr_state.state[1] = pallas::base_field_type::value_type( 0 );
        tr_state.state[2] = pallas::base_field_type::value_type( 0 );
        tr_state.cur      = 1;
        return tr_state.state[0];
    }

    pallas::base_field_type::value_type pow_rows_amount( pallas::base_field_type::value_type x )
    {
        pallas::base_field_type::value_type result = x;
        for ( std::size_t i = 0; i < rows_log; i++ )
        {
            result = result * result;
        }
        return result;
    }

    pallas::base_field_type::value_type pow2( pallas::base_field_type::value_type x )
    {
        return x * x;
    }

    pallas::base_field_type::value_type pow3( pallas::base_field_type::value_type x )
    {
        return x * x * x;
    }

    pallas::base_field_type::value_type pow4( pallas::base_field_type::value_type x )
    {
        pallas::base_field_type::value_type result = x * x;
        result                                     = result * result;
        return result;
    }

    pallas::base_field_type::value_type pow5( pallas::base_field_type::value_type x )
    {
        pallas::base_field_type::value_type result = x * x;
        result                                     = result * result;
        return result * x;
    }

    pallas::base_field_type::value_type pow6( pallas::base_field_type::value_type x )
    {
        pallas::base_field_type::value_type result = x * x * x;
        result                                     = result * result;
        return result;
    }

    pallas::base_field_type::value_type pow7( pallas::base_field_type::value_type x )
    {
        pallas::base_field_type::value_type result = x * x * x;
        result                                     = result * result;
        return result * x;
    }

    pallas::base_field_type::value_type pow8( pallas::base_field_type::value_type x )
    {
        pallas::base_field_type::value_type result = x * x;
        result                                     = result * result;
        return result * result;
    }

    pallas::base_field_type::value_type pow9( pallas::base_field_type::value_type x )
    {
        pallas::base_field_type::value_type result = x;
        result                                     = result * result;
        result                                     = result * result;
        result                                     = result * result;
        result                                     = result * x;
        return result;
    }

    template <std::size_t p>
    pallas::base_field_type::value_type pow( pallas::base_field_type::value_type x )
    {
        if constexpr ( p == 0 )
            return pallas::base_field_type::value_type( 1 );
        if constexpr ( p == 1 )
            return x;
        pallas::base_field_type::value_type result = pow<p / 2>( x );
        result                                     = result * result;
        if constexpr ( p % 2 == 1 )
            result = result * x;
        return result;
    }

    std::array<pallas::base_field_type::value_type, singles_amount> fill_singles( pallas::base_field_type::value_type xi,
                                                                                  pallas::base_field_type::value_type eta )
    {
        std::array<pallas::base_field_type::value_type, singles_amount> singles;
        singles[1] = eta;
        singles[0] = xi;
        singles[2] = xi * omega;
        singles[3] = xi / omega;
        ;
        return singles;
    }

    placeholder_challenges_type generate_challenges( const std::array<pallas::base_field_type::value_type, 2> &vk,
                                                     const placeholder_proof_type                             &proof )
    {
        placeholder_challenges_type challenges;

        transcript_state_type tr_state;
        tr_state.state[0] = pallas::base_field_type::value_type( 0 );
        tr_state.state[1] = pallas::base_field_type::value_type( 0 );
        tr_state.state[2] = pallas::base_field_type::value_type( 0 );
        tr_state.cur      = 1;

        transcript( tr_state, vk[0] );
        transcript( tr_state, vk[1] );

        // LPC additional point
        challenges.eta = transcript_challenge( tr_state );
        transcript( tr_state, proof.commitments[0] );

        challenges.perm_beta  = transcript_challenge( tr_state );
        challenges.perm_gamma = transcript_challenge( tr_state );

        // Call lookup argument
        if ( use_lookups )
        {
            challenges.lookup_theta = transcript_challenge( tr_state );
            transcript( tr_state, proof.commitments[3] );
            challenges.lookup_beta  = transcript_challenge( tr_state );
            challenges.lookup_gamma = transcript_challenge( tr_state );

            for ( std::size_t i = 0; i < sorted_columns - 1; i++ )
            {
                challenges.lookup_alphas[i] = transcript_challenge( tr_state );
            }
        }

        // Call gate argument
        transcript( tr_state, proof.commitments[1] );
        challenges.gate_theta = transcript_challenge( tr_state );

        for ( std::size_t i = 0; i < 8; i++ )
        {
            challenges.alphas[i] = transcript_challenge( tr_state );
        }
        transcript( tr_state, proof.commitments[2] );

        challenges.xi = transcript_challenge( tr_state );

        transcript( tr_state, vk[1] );
        for ( std::size_t i = 0; i < commitments_num; i++ )
        {
            transcript( tr_state, proof.commitments[i] );
        }

        challenges.lpc_theta = transcript_challenge( tr_state );

        for ( std::size_t i = 0; i < fri_roots_num; i++ )
        {
            transcript( tr_state, proof.fri_roots[i] );
            challenges.fri_alphas[i] = transcript_challenge( tr_state );
        }

        for ( std::size_t i = 0; i < lambda; i++ )
        {
            challenges.fri_x_indices[i] = transcript_challenge( tr_state );
        }

        return challenges;
    }

    std::pair<pallas::base_field_type::value_type, pallas::base_field_type::value_type> xi_polys( pallas::base_field_type::value_type xi )
    {
        pallas::base_field_type::value_type xi_n = pow_rows_amount( xi ) - pallas::base_field_type::value_type( 1 );
        pallas::base_field_type::value_type l0 =
            ( xi - pallas::base_field_type::value_type( 1 ) ) * pallas::base_field_type::value_type( rows_amount );
        l0 = xi_n / l0;
        return std::make_pair( l0, xi_n );
    }

    std::array<pallas::base_field_type::value_type, constraints_amount>
    calculate_constraints( std::array<pallas::base_field_type::value_type, points_num> z )
    {
        std::array<pallas::base_field_type::value_type, constraints_amount> constraints;
        constraints[0] =
            ( z[268] * ( pallas::base_field_type::value_type( 0x0_cppui255 ) - ( z[268] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) );
        constraints[1] =
            ( z[271] * ( pallas::base_field_type::value_type( 0x0_cppui255 ) - ( z[271] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) );
        constraints[2] =
            ( z[274] * ( pallas::base_field_type::value_type( 0x0_cppui255 ) - ( z[274] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) );
        constraints[3] =
            ( z[277] * ( pallas::base_field_type::value_type( 0x0_cppui255 ) - ( z[277] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) );
        constraints[4] =
            ( z[280] * ( pallas::base_field_type::value_type( 0x0_cppui255 ) - ( z[280] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) );
        constraints[5] =
            ( ( ( z[267] - z[261] ) * z[283] ) -
              ( z[270] - ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[268] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                           z[264] ) ) );
        constraints[6] =
            ( ( ( z[282] - z[261] ) * z[286] ) -
              ( z[285] - ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[271] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                           z[264] ) ) );
        constraints[7] =
            ( ( ( z[288] - z[261] ) * z[289] ) -
              ( z[291] - ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[274] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                           z[264] ) ) );
        constraints[8] =
            ( ( ( z[294] - z[261] ) * z[292] ) -
              ( z[297] - ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[277] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                           z[264] ) ) );
        constraints[9] =
            ( ( ( z[300] - z[261] ) * z[295] ) -
              ( z[303] - ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[280] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                           z[264] ) ) );
        constraints[10] = ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[270] -
                                ( z[283] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[267] - pow2( z[283] ) ) + z[261] ) ) ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[270] -
                                ( z[283] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[267] - pow2( z[283] ) ) + z[261] ) ) ) ) -
                            ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[267] - pow2( z[283] ) ) + z[261] ) *
                                ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[267] - pow2( z[283] ) ) + z[261] ) ) *
                              ( ( z[282] - z[261] ) + pow2( z[283] ) ) ) );
        constraints[11] = ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[285] -
                                ( z[286] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[282] - pow2( z[286] ) ) + z[261] ) ) ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[285] -
                                ( z[286] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[282] - pow2( z[286] ) ) + z[261] ) ) ) ) -
                            ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[282] - pow2( z[286] ) ) + z[261] ) *
                                ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[282] - pow2( z[286] ) ) + z[261] ) ) *
                              ( ( z[288] - z[261] ) + pow2( z[286] ) ) ) );
        constraints[12] = ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[291] -
                                ( z[289] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[288] - pow2( z[289] ) ) + z[261] ) ) ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[291] -
                                ( z[289] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[288] - pow2( z[289] ) ) + z[261] ) ) ) ) -
                            ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[288] - pow2( z[289] ) ) + z[261] ) *
                                ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[288] - pow2( z[289] ) ) + z[261] ) ) *
                              ( ( z[294] - z[261] ) + pow2( z[289] ) ) ) );
        constraints[13] = ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[297] -
                                ( z[292] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[294] - pow2( z[292] ) ) + z[261] ) ) ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[297] -
                                ( z[292] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[294] - pow2( z[292] ) ) + z[261] ) ) ) ) -
                            ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[294] - pow2( z[292] ) ) + z[261] ) *
                                ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[294] - pow2( z[292] ) ) + z[261] ) ) *
                              ( ( z[300] - z[261] ) + pow2( z[292] ) ) ) );
        constraints[14] = ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[303] -
                                ( z[295] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[300] - pow2( z[295] ) ) + z[261] ) ) ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[303] -
                                ( z[295] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[300] - pow2( z[295] ) ) + z[261] ) ) ) ) -
                            ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[300] - pow2( z[295] ) ) + z[261] ) *
                                ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[300] - pow2( z[295] ) ) + z[261] ) ) *
                              ( ( z[262] - z[261] ) + pow2( z[295] ) ) ) );
        constraints[15] = ( ( ( z[285] + z[270] ) * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[267] - pow2( z[283] ) ) + z[261] ) ) -
                            ( ( z[267] - z[282] ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[270] -
                                ( z[283] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[267] - pow2( z[283] ) ) + z[261] ) ) ) ) );
        constraints[16] = ( ( ( z[291] + z[285] ) * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[282] - pow2( z[286] ) ) + z[261] ) ) -
                            ( ( z[282] - z[288] ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[285] -
                                ( z[286] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[282] - pow2( z[286] ) ) + z[261] ) ) ) ) );
        constraints[17] = ( ( ( z[297] + z[291] ) * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[288] - pow2( z[289] ) ) + z[261] ) ) -
                            ( ( z[288] - z[294] ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[291] -
                                ( z[289] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[288] - pow2( z[289] ) ) + z[261] ) ) ) ) );
        constraints[18] = ( ( ( z[303] + z[297] ) * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[294] - pow2( z[292] ) ) + z[261] ) ) -
                            ( ( z[294] - z[300] ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[297] -
                                ( z[292] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[294] - pow2( z[292] ) ) + z[261] ) ) ) ) );
        constraints[19] = ( ( ( z[265] + z[303] ) * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[300] - pow2( z[295] ) ) + z[261] ) ) -
                            ( ( z[300] - z[262] ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[303] -
                                ( z[295] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[300] - pow2( z[295] ) ) + z[261] ) ) ) ) );
        constraints[20] = ( z[276] - ( ( ( ( ( pallas::base_field_type::value_type( 0x20_cppui255 ) * z[273] +
                                               pallas::base_field_type::value_type( 0x10_cppui255 ) * z[268] ) +
                                             pallas::base_field_type::value_type( 0x8_cppui255 ) * z[271] ) +
                                           pallas::base_field_type::value_type( 0x4_cppui255 ) * z[274] ) +
                                         pallas::base_field_type::value_type( 0x2_cppui255 ) * z[277] ) +
                                       z[280] ) );
        constraints[21] =
            ( z[267] * ( pallas::base_field_type::value_type( 0x0_cppui255 ) - ( z[267] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) );
        constraints[22] =
            ( z[270] * ( pallas::base_field_type::value_type( 0x0_cppui255 ) - ( z[270] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) );
        constraints[23] =
            ( z[273] * ( pallas::base_field_type::value_type( 0x0_cppui255 ) - ( z[273] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) );
        constraints[24] =
            ( z[276] * ( pallas::base_field_type::value_type( 0x0_cppui255 ) - ( z[276] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) );
        constraints[25] =
            ( z[279] * ( pallas::base_field_type::value_type( 0x0_cppui255 ) - ( z[279] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) );
        constraints[26] =
            ( ( ( z[266] - z[260] ) * z[282] ) -
              ( z[269] - ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[267] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                           z[263] ) ) );
        constraints[27] =
            ( ( ( z[281] - z[260] ) * z[285] ) -
              ( z[284] - ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[270] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                           z[263] ) ) );
        constraints[28] =
            ( ( ( z[287] - z[260] ) * z[288] ) -
              ( z[290] - ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[273] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                           z[263] ) ) );
        constraints[29] =
            ( ( ( z[293] - z[260] ) * z[291] ) -
              ( z[296] - ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[276] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                           z[263] ) ) );
        constraints[30] =
            ( ( ( z[299] - z[260] ) * z[294] ) -
              ( z[302] - ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[279] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                           z[263] ) ) );
        constraints[31] = ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[269] -
                                ( z[282] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[266] - pow2( z[282] ) ) + z[260] ) ) ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[269] -
                                ( z[282] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[266] - pow2( z[282] ) ) + z[260] ) ) ) ) -
                            ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[266] - pow2( z[282] ) ) + z[260] ) *
                                ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[266] - pow2( z[282] ) ) + z[260] ) ) *
                              ( ( z[281] - z[260] ) + pow2( z[282] ) ) ) );
        constraints[32] = ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[284] -
                                ( z[285] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[281] - pow2( z[285] ) ) + z[260] ) ) ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[284] -
                                ( z[285] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[281] - pow2( z[285] ) ) + z[260] ) ) ) ) -
                            ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[281] - pow2( z[285] ) ) + z[260] ) *
                                ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[281] - pow2( z[285] ) ) + z[260] ) ) *
                              ( ( z[287] - z[260] ) + pow2( z[285] ) ) ) );
        constraints[33] = ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[290] -
                                ( z[288] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[287] - pow2( z[288] ) ) + z[260] ) ) ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[290] -
                                ( z[288] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[287] - pow2( z[288] ) ) + z[260] ) ) ) ) -
                            ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[287] - pow2( z[288] ) ) + z[260] ) *
                                ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[287] - pow2( z[288] ) ) + z[260] ) ) *
                              ( ( z[293] - z[260] ) + pow2( z[288] ) ) ) );
        constraints[34] = ( ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[296] -
                                    ( z[291] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[293] - pow2( z[291] ) ) + z[260] ) ) ) *
                                  ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[296] -
                                    ( z[291] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[293] - pow2( z[291] ) ) + z[260] ) ) ) ) -
                                ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[293] - pow2( z[291] ) ) + z[260] ) *
                                    ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[293] - pow2( z[291] ) ) + z[260] ) ) *
                                  ( ( z[299] - z[260] ) + pow2( z[291] ) ) ) ) *
                              z[286] ) *
                            z[268] );
        constraints[35] = ( ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[302] -
                                    ( z[294] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[299] - pow2( z[294] ) ) + z[260] ) ) ) *
                                  ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[302] -
                                    ( z[294] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[299] - pow2( z[294] ) ) + z[260] ) ) ) ) -
                                ( ( ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[299] - pow2( z[294] ) ) + z[260] ) *
                                    ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[299] - pow2( z[294] ) ) + z[260] ) ) *
                                  ( ( z[261] - z[260] ) + pow2( z[294] ) ) ) ) *
                              z[286] ) *
                            z[268] );
        constraints[36] = ( ( ( z[284] + z[269] ) * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[266] - pow2( z[282] ) ) + z[260] ) ) -
                            ( ( z[266] - z[281] ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[269] -
                                ( z[282] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[266] - pow2( z[282] ) ) + z[260] ) ) ) ) );
        constraints[37] = ( ( ( z[290] + z[284] ) * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[281] - pow2( z[285] ) ) + z[260] ) ) -
                            ( ( z[281] - z[287] ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[284] -
                                ( z[285] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[281] - pow2( z[285] ) ) + z[260] ) ) ) ) );
        constraints[38] = ( ( ( z[296] + z[290] ) * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[287] - pow2( z[288] ) ) + z[260] ) ) -
                            ( ( z[287] - z[293] ) *
                              ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[290] -
                                ( z[288] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[287] - pow2( z[288] ) ) + z[260] ) ) ) ) );
        constraints[39] =
            ( ( ( ( ( z[302] + z[296] ) * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[293] - pow2( z[291] ) ) + z[260] ) ) -
                  ( ( z[293] - z[299] ) *
                    ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[296] -
                      ( z[291] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[293] - pow2( z[291] ) ) + z[260] ) ) ) ) ) *
                z[286] ) *
              z[268] );
        constraints[40] =
            ( ( ( ( ( z[264] + z[302] ) * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[299] - pow2( z[294] ) ) + z[260] ) ) -
                  ( ( z[299] - z[261] ) *
                    ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[302] -
                      ( z[294] * ( ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[299] - pow2( z[294] ) ) + z[260] ) ) ) ) ) *
                z[286] ) *
              z[268] );
        constraints[41] = ( z[275] - ( ( ( ( ( pallas::base_field_type::value_type( 0x20_cppui255 ) * z[272] +
                                               pallas::base_field_type::value_type( 0x10_cppui255 ) * z[267] ) +
                                             pallas::base_field_type::value_type( 0x8_cppui255 ) * z[270] ) +
                                           pallas::base_field_type::value_type( 0x4_cppui255 ) * z[273] ) +
                                         pallas::base_field_type::value_type( 0x2_cppui255 ) * z[276] ) +
                                       z[279] ) );
        constraints[42] = ( ( z[286] * z[268] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) * z[286] );
        constraints[43] = ( ( ( ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000000_cppui255 ) ) * z[271] ) -
                              pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                            ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000000_cppui255 ) ) );
        constraints[44] = ( ( ( ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000001_cppui255 ) ) * z[274] ) -
                              pallas::base_field_type::value_type( 0x1_cppui255 ) ) *
                            ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000001_cppui255 ) ) );
        constraints[45] = ( ( z[286] * z[268] * z[261] +
                              ( ( ( ( ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000000_cppui255 ) ) * z[271] ) -
                                    ( ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000001_cppui255 ) ) * z[274] ) ) *
                                  ( ( ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000000_cppui255 ) ) * z[271] ) -
                                    ( ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000001_cppui255 ) ) * z[274] ) ) ) *
                                z[280] ) ) -
                            z[262] );
        constraints[46] = ( ( z[286] * z[268] * z[264] +
                              ( ( ( ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000000_cppui255 ) ) * z[271] ) -
                                  ( ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000001_cppui255 ) ) * z[274] ) ) *
                                z[283] ) ) -
                            z[265] );
        constraints[47] =
            ( z[286] -
              ( ( ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000000_cppui255 ) ) *
                  ( z[277] - pallas::base_field_type::value_type( 0x200000000000000000000000000000003369e57a0e5efd4c526a60b180000001_cppui255 ) ) ) *
                ( z[277] - pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000001_cppui255 ) ) ) );
        constraints[48] = ( ( ( ( ( ( ( z[297] * ( z[297] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) *
                                      ( z[297] - pallas::base_field_type::value_type( 0x2_cppui255 ) ) ) *
                                    ( z[297] - pallas::base_field_type::value_type( 0x3_cppui255 ) ) ) *
                                  ( z[297] - pallas::base_field_type::value_type( 0x4_cppui255 ) ) ) *
                                ( z[297] - pallas::base_field_type::value_type( 0x5_cppui255 ) ) ) *
                              ( z[297] - pallas::base_field_type::value_type( 0x6_cppui255 ) ) ) *
                            ( z[297] - pallas::base_field_type::value_type( 0x7_cppui255 ) ) );
        constraints[49] = ( z[300] * ( z[300] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) );
        constraints[50] = ( ( ( z[303] - pallas::base_field_type::value_type( 0x10_cppui255 ) * z[278] ) -
                              pallas::base_field_type::value_type( 0x2_cppui255 ) * z[297] ) -
                            z[300] );
        constraints[51] = ( z[289] * ( z[303] - z[298] ) );
        constraints[52] = ( z[289] * ( z[292] - pallas::base_field_type::value_type( 0x10000000000000000000000000000000_cppui255 ) ) );
        constraints[53] = ( ( ( z[298] - z[295] ) + pallas::base_field_type::value_type( 0x224698fc0994a8dd8c46eb2100000001_cppui255 ) ) -
                            pallas::base_field_type::value_type( 0x400000000000000000000000000000000_cppui255 ) );
        constraints[54] =
            ( ( z[275] - z[295] ) -
              pallas::base_field_type::value_type( 0x4000000000000000000000000000000000000000000000000000000000000000_cppui255 ) * z[289] );
        constraints[55] = ( ( ( ( ( ( ( z[298] * ( z[298] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) *
                                      ( z[298] - pallas::base_field_type::value_type( 0x2_cppui255 ) ) ) *
                                    ( z[298] - pallas::base_field_type::value_type( 0x3_cppui255 ) ) ) *
                                  ( z[298] - pallas::base_field_type::value_type( 0x4_cppui255 ) ) ) *
                                ( z[298] - pallas::base_field_type::value_type( 0x5_cppui255 ) ) ) *
                              ( z[298] - pallas::base_field_type::value_type( 0x6_cppui255 ) ) ) *
                            ( z[298] - pallas::base_field_type::value_type( 0x7_cppui255 ) ) );
        constraints[56] = ( ( ( ( ( ( ( z[301] * ( z[301] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) ) *
                                      ( z[301] - pallas::base_field_type::value_type( 0x2_cppui255 ) ) ) *
                                    ( z[301] - pallas::base_field_type::value_type( 0x3_cppui255 ) ) ) *
                                  ( z[301] - pallas::base_field_type::value_type( 0x4_cppui255 ) ) ) *
                                ( z[301] - pallas::base_field_type::value_type( 0x5_cppui255 ) ) ) *
                              ( z[301] - pallas::base_field_type::value_type( 0x6_cppui255 ) ) ) *
                            ( z[301] - pallas::base_field_type::value_type( 0x7_cppui255 ) ) );
        constraints[57] = ( ( ( z[304] - pallas::base_field_type::value_type( 0x40_cppui255 ) * z[279] ) -
                              pallas::base_field_type::value_type( 0x8_cppui255 ) * z[298] ) -
                            z[301] );
        constraints[58] = ( ( z[267] - z[261] ) * ( ( ( z[267] - z[261] ) * z[291] ) - ( z[270] - z[264] ) ) );
        constraints[59] = ( ( pallas::base_field_type::value_type( 0x1_cppui255 ) - ( ( z[267] - z[261] ) * z[285] ) ) *
                            ( pallas::base_field_type::value_type( 0x2_cppui255 ) * z[264] * z[291] -
                              pallas::base_field_type::value_type( 0x3_cppui255 ) * z[261] * z[261] ) );
        constraints[60] = ( ( z[261] * z[267] * z[267] - z[261] * z[267] * z[261] ) * ( ( ( z[291] * z[291] - z[261] ) - z[267] ) - z[273] ) );
        constraints[61] = ( ( z[261] * z[267] * z[267] - z[261] * z[267] * z[261] ) * ( ( ( z[291] * ( z[261] - z[273] ) ) - z[264] ) - z[276] ) );
        constraints[62] = ( ( z[261] * z[267] * z[270] + z[261] * z[267] * z[264] ) * ( ( ( z[291] * z[291] - z[261] ) - z[267] ) - z[273] ) );
        constraints[63] = ( ( z[261] * z[267] * z[270] + z[261] * z[267] * z[264] ) * ( ( ( z[291] * ( z[261] - z[273] ) ) - z[264] ) - z[276] ) );
        constraints[64] = ( ( pallas::base_field_type::value_type( 0x1_cppui255 ) - z[261] * z[279] ) * ( z[273] - z[267] ) );
        constraints[65] = ( ( pallas::base_field_type::value_type( 0x1_cppui255 ) - z[261] * z[279] ) * ( z[276] - z[270] ) );
        constraints[66] = ( ( pallas::base_field_type::value_type( 0x1_cppui255 ) - z[267] * z[282] ) * ( z[273] - z[261] ) );
        constraints[67] = ( ( pallas::base_field_type::value_type( 0x1_cppui255 ) - z[267] * z[282] ) * ( z[276] - z[264] ) );
        constraints[68] =
            ( ( ( pallas::base_field_type::value_type( 0x1_cppui255 ) - ( ( z[267] - z[261] ) * z[285] ) ) - ( ( z[270] + z[264] ) * z[288] ) ) *
              z[273] );
        constraints[69] =
            ( ( ( pallas::base_field_type::value_type( 0x1_cppui255 ) - ( ( z[267] - z[261] ) * z[285] ) ) - ( ( z[270] + z[264] ) * z[288] ) ) *
              z[276] );
        constraints[70] = ( z[270] * ( z[270] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) );
        constraints[71] =
            ( ( ( z[261] - z[264] ) * z[267] ) +
              pallas::base_field_type::value_type( 0x40000000000000000000000000000000224698fc094cf91b992d30ed00000000_cppui255 ) * z[270] );
        constraints[72] = ( ( z[267] - ( z[261] - z[264] ) ) * ( z[270] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) );
        constraints[73] = ( z[270] * ( z[270] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) );
        constraints[74] = ( ( ( z[261] - z[264] ) * z[267] ) + ( z[270] - pallas::base_field_type::value_type( 0x1_cppui255 ) ) );
        constraints[75] = ( ( z[267] - ( z[261] - z[264] ) ) * z[270] );
        constraints[76] = ( z[267] - z[261] * z[264] );

        return constraints;
    }

    typename pallas::base_field_type::value_type
    gate_argument_verifier( std::array<typename pallas::base_field_type::value_type, gates_amount>       selectors,
                            std::array<typename pallas::base_field_type::value_type, constraints_amount> constraints,
                            typename pallas::base_field_type::value_type                                 theta )
    {

        return __builtin_assigner_gate_arg_verifier( selectors.data(), (int *)&gates_sizes, gates_amount, constraints.data(), constraints_amount,
                                                     theta );
    }

    template <std::size_t start_index, std::size_t leaf_size>
    pallas::base_field_type::value_type calculate_leaf_hash( std::array<pallas::base_field_type::value_type, initial_proof_points_num> val,
                                                             bool                                                                      reversed )
    {
        pallas::base_field_type::value_type hash_state = pallas::base_field_type::value_type( 0 );
        for ( std::size_t pos = 0; pos < leaf_size * 2; pos += 2 )
        {
            hash_state = __builtin_assigner_poseidon_pallas_base( { hash_state, reversed ? val[start_index + pos] : val[start_index + pos + 1],
                                                                    reversed ? val[start_index + pos + 1] : val[start_index + pos] } )[2];
        }
        return hash_state;
    }

    struct precomputed_values_type
    {
        pallas::base_field_type::value_type l0;
        pallas::base_field_type::value_type Z_at_xi;
        pallas::base_field_type::value_type F_consolidated;
        pallas::base_field_type::value_type T_consolidated;
    };

    constexpr std::size_t L0_IND             = 0;
    constexpr std::size_t Z_AT_XI_IND        = 1;
    constexpr std::size_t F_CONSOLIDATED_IND = 2;
    constexpr std::size_t T_CONSOLIDATED_IND = 3;

    typedef __attribute__( ( ext_vector_type( 2 ) ) ) typename pallas::base_field_type::value_type pair_type;

    typedef __attribute__( ( ext_vector_type( 4 ) ) ) typename pallas::base_field_type::value_type lookup_output_type;

    typedef __attribute__( ( ext_vector_type( 2 ) ) ) typename pallas::base_field_type::value_type pair_type;

    [[circuit]] bool placeholder_verifier( std::array<pallas::base_field_type::value_type, full_public_input_size> public_input,

                                           std::array<pallas::base_field_type::value_type, 2> vk, placeholder_proof_type proof )
    {
        placeholder_challenges_type challenges = generate_challenges( vk, proof );
        __builtin_assigner_exit_check( challenges.xi == proof.challenge );

        precomputed_values_type precomputed_values;
        std::tie( precomputed_values.l0, precomputed_values.Z_at_xi ) = xi_polys( challenges.xi );

        // For loop in for loop removed
        std::array<pallas::base_field_type::value_type, 50> Omegas = { 1 };
        pallas::base_field_type::value_type                 result( 0 );
        {
            result = pallas::base_field_type::value_type( 0 );
            result += public_input[0] * Omegas[0] / ( challenges.xi - Omegas[0] );
            Omegas[1] = Omegas[0] * omega;
            result += public_input[1] * Omegas[1] / ( challenges.xi - Omegas[1] );
            Omegas[2] = Omegas[1] * omega;
            result += public_input[2] * Omegas[2] / ( challenges.xi - Omegas[2] );
            Omegas[3] = Omegas[2] * omega;
            result += public_input[3] * Omegas[3] / ( challenges.xi - Omegas[3] );
            Omegas[4] = Omegas[3] * omega;
            result += public_input[4] * Omegas[4] / ( challenges.xi - Omegas[4] );
            Omegas[5] = Omegas[4] * omega;
            result += public_input[5] * Omegas[5] / ( challenges.xi - Omegas[5] );
            Omegas[6] = Omegas[5] * omega;
            result += public_input[6] * Omegas[6] / ( challenges.xi - Omegas[6] );
            Omegas[7] = Omegas[6] * omega;
            result += public_input[7] * Omegas[7] / ( challenges.xi - Omegas[7] );
            Omegas[8] = Omegas[7] * omega;
            result += public_input[8] * Omegas[8] / ( challenges.xi - Omegas[8] );
            Omegas[9] = Omegas[8] * omega;
            result += public_input[9] * Omegas[9] / ( challenges.xi - Omegas[9] );
            Omegas[10] = Omegas[9] * omega;
            result += public_input[10] * Omegas[10] / ( challenges.xi - Omegas[10] );
            Omegas[11] = Omegas[10] * omega;
            result += public_input[11] * Omegas[11] / ( challenges.xi - Omegas[11] );
            Omegas[12] = Omegas[11] * omega;
            result += public_input[12] * Omegas[12] / ( challenges.xi - Omegas[12] );
            Omegas[13] = Omegas[12] * omega;
            result += public_input[13] * Omegas[13] / ( challenges.xi - Omegas[13] );
            Omegas[14] = Omegas[13] * omega;
            result += public_input[14] * Omegas[14] / ( challenges.xi - Omegas[14] );
            Omegas[15] = Omegas[14] * omega;
            result += public_input[15] * Omegas[15] / ( challenges.xi - Omegas[15] );
            Omegas[16] = Omegas[15] * omega;
            result += public_input[16] * Omegas[16] / ( challenges.xi - Omegas[16] );
            Omegas[17] = Omegas[16] * omega;
            result += public_input[17] * Omegas[17] / ( challenges.xi - Omegas[17] );
            Omegas[18] = Omegas[17] * omega;
            result += public_input[18] * Omegas[18] / ( challenges.xi - Omegas[18] );
            Omegas[19] = Omegas[18] * omega;
            result += public_input[19] * Omegas[19] / ( challenges.xi - Omegas[19] );
            Omegas[20] = Omegas[19] * omega;
            result += public_input[20] * Omegas[20] / ( challenges.xi - Omegas[20] );
            Omegas[21] = Omegas[20] * omega;
            result += public_input[21] * Omegas[21] / ( challenges.xi - Omegas[21] );
            Omegas[22] = Omegas[21] * omega;
            result += public_input[22] * Omegas[22] / ( challenges.xi - Omegas[22] );
            Omegas[23] = Omegas[22] * omega;
            result += public_input[23] * Omegas[23] / ( challenges.xi - Omegas[23] );
            Omegas[24] = Omegas[23] * omega;
            result += public_input[24] * Omegas[24] / ( challenges.xi - Omegas[24] );
            Omegas[25] = Omegas[24] * omega;
            result += public_input[25] * Omegas[25] / ( challenges.xi - Omegas[25] );
            Omegas[26] = Omegas[25] * omega;
            result += public_input[26] * Omegas[26] / ( challenges.xi - Omegas[26] );
            Omegas[27] = Omegas[26] * omega;
            result += public_input[27] * Omegas[27] / ( challenges.xi - Omegas[27] );
            Omegas[28] = Omegas[27] * omega;
            result += public_input[28] * Omegas[28] / ( challenges.xi - Omegas[28] );
            Omegas[29] = Omegas[28] * omega;
            result += public_input[29] * Omegas[29] / ( challenges.xi - Omegas[29] );
            Omegas[30] = Omegas[29] * omega;
            result += public_input[30] * Omegas[30] / ( challenges.xi - Omegas[30] );
            Omegas[31] = Omegas[30] * omega;
            result += public_input[31] * Omegas[31] / ( challenges.xi - Omegas[31] );
            Omegas[32] = Omegas[31] * omega;
            result += public_input[32] * Omegas[32] / ( challenges.xi - Omegas[32] );
            Omegas[33] = Omegas[32] * omega;
            result += public_input[33] * Omegas[33] / ( challenges.xi - Omegas[33] );
            Omegas[34] = Omegas[33] * omega;
            result += public_input[34] * Omegas[34] / ( challenges.xi - Omegas[34] );
            Omegas[35] = Omegas[34] * omega;
            result += public_input[35] * Omegas[35] / ( challenges.xi - Omegas[35] );
            Omegas[36] = Omegas[35] * omega;
            result += public_input[36] * Omegas[36] / ( challenges.xi - Omegas[36] );
            Omegas[37] = Omegas[36] * omega;
            result += public_input[37] * Omegas[37] / ( challenges.xi - Omegas[37] );
            Omegas[38] = Omegas[37] * omega;
            result += public_input[38] * Omegas[38] / ( challenges.xi - Omegas[38] );
            Omegas[39] = Omegas[38] * omega;
            result += public_input[39] * Omegas[39] / ( challenges.xi - Omegas[39] );
            Omegas[40] = Omegas[39] * omega;
            result += public_input[40] * Omegas[40] / ( challenges.xi - Omegas[40] );
            Omegas[41] = Omegas[40] * omega;
            result += public_input[41] * Omegas[41] / ( challenges.xi - Omegas[41] );
            Omegas[42] = Omegas[41] * omega;
            result += public_input[42] * Omegas[42] / ( challenges.xi - Omegas[42] );
            Omegas[43] = Omegas[42] * omega;
            result += public_input[43] * Omegas[43] / ( challenges.xi - Omegas[43] );
            Omegas[44] = Omegas[43] * omega;
            result += public_input[44] * Omegas[44] / ( challenges.xi - Omegas[44] );
            Omegas[45] = Omegas[44] * omega;
            result += public_input[45] * Omegas[45] / ( challenges.xi - Omegas[45] );
            Omegas[46] = Omegas[45] * omega;
            result += public_input[46] * Omegas[46] / ( challenges.xi - Omegas[46] );
            Omegas[47] = Omegas[46] * omega;
            result += public_input[47] * Omegas[47] / ( challenges.xi - Omegas[47] );
            Omegas[48] = Omegas[47] * omega;
            result += public_input[48] * Omegas[48] / ( challenges.xi - Omegas[48] );
            Omegas[49] = Omegas[48] * omega;
            result += public_input[49] * Omegas[49] / ( challenges.xi - Omegas[49] );
            __builtin_assigner_exit_check( rows_amount * proof.z[zero_indices[witness_amount + 0]] == precomputed_values.Z_at_xi * result );
        }

        std::array<pallas::base_field_type::value_type, 8> F; // = {0,0,0,0,0,0,0,0};

        // Call permutation argument
        placeholder_permutation_argument_input_type perm_arg_input;
        perm_arg_input.thetas[0] = challenges.perm_beta;
        perm_arg_input.thetas[1] = challenges.perm_gamma;

        for ( std::size_t i = 0; i < permutation_size; i++ )
        {
            perm_arg_input.xi_values[i]  = proof.z[zero_indices[i]];
            perm_arg_input.id_perm[i]    = proof.z[2 * i];
            perm_arg_input.sigma_perm[i] = proof.z[2 * permutation_size + 2 * i];
        }

        permutation_argument_output_type permutation_argument = __builtin_assigner_permutation_arg_verifier(
            perm_arg_input.xi_values.data(), perm_arg_input.id_perm.data(), perm_arg_input.sigma_perm.data(), permutation_size, precomputed_values.l0,
            proof.z[4 * permutation_size + 6 + table_values_num],     // V
            proof.z[4 * permutation_size + 6 + table_values_num + 1], // V_shifted
            proof.z[4 * permutation_size],                            // q_last
            proof.z[4 * permutation_size + 3],                        // q_blind
            perm_arg_input.thetas );

        F[0] = permutation_argument[0];
        F[1] = permutation_argument[1];
        F[2] = permutation_argument[2];

        if constexpr ( gates_amount > 0 )
        {
            std::array<pallas::base_field_type::value_type, constraints_amount> constraints;
            std::array<pallas::base_field_type::value_type, gates_amount>       selectors;
            constraints = calculate_constraints( proof.z );

            for ( std::size_t i = 0; i < gates_amount; i++ )
            {
                selectors[i] = proof.z[zero_indices[witness_amount + public_input_amount + constant_amount + gates_selector_indices[i]]];
            }

            F[7] = gate_argument_verifier( selectors, constraints, challenges.gate_theta );
            F[7] *= ( pallas::base_field_type::value_type( 1 ) - proof.z[4 * permutation_size] - proof.z[4 * permutation_size + 3] );
        }

        precomputed_values.F_consolidated = pallas::base_field_type::value_type( 0 );
        for ( std::size_t i = 0; i < 8; i++ )
        {
            F[i] *= challenges.alphas[i];
            precomputed_values.F_consolidated += F[i];
        }

        precomputed_values.T_consolidated          = pallas::base_field_type::value_type( 0 );
        pallas::base_field_type::value_type factor = pallas::base_field_type::value_type( 1 );
        for ( std::size_t i = 0; i < quotient_polys_amount; i++ )
        {
            precomputed_values.T_consolidated += proof.z[quotient_polys_start + i] * factor;
            factor *= ( precomputed_values.Z_at_xi + pallas::base_field_type::value_type( 1 ) );
        }
        __builtin_assigner_exit_check( precomputed_values.F_consolidated == precomputed_values.T_consolidated * precomputed_values.Z_at_xi );

        // Commitment scheme
        std::array<pallas::base_field_type::value_type, singles_amount> singles = fill_singles( challenges.xi, challenges.eta );
        std::array<pallas::base_field_type::value_type, unique_points>  U;

        pallas::base_field_type::value_type theta_acc = pallas::base_field_type::value_type( 1 );

        U[0] += theta_acc * proof.z[0];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[2];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[4];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[6];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[8];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[10];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[12];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[14];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[16];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[18];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[20];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[22];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[24];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[26];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[28];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[30];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[32];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[34];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[36];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[38];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[40];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[42];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[44];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[46];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[48];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[50];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[52];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[54];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[56];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[58];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[60];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[62];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[64];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[66];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[68];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[70];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[72];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[75];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[78];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[80];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[82];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[84];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[86];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[88];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[90];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[92];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[94];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[96];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[98];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[100];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[102];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[104];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[106];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[108];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[110];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[112];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[114];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[116];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[118];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[120];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[122];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[124];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[126];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[128];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[130];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[132];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[134];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[136];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[138];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[140];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[142];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[144];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[146];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[148];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[150];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[152];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[154];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[156];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[158];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[160];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[162];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[164];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[166];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[168];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[170];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[172];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[174];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[176];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[178];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[180];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[182];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[184];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[186];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[188];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[190];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[192];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[194];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[196];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[198];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[200];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[202];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[204];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[206];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[208];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[210];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[212];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[214];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[216];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[218];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[220];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[222];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[224];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[226];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[228];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[230];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[232];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[234];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[236];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[238];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[240];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[242];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[244];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[246];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[248];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[250];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[252];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[254];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[256];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[258];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[261];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[264];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[267];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[270];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[273];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[276];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[279];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[282];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[285];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[288];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[291];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[294];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[297];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[300];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[303];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[305];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[306];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[308];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[309];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[310];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[311];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[312];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[313];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[314];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[315];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[316];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[317];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[318];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[319];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[320];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[321];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[322];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[323];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[324];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[325];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[326];
        theta_acc *= challenges.lpc_theta;
        U[0] += theta_acc * proof.z[327];
        theta_acc *= challenges.lpc_theta;

        U[1] += theta_acc * proof.z[1];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[3];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[5];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[7];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[9];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[11];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[13];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[15];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[17];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[19];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[21];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[23];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[25];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[27];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[29];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[31];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[33];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[35];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[37];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[39];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[41];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[43];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[45];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[47];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[49];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[51];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[53];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[55];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[57];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[59];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[61];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[63];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[65];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[67];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[69];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[71];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[74];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[77];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[79];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[81];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[83];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[85];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[87];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[89];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[91];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[93];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[95];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[97];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[99];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[101];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[103];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[105];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[107];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[109];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[111];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[113];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[115];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[117];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[119];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[121];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[123];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[125];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[127];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[129];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[131];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[133];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[135];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[137];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[139];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[141];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[143];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[145];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[147];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[149];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[151];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[153];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[155];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[157];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[159];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[161];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[163];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[165];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[167];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[169];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[171];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[173];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[175];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[177];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[179];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[181];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[183];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[185];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[187];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[189];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[191];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[193];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[195];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[197];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[199];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[201];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[203];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[205];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[207];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[209];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[211];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[213];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[215];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[217];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[219];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[221];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[223];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[225];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[227];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[229];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[231];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[233];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[235];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[237];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[239];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[241];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[243];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[245];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[247];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[249];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[251];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[253];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[255];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[257];
        theta_acc *= challenges.lpc_theta;
        U[1] += theta_acc * proof.z[259];
        theta_acc *= challenges.lpc_theta;

        U[2] += theta_acc * proof.z[73];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[76];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[262];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[265];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[268];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[271];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[274];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[277];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[280];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[283];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[286];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[289];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[292];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[295];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[298];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[301];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[304];
        theta_acc *= challenges.lpc_theta;
        U[2] += theta_acc * proof.z[307];
        theta_acc *= challenges.lpc_theta;

        U[3] += theta_acc * proof.z[260];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[263];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[266];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[269];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[272];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[275];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[278];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[281];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[284];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[287];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[290];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[293];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[296];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[299];
        theta_acc *= challenges.lpc_theta;
        U[3] += theta_acc * proof.z[302];
        theta_acc *= challenges.lpc_theta;

        std::array<std::array<typename pallas::base_field_type::value_type, 3>, D0_log> res;
        std::size_t                                                                     round_proof_ind        = 0;
        std::size_t                                                                     initial_proof_ind      = 0;
        std::size_t                                                                     initial_proof_hash_ind = 0;
        pallas::base_field_type::value_type                                             interpolant;
        std::size_t                                                                     cur_val              = 0;
        std::size_t                                                                     round_proof_hash_ind = 0;

        for ( std::size_t i = 0; i < lambda; i++ )
        {
            __builtin_assigner_fri_cosets( res.data(), D0_log, D0_omega, challenges.fri_x_indices[i] );
            cur_val = 0;

            pallas::base_field_type::value_type hash_state;
            pallas::base_field_type::value_type pos;
            pallas::base_field_type::value_type npos;
            hash_state = calculate_leaf_hash<0, 129>( proof.initial_proof_values[i], res[0][2] == pallas::base_field_type::value_type( 0 ) );
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][0] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][0], npos * hash_state + pos * proof.initial_proof_hashes[i][0] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][1] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][1], npos * hash_state + pos * proof.initial_proof_hashes[i][1] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][2] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][2], npos * hash_state + pos * proof.initial_proof_hashes[i][2] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][3] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][3], npos * hash_state + pos * proof.initial_proof_hashes[i][3] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][4] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][4], npos * hash_state + pos * proof.initial_proof_hashes[i][4] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][5] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][5], npos * hash_state + pos * proof.initial_proof_hashes[i][5] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][6] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][6], npos * hash_state + pos * proof.initial_proof_hashes[i][6] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][7] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][7], npos * hash_state + pos * proof.initial_proof_hashes[i][7] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][8] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][8], npos * hash_state + pos * proof.initial_proof_hashes[i][8] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][9] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][9], npos * hash_state + pos * proof.initial_proof_hashes[i][9] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][10] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][10], npos * hash_state + pos * proof.initial_proof_hashes[i][10] } )[2];
            __builtin_assigner_exit_check( hash_state == vk[1] );

            hash_state = calculate_leaf_hash<258, 16>( proof.initial_proof_values[i], res[0][2] == pallas::base_field_type::value_type( 0 ) );
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][0] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][11], npos * hash_state + pos * proof.initial_proof_hashes[i][11] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][1] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][12], npos * hash_state + pos * proof.initial_proof_hashes[i][12] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][2] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][13], npos * hash_state + pos * proof.initial_proof_hashes[i][13] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][3] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][14], npos * hash_state + pos * proof.initial_proof_hashes[i][14] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][4] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][15], npos * hash_state + pos * proof.initial_proof_hashes[i][15] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][5] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][16], npos * hash_state + pos * proof.initial_proof_hashes[i][16] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][6] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][17], npos * hash_state + pos * proof.initial_proof_hashes[i][17] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][7] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][18], npos * hash_state + pos * proof.initial_proof_hashes[i][18] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][8] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][19], npos * hash_state + pos * proof.initial_proof_hashes[i][19] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][9] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][20], npos * hash_state + pos * proof.initial_proof_hashes[i][20] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][10] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][21], npos * hash_state + pos * proof.initial_proof_hashes[i][21] } )[2];
            __builtin_assigner_exit_check( hash_state == proof.commitments[0] );

            hash_state = calculate_leaf_hash<290, 1>( proof.initial_proof_values[i], res[0][2] == pallas::base_field_type::value_type( 0 ) );
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][0] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][22], npos * hash_state + pos * proof.initial_proof_hashes[i][22] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][1] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][23], npos * hash_state + pos * proof.initial_proof_hashes[i][23] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][2] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][24], npos * hash_state + pos * proof.initial_proof_hashes[i][24] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][3] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][25], npos * hash_state + pos * proof.initial_proof_hashes[i][25] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][4] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][26], npos * hash_state + pos * proof.initial_proof_hashes[i][26] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][5] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][27], npos * hash_state + pos * proof.initial_proof_hashes[i][27] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][6] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][28], npos * hash_state + pos * proof.initial_proof_hashes[i][28] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][7] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][29], npos * hash_state + pos * proof.initial_proof_hashes[i][29] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][8] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][30], npos * hash_state + pos * proof.initial_proof_hashes[i][30] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][9] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][31], npos * hash_state + pos * proof.initial_proof_hashes[i][31] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][10] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][32], npos * hash_state + pos * proof.initial_proof_hashes[i][32] } )[2];
            __builtin_assigner_exit_check( hash_state == proof.commitments[1] );

            hash_state = calculate_leaf_hash<292, 20>( proof.initial_proof_values[i], res[0][2] == pallas::base_field_type::value_type( 0 ) );
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][0] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][33], npos * hash_state + pos * proof.initial_proof_hashes[i][33] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][1] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][34], npos * hash_state + pos * proof.initial_proof_hashes[i][34] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][2] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][35], npos * hash_state + pos * proof.initial_proof_hashes[i][35] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][3] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][36], npos * hash_state + pos * proof.initial_proof_hashes[i][36] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][4] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][37], npos * hash_state + pos * proof.initial_proof_hashes[i][37] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][5] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][38], npos * hash_state + pos * proof.initial_proof_hashes[i][38] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][6] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][39], npos * hash_state + pos * proof.initial_proof_hashes[i][39] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][7] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][40], npos * hash_state + pos * proof.initial_proof_hashes[i][40] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][8] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][41], npos * hash_state + pos * proof.initial_proof_hashes[i][41] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][9] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][42], npos * hash_state + pos * proof.initial_proof_hashes[i][42] } )[2];
            pos        = pallas::base_field_type::value_type( proof.initial_proof_positions[i][10] );
            npos       = pallas::base_field_type::value_type( 1 ) - pos;
            hash_state = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * hash_state + npos * proof.initial_proof_hashes[i][43], npos * hash_state + pos * proof.initial_proof_hashes[i][43] } )[2];
            __builtin_assigner_exit_check( hash_state == proof.commitments[2] );

            std::array<pallas::base_field_type::value_type, 2> y = { 0, 0 };
            theta_acc                                            = pallas::base_field_type::value_type( 1 );
            pallas::base_field_type::value_type Q0;
            pallas::base_field_type::value_type Q1;
            Q0 = pallas::base_field_type::value_type( 0 );
            Q1 = pallas::base_field_type::value_type( 0 );
            Q0 += proof.initial_proof_values[i][0] * theta_acc;
            Q1 += proof.initial_proof_values[i][1] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][2] * theta_acc;
            Q1 += proof.initial_proof_values[i][3] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][4] * theta_acc;
            Q1 += proof.initial_proof_values[i][5] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][6] * theta_acc;
            Q1 += proof.initial_proof_values[i][7] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][8] * theta_acc;
            Q1 += proof.initial_proof_values[i][9] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][10] * theta_acc;
            Q1 += proof.initial_proof_values[i][11] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][12] * theta_acc;
            Q1 += proof.initial_proof_values[i][13] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][14] * theta_acc;
            Q1 += proof.initial_proof_values[i][15] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][16] * theta_acc;
            Q1 += proof.initial_proof_values[i][17] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][18] * theta_acc;
            Q1 += proof.initial_proof_values[i][19] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][20] * theta_acc;
            Q1 += proof.initial_proof_values[i][21] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][22] * theta_acc;
            Q1 += proof.initial_proof_values[i][23] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][24] * theta_acc;
            Q1 += proof.initial_proof_values[i][25] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][26] * theta_acc;
            Q1 += proof.initial_proof_values[i][27] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][28] * theta_acc;
            Q1 += proof.initial_proof_values[i][29] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][30] * theta_acc;
            Q1 += proof.initial_proof_values[i][31] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][32] * theta_acc;
            Q1 += proof.initial_proof_values[i][33] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][34] * theta_acc;
            Q1 += proof.initial_proof_values[i][35] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][36] * theta_acc;
            Q1 += proof.initial_proof_values[i][37] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][38] * theta_acc;
            Q1 += proof.initial_proof_values[i][39] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][40] * theta_acc;
            Q1 += proof.initial_proof_values[i][41] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][42] * theta_acc;
            Q1 += proof.initial_proof_values[i][43] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][44] * theta_acc;
            Q1 += proof.initial_proof_values[i][45] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][46] * theta_acc;
            Q1 += proof.initial_proof_values[i][47] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][48] * theta_acc;
            Q1 += proof.initial_proof_values[i][49] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][50] * theta_acc;
            Q1 += proof.initial_proof_values[i][51] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][52] * theta_acc;
            Q1 += proof.initial_proof_values[i][53] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][54] * theta_acc;
            Q1 += proof.initial_proof_values[i][55] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][56] * theta_acc;
            Q1 += proof.initial_proof_values[i][57] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][58] * theta_acc;
            Q1 += proof.initial_proof_values[i][59] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][60] * theta_acc;
            Q1 += proof.initial_proof_values[i][61] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][62] * theta_acc;
            Q1 += proof.initial_proof_values[i][63] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][64] * theta_acc;
            Q1 += proof.initial_proof_values[i][65] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][66] * theta_acc;
            Q1 += proof.initial_proof_values[i][67] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][68] * theta_acc;
            Q1 += proof.initial_proof_values[i][69] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][70] * theta_acc;
            Q1 += proof.initial_proof_values[i][71] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][72] * theta_acc;
            Q1 += proof.initial_proof_values[i][73] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][74] * theta_acc;
            Q1 += proof.initial_proof_values[i][75] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][76] * theta_acc;
            Q1 += proof.initial_proof_values[i][77] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][78] * theta_acc;
            Q1 += proof.initial_proof_values[i][79] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][80] * theta_acc;
            Q1 += proof.initial_proof_values[i][81] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][82] * theta_acc;
            Q1 += proof.initial_proof_values[i][83] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][84] * theta_acc;
            Q1 += proof.initial_proof_values[i][85] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][86] * theta_acc;
            Q1 += proof.initial_proof_values[i][87] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][88] * theta_acc;
            Q1 += proof.initial_proof_values[i][89] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][90] * theta_acc;
            Q1 += proof.initial_proof_values[i][91] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][92] * theta_acc;
            Q1 += proof.initial_proof_values[i][93] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][94] * theta_acc;
            Q1 += proof.initial_proof_values[i][95] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][96] * theta_acc;
            Q1 += proof.initial_proof_values[i][97] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][98] * theta_acc;
            Q1 += proof.initial_proof_values[i][99] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][100] * theta_acc;
            Q1 += proof.initial_proof_values[i][101] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][102] * theta_acc;
            Q1 += proof.initial_proof_values[i][103] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][104] * theta_acc;
            Q1 += proof.initial_proof_values[i][105] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][106] * theta_acc;
            Q1 += proof.initial_proof_values[i][107] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][108] * theta_acc;
            Q1 += proof.initial_proof_values[i][109] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][110] * theta_acc;
            Q1 += proof.initial_proof_values[i][111] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][112] * theta_acc;
            Q1 += proof.initial_proof_values[i][113] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][114] * theta_acc;
            Q1 += proof.initial_proof_values[i][115] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][116] * theta_acc;
            Q1 += proof.initial_proof_values[i][117] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][118] * theta_acc;
            Q1 += proof.initial_proof_values[i][119] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][120] * theta_acc;
            Q1 += proof.initial_proof_values[i][121] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][122] * theta_acc;
            Q1 += proof.initial_proof_values[i][123] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][124] * theta_acc;
            Q1 += proof.initial_proof_values[i][125] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][126] * theta_acc;
            Q1 += proof.initial_proof_values[i][127] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][128] * theta_acc;
            Q1 += proof.initial_proof_values[i][129] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][130] * theta_acc;
            Q1 += proof.initial_proof_values[i][131] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][132] * theta_acc;
            Q1 += proof.initial_proof_values[i][133] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][134] * theta_acc;
            Q1 += proof.initial_proof_values[i][135] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][136] * theta_acc;
            Q1 += proof.initial_proof_values[i][137] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][138] * theta_acc;
            Q1 += proof.initial_proof_values[i][139] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][140] * theta_acc;
            Q1 += proof.initial_proof_values[i][141] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][142] * theta_acc;
            Q1 += proof.initial_proof_values[i][143] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][144] * theta_acc;
            Q1 += proof.initial_proof_values[i][145] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][146] * theta_acc;
            Q1 += proof.initial_proof_values[i][147] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][148] * theta_acc;
            Q1 += proof.initial_proof_values[i][149] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][150] * theta_acc;
            Q1 += proof.initial_proof_values[i][151] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][152] * theta_acc;
            Q1 += proof.initial_proof_values[i][153] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][154] * theta_acc;
            Q1 += proof.initial_proof_values[i][155] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][156] * theta_acc;
            Q1 += proof.initial_proof_values[i][157] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][158] * theta_acc;
            Q1 += proof.initial_proof_values[i][159] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][160] * theta_acc;
            Q1 += proof.initial_proof_values[i][161] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][162] * theta_acc;
            Q1 += proof.initial_proof_values[i][163] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][164] * theta_acc;
            Q1 += proof.initial_proof_values[i][165] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][166] * theta_acc;
            Q1 += proof.initial_proof_values[i][167] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][168] * theta_acc;
            Q1 += proof.initial_proof_values[i][169] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][170] * theta_acc;
            Q1 += proof.initial_proof_values[i][171] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][172] * theta_acc;
            Q1 += proof.initial_proof_values[i][173] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][174] * theta_acc;
            Q1 += proof.initial_proof_values[i][175] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][176] * theta_acc;
            Q1 += proof.initial_proof_values[i][177] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][178] * theta_acc;
            Q1 += proof.initial_proof_values[i][179] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][180] * theta_acc;
            Q1 += proof.initial_proof_values[i][181] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][182] * theta_acc;
            Q1 += proof.initial_proof_values[i][183] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][184] * theta_acc;
            Q1 += proof.initial_proof_values[i][185] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][186] * theta_acc;
            Q1 += proof.initial_proof_values[i][187] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][188] * theta_acc;
            Q1 += proof.initial_proof_values[i][189] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][190] * theta_acc;
            Q1 += proof.initial_proof_values[i][191] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][192] * theta_acc;
            Q1 += proof.initial_proof_values[i][193] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][194] * theta_acc;
            Q1 += proof.initial_proof_values[i][195] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][196] * theta_acc;
            Q1 += proof.initial_proof_values[i][197] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][198] * theta_acc;
            Q1 += proof.initial_proof_values[i][199] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][200] * theta_acc;
            Q1 += proof.initial_proof_values[i][201] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][202] * theta_acc;
            Q1 += proof.initial_proof_values[i][203] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][204] * theta_acc;
            Q1 += proof.initial_proof_values[i][205] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][206] * theta_acc;
            Q1 += proof.initial_proof_values[i][207] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][208] * theta_acc;
            Q1 += proof.initial_proof_values[i][209] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][210] * theta_acc;
            Q1 += proof.initial_proof_values[i][211] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][212] * theta_acc;
            Q1 += proof.initial_proof_values[i][213] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][214] * theta_acc;
            Q1 += proof.initial_proof_values[i][215] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][216] * theta_acc;
            Q1 += proof.initial_proof_values[i][217] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][218] * theta_acc;
            Q1 += proof.initial_proof_values[i][219] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][220] * theta_acc;
            Q1 += proof.initial_proof_values[i][221] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][222] * theta_acc;
            Q1 += proof.initial_proof_values[i][223] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][224] * theta_acc;
            Q1 += proof.initial_proof_values[i][225] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][226] * theta_acc;
            Q1 += proof.initial_proof_values[i][227] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][228] * theta_acc;
            Q1 += proof.initial_proof_values[i][229] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][230] * theta_acc;
            Q1 += proof.initial_proof_values[i][231] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][232] * theta_acc;
            Q1 += proof.initial_proof_values[i][233] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][234] * theta_acc;
            Q1 += proof.initial_proof_values[i][235] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][236] * theta_acc;
            Q1 += proof.initial_proof_values[i][237] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][238] * theta_acc;
            Q1 += proof.initial_proof_values[i][239] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][240] * theta_acc;
            Q1 += proof.initial_proof_values[i][241] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][242] * theta_acc;
            Q1 += proof.initial_proof_values[i][243] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][244] * theta_acc;
            Q1 += proof.initial_proof_values[i][245] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][246] * theta_acc;
            Q1 += proof.initial_proof_values[i][247] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][248] * theta_acc;
            Q1 += proof.initial_proof_values[i][249] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][250] * theta_acc;
            Q1 += proof.initial_proof_values[i][251] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][252] * theta_acc;
            Q1 += proof.initial_proof_values[i][253] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][254] * theta_acc;
            Q1 += proof.initial_proof_values[i][255] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][256] * theta_acc;
            Q1 += proof.initial_proof_values[i][257] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][258] * theta_acc;
            Q1 += proof.initial_proof_values[i][259] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][260] * theta_acc;
            Q1 += proof.initial_proof_values[i][261] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][262] * theta_acc;
            Q1 += proof.initial_proof_values[i][263] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][264] * theta_acc;
            Q1 += proof.initial_proof_values[i][265] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][266] * theta_acc;
            Q1 += proof.initial_proof_values[i][267] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][268] * theta_acc;
            Q1 += proof.initial_proof_values[i][269] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][270] * theta_acc;
            Q1 += proof.initial_proof_values[i][271] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][272] * theta_acc;
            Q1 += proof.initial_proof_values[i][273] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][274] * theta_acc;
            Q1 += proof.initial_proof_values[i][275] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][276] * theta_acc;
            Q1 += proof.initial_proof_values[i][277] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][278] * theta_acc;
            Q1 += proof.initial_proof_values[i][279] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][280] * theta_acc;
            Q1 += proof.initial_proof_values[i][281] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][282] * theta_acc;
            Q1 += proof.initial_proof_values[i][283] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][284] * theta_acc;
            Q1 += proof.initial_proof_values[i][285] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][286] * theta_acc;
            Q1 += proof.initial_proof_values[i][287] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][288] * theta_acc;
            Q1 += proof.initial_proof_values[i][289] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][290] * theta_acc;
            Q1 += proof.initial_proof_values[i][291] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][292] * theta_acc;
            Q1 += proof.initial_proof_values[i][293] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][294] * theta_acc;
            Q1 += proof.initial_proof_values[i][295] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][296] * theta_acc;
            Q1 += proof.initial_proof_values[i][297] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][298] * theta_acc;
            Q1 += proof.initial_proof_values[i][299] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][300] * theta_acc;
            Q1 += proof.initial_proof_values[i][301] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][302] * theta_acc;
            Q1 += proof.initial_proof_values[i][303] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][304] * theta_acc;
            Q1 += proof.initial_proof_values[i][305] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][306] * theta_acc;
            Q1 += proof.initial_proof_values[i][307] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][308] * theta_acc;
            Q1 += proof.initial_proof_values[i][309] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][310] * theta_acc;
            Q1 += proof.initial_proof_values[i][311] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][312] * theta_acc;
            Q1 += proof.initial_proof_values[i][313] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][314] * theta_acc;
            Q1 += proof.initial_proof_values[i][315] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][316] * theta_acc;
            Q1 += proof.initial_proof_values[i][317] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][318] * theta_acc;
            Q1 += proof.initial_proof_values[i][319] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][320] * theta_acc;
            Q1 += proof.initial_proof_values[i][321] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][322] * theta_acc;
            Q1 += proof.initial_proof_values[i][323] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][324] * theta_acc;
            Q1 += proof.initial_proof_values[i][325] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][326] * theta_acc;
            Q1 += proof.initial_proof_values[i][327] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][328] * theta_acc;
            Q1 += proof.initial_proof_values[i][329] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][330] * theta_acc;
            Q1 += proof.initial_proof_values[i][331] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 -= U[0];
            Q1 -= U[0];
            Q0 /= ( res[0][0] - singles[0] );
            Q1 /= ( res[0][1] - singles[0] );
            y[0] += Q0;
            y[1] += Q1;
            Q0 = pallas::base_field_type::value_type( 0 );
            Q1 = pallas::base_field_type::value_type( 0 );
            Q0 += proof.initial_proof_values[i][0] * theta_acc;
            Q1 += proof.initial_proof_values[i][1] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][2] * theta_acc;
            Q1 += proof.initial_proof_values[i][3] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][4] * theta_acc;
            Q1 += proof.initial_proof_values[i][5] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][6] * theta_acc;
            Q1 += proof.initial_proof_values[i][7] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][8] * theta_acc;
            Q1 += proof.initial_proof_values[i][9] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][10] * theta_acc;
            Q1 += proof.initial_proof_values[i][11] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][12] * theta_acc;
            Q1 += proof.initial_proof_values[i][13] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][14] * theta_acc;
            Q1 += proof.initial_proof_values[i][15] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][16] * theta_acc;
            Q1 += proof.initial_proof_values[i][17] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][18] * theta_acc;
            Q1 += proof.initial_proof_values[i][19] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][20] * theta_acc;
            Q1 += proof.initial_proof_values[i][21] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][22] * theta_acc;
            Q1 += proof.initial_proof_values[i][23] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][24] * theta_acc;
            Q1 += proof.initial_proof_values[i][25] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][26] * theta_acc;
            Q1 += proof.initial_proof_values[i][27] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][28] * theta_acc;
            Q1 += proof.initial_proof_values[i][29] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][30] * theta_acc;
            Q1 += proof.initial_proof_values[i][31] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][32] * theta_acc;
            Q1 += proof.initial_proof_values[i][33] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][34] * theta_acc;
            Q1 += proof.initial_proof_values[i][35] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][36] * theta_acc;
            Q1 += proof.initial_proof_values[i][37] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][38] * theta_acc;
            Q1 += proof.initial_proof_values[i][39] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][40] * theta_acc;
            Q1 += proof.initial_proof_values[i][41] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][42] * theta_acc;
            Q1 += proof.initial_proof_values[i][43] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][44] * theta_acc;
            Q1 += proof.initial_proof_values[i][45] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][46] * theta_acc;
            Q1 += proof.initial_proof_values[i][47] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][48] * theta_acc;
            Q1 += proof.initial_proof_values[i][49] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][50] * theta_acc;
            Q1 += proof.initial_proof_values[i][51] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][52] * theta_acc;
            Q1 += proof.initial_proof_values[i][53] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][54] * theta_acc;
            Q1 += proof.initial_proof_values[i][55] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][56] * theta_acc;
            Q1 += proof.initial_proof_values[i][57] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][58] * theta_acc;
            Q1 += proof.initial_proof_values[i][59] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][60] * theta_acc;
            Q1 += proof.initial_proof_values[i][61] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][62] * theta_acc;
            Q1 += proof.initial_proof_values[i][63] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][64] * theta_acc;
            Q1 += proof.initial_proof_values[i][65] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][66] * theta_acc;
            Q1 += proof.initial_proof_values[i][67] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][68] * theta_acc;
            Q1 += proof.initial_proof_values[i][69] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][70] * theta_acc;
            Q1 += proof.initial_proof_values[i][71] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][72] * theta_acc;
            Q1 += proof.initial_proof_values[i][73] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][74] * theta_acc;
            Q1 += proof.initial_proof_values[i][75] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][76] * theta_acc;
            Q1 += proof.initial_proof_values[i][77] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][78] * theta_acc;
            Q1 += proof.initial_proof_values[i][79] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][80] * theta_acc;
            Q1 += proof.initial_proof_values[i][81] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][82] * theta_acc;
            Q1 += proof.initial_proof_values[i][83] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][84] * theta_acc;
            Q1 += proof.initial_proof_values[i][85] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][86] * theta_acc;
            Q1 += proof.initial_proof_values[i][87] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][88] * theta_acc;
            Q1 += proof.initial_proof_values[i][89] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][90] * theta_acc;
            Q1 += proof.initial_proof_values[i][91] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][92] * theta_acc;
            Q1 += proof.initial_proof_values[i][93] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][94] * theta_acc;
            Q1 += proof.initial_proof_values[i][95] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][96] * theta_acc;
            Q1 += proof.initial_proof_values[i][97] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][98] * theta_acc;
            Q1 += proof.initial_proof_values[i][99] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][100] * theta_acc;
            Q1 += proof.initial_proof_values[i][101] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][102] * theta_acc;
            Q1 += proof.initial_proof_values[i][103] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][104] * theta_acc;
            Q1 += proof.initial_proof_values[i][105] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][106] * theta_acc;
            Q1 += proof.initial_proof_values[i][107] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][108] * theta_acc;
            Q1 += proof.initial_proof_values[i][109] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][110] * theta_acc;
            Q1 += proof.initial_proof_values[i][111] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][112] * theta_acc;
            Q1 += proof.initial_proof_values[i][113] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][114] * theta_acc;
            Q1 += proof.initial_proof_values[i][115] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][116] * theta_acc;
            Q1 += proof.initial_proof_values[i][117] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][118] * theta_acc;
            Q1 += proof.initial_proof_values[i][119] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][120] * theta_acc;
            Q1 += proof.initial_proof_values[i][121] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][122] * theta_acc;
            Q1 += proof.initial_proof_values[i][123] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][124] * theta_acc;
            Q1 += proof.initial_proof_values[i][125] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][126] * theta_acc;
            Q1 += proof.initial_proof_values[i][127] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][128] * theta_acc;
            Q1 += proof.initial_proof_values[i][129] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][130] * theta_acc;
            Q1 += proof.initial_proof_values[i][131] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][132] * theta_acc;
            Q1 += proof.initial_proof_values[i][133] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][134] * theta_acc;
            Q1 += proof.initial_proof_values[i][135] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][136] * theta_acc;
            Q1 += proof.initial_proof_values[i][137] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][138] * theta_acc;
            Q1 += proof.initial_proof_values[i][139] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][140] * theta_acc;
            Q1 += proof.initial_proof_values[i][141] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][142] * theta_acc;
            Q1 += proof.initial_proof_values[i][143] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][144] * theta_acc;
            Q1 += proof.initial_proof_values[i][145] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][146] * theta_acc;
            Q1 += proof.initial_proof_values[i][147] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][148] * theta_acc;
            Q1 += proof.initial_proof_values[i][149] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][150] * theta_acc;
            Q1 += proof.initial_proof_values[i][151] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][152] * theta_acc;
            Q1 += proof.initial_proof_values[i][153] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][154] * theta_acc;
            Q1 += proof.initial_proof_values[i][155] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][156] * theta_acc;
            Q1 += proof.initial_proof_values[i][157] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][158] * theta_acc;
            Q1 += proof.initial_proof_values[i][159] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][160] * theta_acc;
            Q1 += proof.initial_proof_values[i][161] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][162] * theta_acc;
            Q1 += proof.initial_proof_values[i][163] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][164] * theta_acc;
            Q1 += proof.initial_proof_values[i][165] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][166] * theta_acc;
            Q1 += proof.initial_proof_values[i][167] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][168] * theta_acc;
            Q1 += proof.initial_proof_values[i][169] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][170] * theta_acc;
            Q1 += proof.initial_proof_values[i][171] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][172] * theta_acc;
            Q1 += proof.initial_proof_values[i][173] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][174] * theta_acc;
            Q1 += proof.initial_proof_values[i][175] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][176] * theta_acc;
            Q1 += proof.initial_proof_values[i][177] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][178] * theta_acc;
            Q1 += proof.initial_proof_values[i][179] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][180] * theta_acc;
            Q1 += proof.initial_proof_values[i][181] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][182] * theta_acc;
            Q1 += proof.initial_proof_values[i][183] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][184] * theta_acc;
            Q1 += proof.initial_proof_values[i][185] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][186] * theta_acc;
            Q1 += proof.initial_proof_values[i][187] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][188] * theta_acc;
            Q1 += proof.initial_proof_values[i][189] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][190] * theta_acc;
            Q1 += proof.initial_proof_values[i][191] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][192] * theta_acc;
            Q1 += proof.initial_proof_values[i][193] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][194] * theta_acc;
            Q1 += proof.initial_proof_values[i][195] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][196] * theta_acc;
            Q1 += proof.initial_proof_values[i][197] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][198] * theta_acc;
            Q1 += proof.initial_proof_values[i][199] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][200] * theta_acc;
            Q1 += proof.initial_proof_values[i][201] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][202] * theta_acc;
            Q1 += proof.initial_proof_values[i][203] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][204] * theta_acc;
            Q1 += proof.initial_proof_values[i][205] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][206] * theta_acc;
            Q1 += proof.initial_proof_values[i][207] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][208] * theta_acc;
            Q1 += proof.initial_proof_values[i][209] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][210] * theta_acc;
            Q1 += proof.initial_proof_values[i][211] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][212] * theta_acc;
            Q1 += proof.initial_proof_values[i][213] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][214] * theta_acc;
            Q1 += proof.initial_proof_values[i][215] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][216] * theta_acc;
            Q1 += proof.initial_proof_values[i][217] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][218] * theta_acc;
            Q1 += proof.initial_proof_values[i][219] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][220] * theta_acc;
            Q1 += proof.initial_proof_values[i][221] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][222] * theta_acc;
            Q1 += proof.initial_proof_values[i][223] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][224] * theta_acc;
            Q1 += proof.initial_proof_values[i][225] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][226] * theta_acc;
            Q1 += proof.initial_proof_values[i][227] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][228] * theta_acc;
            Q1 += proof.initial_proof_values[i][229] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][230] * theta_acc;
            Q1 += proof.initial_proof_values[i][231] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][232] * theta_acc;
            Q1 += proof.initial_proof_values[i][233] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][234] * theta_acc;
            Q1 += proof.initial_proof_values[i][235] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][236] * theta_acc;
            Q1 += proof.initial_proof_values[i][237] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][238] * theta_acc;
            Q1 += proof.initial_proof_values[i][239] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][240] * theta_acc;
            Q1 += proof.initial_proof_values[i][241] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][242] * theta_acc;
            Q1 += proof.initial_proof_values[i][243] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][244] * theta_acc;
            Q1 += proof.initial_proof_values[i][245] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][246] * theta_acc;
            Q1 += proof.initial_proof_values[i][247] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][248] * theta_acc;
            Q1 += proof.initial_proof_values[i][249] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][250] * theta_acc;
            Q1 += proof.initial_proof_values[i][251] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][252] * theta_acc;
            Q1 += proof.initial_proof_values[i][253] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][254] * theta_acc;
            Q1 += proof.initial_proof_values[i][255] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][256] * theta_acc;
            Q1 += proof.initial_proof_values[i][257] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 -= U[1];
            Q1 -= U[1];
            Q0 /= ( res[0][0] - singles[1] );
            Q1 /= ( res[0][1] - singles[1] );
            y[0] += Q0;
            y[1] += Q1;
            Q0 = pallas::base_field_type::value_type( 0 );
            Q1 = pallas::base_field_type::value_type( 0 );
            Q0 += proof.initial_proof_values[i][72] * theta_acc;
            Q1 += proof.initial_proof_values[i][73] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][74] * theta_acc;
            Q1 += proof.initial_proof_values[i][75] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][258] * theta_acc;
            Q1 += proof.initial_proof_values[i][259] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][260] * theta_acc;
            Q1 += proof.initial_proof_values[i][261] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][262] * theta_acc;
            Q1 += proof.initial_proof_values[i][263] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][264] * theta_acc;
            Q1 += proof.initial_proof_values[i][265] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][266] * theta_acc;
            Q1 += proof.initial_proof_values[i][267] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][268] * theta_acc;
            Q1 += proof.initial_proof_values[i][269] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][270] * theta_acc;
            Q1 += proof.initial_proof_values[i][271] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][272] * theta_acc;
            Q1 += proof.initial_proof_values[i][273] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][274] * theta_acc;
            Q1 += proof.initial_proof_values[i][275] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][276] * theta_acc;
            Q1 += proof.initial_proof_values[i][277] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][278] * theta_acc;
            Q1 += proof.initial_proof_values[i][279] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][280] * theta_acc;
            Q1 += proof.initial_proof_values[i][281] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][282] * theta_acc;
            Q1 += proof.initial_proof_values[i][283] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][284] * theta_acc;
            Q1 += proof.initial_proof_values[i][285] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][286] * theta_acc;
            Q1 += proof.initial_proof_values[i][287] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][290] * theta_acc;
            Q1 += proof.initial_proof_values[i][291] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 -= U[2];
            Q1 -= U[2];
            Q0 /= ( res[0][0] - singles[2] );
            Q1 /= ( res[0][1] - singles[2] );
            y[0] += Q0;
            y[1] += Q1;
            Q0 = pallas::base_field_type::value_type( 0 );
            Q1 = pallas::base_field_type::value_type( 0 );
            Q0 += proof.initial_proof_values[i][258] * theta_acc;
            Q1 += proof.initial_proof_values[i][259] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][260] * theta_acc;
            Q1 += proof.initial_proof_values[i][261] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][262] * theta_acc;
            Q1 += proof.initial_proof_values[i][263] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][264] * theta_acc;
            Q1 += proof.initial_proof_values[i][265] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][266] * theta_acc;
            Q1 += proof.initial_proof_values[i][267] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][268] * theta_acc;
            Q1 += proof.initial_proof_values[i][269] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][270] * theta_acc;
            Q1 += proof.initial_proof_values[i][271] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][272] * theta_acc;
            Q1 += proof.initial_proof_values[i][273] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][274] * theta_acc;
            Q1 += proof.initial_proof_values[i][275] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][276] * theta_acc;
            Q1 += proof.initial_proof_values[i][277] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][278] * theta_acc;
            Q1 += proof.initial_proof_values[i][279] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][280] * theta_acc;
            Q1 += proof.initial_proof_values[i][281] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][282] * theta_acc;
            Q1 += proof.initial_proof_values[i][283] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][284] * theta_acc;
            Q1 += proof.initial_proof_values[i][285] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 += proof.initial_proof_values[i][286] * theta_acc;
            Q1 += proof.initial_proof_values[i][287] * theta_acc;
            theta_acc *= challenges.lpc_theta;
            Q0 -= U[3];
            Q1 -= U[3];
            Q0 /= ( res[0][0] - singles[3] );
            Q1 /= ( res[0][1] - singles[3] );
            y[0] += Q0;
            y[1] += Q1;

            std::size_t                         D = D0_log - 1;
            pallas::base_field_type::value_type rhash;
            pos   = res[0][2];
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base( { 0, npos * y[0] + pos * y[1], pos * y[0] + npos * y[1] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][0] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][0], npos * rhash + pos * proof.round_proof_hashes[i][0] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][1] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][1], npos * rhash + pos * proof.round_proof_hashes[i][1] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][2] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][2], npos * rhash + pos * proof.round_proof_hashes[i][2] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][3] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][3], npos * rhash + pos * proof.round_proof_hashes[i][3] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][4] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][4], npos * rhash + pos * proof.round_proof_hashes[i][4] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][5] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][5], npos * rhash + pos * proof.round_proof_hashes[i][5] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][6] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][6], npos * rhash + pos * proof.round_proof_hashes[i][6] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][7] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][7], npos * rhash + pos * proof.round_proof_hashes[i][7] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][8] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][8], npos * rhash + pos * proof.round_proof_hashes[i][8] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][9] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][9], npos * rhash + pos * proof.round_proof_hashes[i][9] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][10] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][10], npos * rhash + pos * proof.round_proof_hashes[i][10] } )[2];
            __builtin_assigner_exit_check( rhash == proof.fri_roots[0] );

            pos   = res[1][2];
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base( { 0, npos * proof.round_proof_values[i][0] + pos * proof.round_proof_values[i][1],
                                                               npos * proof.round_proof_values[i][1] + pos * proof.round_proof_values[i][0] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][11] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][11], npos * rhash + pos * proof.round_proof_hashes[i][11] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][12] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][12], npos * rhash + pos * proof.round_proof_hashes[i][12] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][13] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][13], npos * rhash + pos * proof.round_proof_hashes[i][13] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][14] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][14], npos * rhash + pos * proof.round_proof_hashes[i][14] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][15] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][15], npos * rhash + pos * proof.round_proof_hashes[i][15] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][16] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][16], npos * rhash + pos * proof.round_proof_hashes[i][16] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][17] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][17], npos * rhash + pos * proof.round_proof_hashes[i][17] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][18] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][18], npos * rhash + pos * proof.round_proof_hashes[i][18] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][19] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][19], npos * rhash + pos * proof.round_proof_hashes[i][19] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][20] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][20], npos * rhash + pos * proof.round_proof_hashes[i][20] } )[2];
            __builtin_assigner_exit_check( rhash == proof.fri_roots[1] );

            pos   = res[2][2];
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base( { 0, npos * proof.round_proof_values[i][2] + pos * proof.round_proof_values[i][3],
                                                               npos * proof.round_proof_values[i][3] + pos * proof.round_proof_values[i][2] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][21] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][21], npos * rhash + pos * proof.round_proof_hashes[i][21] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][22] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][22], npos * rhash + pos * proof.round_proof_hashes[i][22] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][23] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][23], npos * rhash + pos * proof.round_proof_hashes[i][23] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][24] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][24], npos * rhash + pos * proof.round_proof_hashes[i][24] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][25] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][25], npos * rhash + pos * proof.round_proof_hashes[i][25] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][26] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][26], npos * rhash + pos * proof.round_proof_hashes[i][26] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][27] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][27], npos * rhash + pos * proof.round_proof_hashes[i][27] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][28] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][28], npos * rhash + pos * proof.round_proof_hashes[i][28] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][29] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][29], npos * rhash + pos * proof.round_proof_hashes[i][29] } )[2];
            __builtin_assigner_exit_check( rhash == proof.fri_roots[2] );

            pos   = res[3][2];
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base( { 0, npos * proof.round_proof_values[i][4] + pos * proof.round_proof_values[i][5],
                                                               npos * proof.round_proof_values[i][5] + pos * proof.round_proof_values[i][4] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][30] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][30], npos * rhash + pos * proof.round_proof_hashes[i][30] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][31] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][31], npos * rhash + pos * proof.round_proof_hashes[i][31] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][32] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][32], npos * rhash + pos * proof.round_proof_hashes[i][32] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][33] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][33], npos * rhash + pos * proof.round_proof_hashes[i][33] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][34] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][34], npos * rhash + pos * proof.round_proof_hashes[i][34] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][35] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][35], npos * rhash + pos * proof.round_proof_hashes[i][35] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][36] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][36], npos * rhash + pos * proof.round_proof_hashes[i][36] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][37] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][37], npos * rhash + pos * proof.round_proof_hashes[i][37] } )[2];
            __builtin_assigner_exit_check( rhash == proof.fri_roots[3] );

            pos   = res[4][2];
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base( { 0, npos * proof.round_proof_values[i][6] + pos * proof.round_proof_values[i][7],
                                                               npos * proof.round_proof_values[i][7] + pos * proof.round_proof_values[i][6] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][38] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][38], npos * rhash + pos * proof.round_proof_hashes[i][38] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][39] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][39], npos * rhash + pos * proof.round_proof_hashes[i][39] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][40] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][40], npos * rhash + pos * proof.round_proof_hashes[i][40] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][41] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][41], npos * rhash + pos * proof.round_proof_hashes[i][41] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][42] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][42], npos * rhash + pos * proof.round_proof_hashes[i][42] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][43] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][43], npos * rhash + pos * proof.round_proof_hashes[i][43] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][44] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][44], npos * rhash + pos * proof.round_proof_hashes[i][44] } )[2];
            __builtin_assigner_exit_check( rhash == proof.fri_roots[4] );

            pos   = res[5][2];
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base( { 0, npos * proof.round_proof_values[i][8] + pos * proof.round_proof_values[i][9],
                                                               npos * proof.round_proof_values[i][9] + pos * proof.round_proof_values[i][8] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][45] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][45], npos * rhash + pos * proof.round_proof_hashes[i][45] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][46] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][46], npos * rhash + pos * proof.round_proof_hashes[i][46] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][47] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][47], npos * rhash + pos * proof.round_proof_hashes[i][47] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][48] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][48], npos * rhash + pos * proof.round_proof_hashes[i][48] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][49] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][49], npos * rhash + pos * proof.round_proof_hashes[i][49] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][50] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][50], npos * rhash + pos * proof.round_proof_hashes[i][50] } )[2];
            __builtin_assigner_exit_check( rhash == proof.fri_roots[5] );

            pos   = res[6][2];
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base( { 0, npos * proof.round_proof_values[i][10] + pos * proof.round_proof_values[i][11],
                                                               npos * proof.round_proof_values[i][11] + pos * proof.round_proof_values[i][10] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][51] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][51], npos * rhash + pos * proof.round_proof_hashes[i][51] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][52] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][52], npos * rhash + pos * proof.round_proof_hashes[i][52] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][53] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][53], npos * rhash + pos * proof.round_proof_hashes[i][53] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][54] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][54], npos * rhash + pos * proof.round_proof_hashes[i][54] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][55] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][55], npos * rhash + pos * proof.round_proof_hashes[i][55] } )[2];
            __builtin_assigner_exit_check( rhash == proof.fri_roots[6] );

            pos   = res[7][2];
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base( { 0, npos * proof.round_proof_values[i][12] + pos * proof.round_proof_values[i][13],
                                                               npos * proof.round_proof_values[i][13] + pos * proof.round_proof_values[i][12] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][56] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][56], npos * rhash + pos * proof.round_proof_hashes[i][56] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][57] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][57], npos * rhash + pos * proof.round_proof_hashes[i][57] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][58] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][58], npos * rhash + pos * proof.round_proof_hashes[i][58] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][59] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][59], npos * rhash + pos * proof.round_proof_hashes[i][59] } )[2];
            __builtin_assigner_exit_check( rhash == proof.fri_roots[7] );

            pos   = res[8][2];
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base( { 0, npos * proof.round_proof_values[i][14] + pos * proof.round_proof_values[i][15],
                                                               npos * proof.round_proof_values[i][15] + pos * proof.round_proof_values[i][14] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][60] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][60], npos * rhash + pos * proof.round_proof_hashes[i][60] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][61] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][61], npos * rhash + pos * proof.round_proof_hashes[i][61] } )[2];
            pos   = pallas::base_field_type::value_type( proof.round_merkle_proof_positions[i][62] );
            npos  = pallas::base_field_type::value_type( 1 ) - pos;
            rhash = __builtin_assigner_poseidon_pallas_base(
                { 0, pos * rhash + npos * proof.round_proof_hashes[i][62], npos * rhash + pos * proof.round_proof_hashes[i][62] } )[2];
            __builtin_assigner_exit_check( rhash == proof.fri_roots[8] );

            for ( std::size_t j = 0; j < fri_rounds; j++ )
            {
                interpolant = __builtin_assigner_fri_lin_inter( res[j][0], y[0], y[1], challenges.fri_alphas[j] );
                __builtin_assigner_exit_check( interpolant == proof.round_proof_values[i][2 * j] );
                y[0] = proof.round_proof_values[i][2 * j];
                y[1] = proof.round_proof_values[i][2 * j + 1];

                pallas::base_field_type::value_type rhash;
            }

            interpolant                                = pallas::base_field_type::value_type( 0 );
            pallas::base_field_type::value_type x      = res[fri_rounds][0];
            pallas::base_field_type::value_type factor = pallas::base_field_type::value_type( 1 );
            for ( std::size_t j = 0; j < final_polynomial_size; j++ )
            {
                interpolant = interpolant + proof.final_polynomial[j] * factor;
                factor      = factor * x;
            }
            __builtin_assigner_exit_check( interpolant == y[0] );

            interpolant = pallas::base_field_type::value_type( 0 );
            x           = res[fri_rounds][1];
            factor      = pallas::base_field_type::value_type( 1 );
            for ( std::size_t j = 0; j < final_polynomial_size; j++ )
            {
                interpolant = interpolant + proof.final_polynomial[j] * factor;
                factor      = factor * x;
            }
            __builtin_assigner_exit_check( interpolant == y[1] );
        }
        return true;
    }

}
