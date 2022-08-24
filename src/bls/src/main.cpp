#include <iostream>

#include <nil/crypto3/pubkey/algorithm/sign.hpp>
#include <nil/crypto3/pubkey/algorithm/verify.hpp>
#include <nil/crypto3/pubkey/bls.hpp>

#include <nil/crypto3/algebra/curves/bls12.hpp>
#include <nil/crypto3/algebra/random_element.hpp>

#include <vector>
#include <string>

using namespace nil::crypto3;
using namespace nil::crypto3::algebra;
using namespace nil::crypto3::pubkey;
using namespace nil::crypto3::hashes;
using namespace nil::crypto3::multiprecision;

using curve_type = curves::bls12_381;
using scheme_type = bls<bls_default_public_params<>, bls_mss_ro_version, bls_basic_scheme, curve_type>;

using privkey_type = private_key<scheme_type>;
using pubkey_type = public_key<scheme_type>;
using _privkey_type = typename privkey_type::private_key_type;
using signature_type = typename pubkey_type::signature_type;

int main() {
    std::string msg_str = "hello world";
    std::vector<std::uint8_t> msg(msg_str.begin(), msg_str.end());
    privkey_type sk = privkey_type(random_element<typename _privkey_type::field_type>());

    signature_type sig = sign(msg, sk);
    pubkey_type &pubkey = sk;

    assert(verify(msg, sig, pubkey));
    std::cout << "Verified signature successfully\n";
    return 0;
}