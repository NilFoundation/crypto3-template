#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

#include <nil/crypto3/pubkey/bls.hpp>
#include <nil/crypto3/pubkey/modes/threshold_bls.hpp>

#include <nil/crypto3/pubkey/secret_sharing/pedersen.hpp>

#include <nil/crypto3/pubkey/modes/threshold.hpp>

#include <nil/crypto3/pubkey/algorithm/sign.hpp>
#include <nil/crypto3/pubkey/modes/algorithm/sign.hpp>
#include <nil/crypto3/pubkey/algorithm/verify.hpp>
#include <nil/crypto3/pubkey/modes/algorithm/part_verify.hpp>
#include <nil/crypto3/pubkey/algorithm/aggregate.hpp>
#include <nil/crypto3/pubkey/algorithm/deal_shares.hpp>

#include <nil/crypto3/pubkey/modes/algorithm/create_key.hpp>
#include <nil/crypto3/pubkey/modes/algorithm/part_verify.hpp>


using namespace nil::crypto3::algebra;
using namespace nil::crypto3::hashes;
using namespace nil::crypto3::pubkey;





int main() {

    const std::string msg_str = "hello foo";
    const std::vector<std::uint8_t> msg(std::cbegin(msg_str), std::cend(msg_str));
    const std::vector<std::uint8_t> msg_wrong(std::cbegin(msg_str), std::cend(msg_str) - 1);



    using curve_type = nil::crypto3::algebra::curves::bls12_381;
    using base_scheme_type = bls<bls_default_public_params<>, bls_mps_ro_version, bls_basic_scheme, curve_type>;

    using mode_type = modes::threshold<base_scheme_type, feldman_sss>;
    using scheme_type = typename mode_type::scheme_type;
    using privkey_type = private_key<scheme_type>;
    using pubkey_type = public_key<scheme_type>;

    using sss_public_key_group_type = typename pubkey_type::sss_public_key_group_type;
    using shares_dealing_processing_mode = typename nil::crypto3::pubkey::modes::isomorphic<sss_public_key_group_type>::template bind<
            nil::crypto3::pubkey::shares_dealing_policy<sss_public_key_group_type>>::type;
    using signing_processing_mode_type = typename mode_type::template bind<typename mode_type::signing_policy>::type;
    using verification_processing_mode_type =
            typename mode_type::template bind<typename mode_type::verification_policy>::type;
    using aggregation_processing_mode_type =
            typename mode_type::template bind<typename mode_type::aggregation_policy>::type;

    std::size_t n = 20;
    std::size_t t = 10;

    //===========================================================================
    // dealer creates participants keys and its public key

    // TODO: add public interface for get_poly and get_public_coeffs
    auto coeffs = sss_public_key_group_type::get_poly(t, n);
    auto public_coeffs = sss_public_key_group_type::get_public_coeffs(coeffs);

    decltype(public_coeffs) public_coeffs_wrong(public_coeffs.begin(), public_coeffs.end() - 1);
    auto [PK, privkeys] = nil::crypto3::create_key<scheme_type>(coeffs, n);
//
//    //===========================================================================
//    // participants should check received shares before key creating
//
    std::vector<privkey_type> verified_privkeys;
    typename shares_dealing_processing_mode::result_type verified_shares =
            nil::crypto3::deal_shares<sss_public_key_group_type>(coeffs, n);
    for (auto &s : verified_shares) {
        verified_privkeys.emplace_back(nil::crypto3::create_key<scheme_type>(public_coeffs, s, n));

        // TODO: add public interface verify_key
//        BOOST_CHECK(verified_privkeys.back().verify_key(public_coeffs));
//        BOOST_CHECK(!verified_privkeys.back().verify_key(public_coeffs_wrong));
    }
//
//    //===========================================================================
//    // participants sign messages and verify its signatures
//
    std::vector<typename privkey_type::part_signature_type> part_signatures;
    for (auto &sk : privkeys) {
        // TODO: add simplified call interface for sign
        part_signatures.emplace_back(
                nil::crypto3::sign<scheme_type, decltype(msg), signing_processing_mode_type>(msg, sk));
//        BOOST_CHECK(static_cast<bool>(nil::crypto3::part_verify<mode_type>(msg, part_signatures.back(), sk)));
//        BOOST_CHECK(!static_cast<bool>(nil::crypto3::part_verify<mode_type>(
//                msg, typename privkey_type::part_signature_type(part_signatures.back().get_index()), sk)));
    }
//
//    //===========================================================================
//    // threshold number of participants aggregate partial signatures
//
//    // TODO: add simplified call interface for aggregate and verify
    typename pubkey_type::signature_type sig =
            nil::crypto3::aggregate<scheme_type, decltype(std::cbegin(part_signatures)), aggregation_processing_mode_type>(
                    std::cbegin(part_signatures), std::cbegin(part_signatures) + t);
//    BOOST_CHECK(static_cast<bool>(
//                        nil::crypto3::verify<scheme_type, decltype(msg), verification_processing_mode_type>(msg, sig, PK)));
//
//    //===========================================================================
//    // less than threshold number of participants cannot aggregate partial signatures
//
//    // TODO: add simplified call interface for aggregate and verify
    typename pubkey_type::signature_type wrong_sig =
            nil::crypto3::aggregate<scheme_type, decltype(std::cbegin(part_signatures)), aggregation_processing_mode_type>(
                    std::cbegin(part_signatures), std::cbegin(part_signatures) + t - 1);
//    BOOST_CHECK(!static_cast<bool>(
//            nil::crypto3::verify<scheme_type, decltype(msg), verification_processing_mode_type>(msg, wrong_sig, PK)));



    return 0;
}