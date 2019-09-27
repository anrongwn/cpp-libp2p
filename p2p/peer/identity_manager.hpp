/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LIBP2P_IDENTITY_MANAGER_HPP
#define LIBP2P_IDENTITY_MANAGER_HPP

#include "crypto/key.hpp"
#include "event/bus.hpp"
#include "peer/peer_id.hpp"

namespace libp2p::peer {

  namespace event {
    struct KeyPairChanged {};
    using KeyPairChangedChannel =
        libp2p::event::channel_decl<KeyPairChanged, crypto::KeyPair>;
  }  // namespace event

  /**
   * @brief Component, which "owns" information about current Host identity.
   */
  struct IdentityManager {
    virtual ~IdentityManager() = default;

    virtual const peer::PeerId &getId() const = 0;

    virtual const crypto::KeyPair &getKeyPair() const = 0;
  };

}  // namespace libp2p::peer

#endif  // LIBP2P_IDENTITY_MANAGER_HPP
