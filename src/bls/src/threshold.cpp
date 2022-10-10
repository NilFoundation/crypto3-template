#include <nil/crypto3/pubkey/modes/algorithm/sign.hpp>
#include <nil/crypto3/pubkey/modes/algorithm/verify.hpp>
#include <nil/crypto3/pubkey/modes/algorithm/part_verify.hpp>
#include <nil/crypto3/pubkey/modes/algorithm/aggregate.hpp>
#include <nil/crypto3/pubkey/algorithm/deal_shares.hpp>
#include <nil/crypto3/pubkey/modes/algorithm/create_key.hpp>
#include <nil/crypto3/block/algorithm/block.hpp>

#include <nil/crypto3/pubkey/modes/threshold.hpp>

#include <nil/crypto3/pubkey/bls.hpp>

//#include <nil/crypto3/pubkey/secret_sharing.hpp>

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>

using namespace nil::crypto3;
using namespace nil::crypto3::algebra;
using namespace nil::crypto3::pubkey;
using namespace nil::crypto3::hashes;
using namespace nil::crypto3::multiprecision;



//
//BOOST_AUTO_TEST_CASE(threshold_bls_feldman_self_test) {
//    using curve_type = curves::bls12_381;
//    using hash_type = sha2<256>;
//    using bls_variant = bls_mps_ro_variant<curve_type, hash_type>; // HG : Does not work?
//    using base_scheme_type = bls<bls_variant, bls_basic_scheme>;
//    using mode_type = modes::threshold<base_scheme_type, feldman_sss, nop_padding>;
//    using scheme_type = typename mode_type::scheme_type;
//    using privkey_type = private_key<scheme_type>;
//    using pubkey_type = public_key<scheme_type>;
//    using no_key_type = no_key_ops<scheme_type>;
//    using sss_pubkey_no_key_type = typename privkey_type::sss_public_key_no_key_ops_type;
//
//    std::size_t n = 20;
//    std::size_t t = 10;
//
//    //===========================================================================
//    // dealer creates participants keys and its public key
//    typename sss_pubkey_no_key_type::coeffs_type coeffs = sss_pubkey_no_key_type::get_poly(t, n);
//    typename sss_pubkey_no_key_type::public_coeffs_type public_coeffs =
//            sss_pubkey_no_key_type::get_public_coeffs(coeffs);
//    typename sss_pubkey_no_key_type::public_coeffs_type public_coeffs_wrong(public_coeffs.begin(),
//                                                                            public_coeffs.end() - 1);
//    auto [PK, privkeys] = nil::crypto3::create_key<scheme_type>(coeffs, n);
//
//    //===========================================================================
//    // participants should check received shares before key creating
//    std::vector<privkey_type> verified_privkeys;
//    typename sss_pubkey_no_key_type::shares_type verified_shares =
//            nil::crypto3::deal_shares<typename privkey_type::sss_public_key_group_type>(coeffs, n);
//    for (auto &s : verified_shares) {
//        verified_privkeys.emplace_back(nil::crypto3::create_key<scheme_type>(public_coeffs, s, n));
//        BOOST_CHECK(verified_privkeys.back().verify_key(public_coeffs));
//        BOOST_CHECK(!verified_privkeys.back().verify_key(public_coeffs_wrong));
//    }
//
//    //===========================================================================
//    // participants sign messages and verify its signatures
//    std::vector<typename privkey_type::part_signature_type> part_signatures;
//    for (auto &sk : privkeys) {
//        part_signatures.emplace_back(nil::crypto3::sign<mode_type>(msg, sk));
//        BOOST_CHECK(static_cast<bool>(nil::crypto3::part_verify<mode_type>(msg, part_signatures.back(), sk)));
//    }
//
//    //===========================================================================
//    // threshold number of participants aggregate partial signatures
//    typename no_key_type::signature_type sig =
//            nil::crypto3::aggregate<mode_type>(part_signatures.begin(), part_signatures.begin() + t);
//    BOOST_CHECK(static_cast<bool>(nil::crypto3::verify<mode_type>(msg, sig, PK)));
//
//    //===========================================================================
//    // less than threshold number of participants cannot aggregate partial signatures
//    typename no_key_type::signature_type wrong_sig =
//            nil::crypto3::aggregate<mode_type>(part_signatures.begin(), part_signatures.begin() + t - 1);
//    BOOST_CHECK(!static_cast<bool>(nil::crypto3::verify<mode_type>(msg, wrong_sig, PK)));
//}


using curve_type = curves::bls12_381;
using hash_type = sha2<256>;
//using bls_variant = bls_mps_ro_variant<curve_type, hash_type>; //TODO check if compiles lol
using base_scheme_type = bls<bls_default_public_params<>, bls_mss_ro_version, bls_basic_scheme, curve_type>;



using mode_type = modes::threshold<base_scheme_type, feldman_sss, nop_padding>;
using scheme_type = typename mode_type::scheme_type;
using privkey_type = private_key<scheme_type>;
using pubkey_type = public_key<scheme_type>;
using no_key_type = no_key_ops<scheme_type>;
using sss_pubkey_no_key_type = typename privkey_type::sss_public_key_no_key_ops_type;


int main() {
    std::string msg_str = "hello world";

    return 0;
}