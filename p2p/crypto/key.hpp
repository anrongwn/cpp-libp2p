/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LIBP2P_LIBP2P_CRYPTO_KEY_HPP
#define LIBP2P_LIBP2P_CRYPTO_KEY_HPP

#include "common/types.hpp"

namespace libp2p::crypto {

  using Buffer = libp2p::common::ByteArray;

  struct Key {
    /**
     * Supported types of all keys
     */
    enum class Type {
      UNSPECIFIED,
      RSA1024,
      RSA2048,
      RSA4096,
      ED25519,
      SECP256K1
    };

    Type type = Type::UNSPECIFIED;  ///< key type
    std::vector<uint8_t> data{};    ///< key content
  };

  inline bool operator==(const Key &lhs, const Key &rhs) {
    return lhs.type == rhs.type && lhs.data == rhs.data;
  }

  inline bool operator!=(const Key &lhs, const Key &rhs) {
    return !(lhs == rhs);
  }

  struct PublicKey : public Key {};

  struct PrivateKey : public Key {};

  struct KeyPair {
    PublicKey publicKey;
    PrivateKey privateKey;
  };

  inline bool operator==(const KeyPair &a, const KeyPair &b) {
    return a.publicKey == b.publicKey && a.privateKey == b.privateKey;
  }

  /**
   * Result of ephemeral key generation
   */
  struct EphemeralKeyPair {
    Buffer ephemeral_public_key;
    std::function<PrivateKey()> private_key_generator;
  };

  /**
   * Type of the stretched key
   */
  struct StretchedKey {
    Buffer iv;
    Buffer cipher_key;
    Buffer mac_key;
  };

}  // namespace libp2p::crypto

namespace std {
  template <>
  struct hash<libp2p::crypto::Key> {
    size_t operator()(const libp2p::crypto::Key &x) const;
  };

  template <>
  struct hash<libp2p::crypto::PrivateKey> {
    size_t operator()(const libp2p::crypto::PrivateKey &x) const;
  };

  template <>
  struct hash<libp2p::crypto::PublicKey> {
    size_t operator()(const libp2p::crypto::PublicKey &x) const;
  };

  template <>
  struct hash<libp2p::crypto::KeyPair> {
    size_t operator()(const libp2p::crypto::KeyPair &x) const;
  };
}  // namespace std

#endif  // LIBP2P_LIBP2P_CRYPTO_KEY_HPP
