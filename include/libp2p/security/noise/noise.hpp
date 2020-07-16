/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LIBP2P_INCLUDE_LIBP2P_SECURITY_NOISE_NOISE_HPP
#define LIBP2P_INCLUDE_LIBP2P_SECURITY_NOISE_NOISE_HPP

#include <libp2p/common/logger.hpp>
#include <libp2p/security/security_adaptor.hpp>

namespace libp2p::security {

  class Noise : public SecurityAdaptor,
                public std::enable_shared_from_this<Noise> {
   public:
    enum class Error {
      FAILURE = 1,
    };

    static constexpr auto kProtocolId = "/noise";
    static constexpr auto kNoiseProtocolName =
        "Noise_XX_25519_ChaChaPoly_SHA256";

    ~Noise() override = default;

    peer::Protocol getProtocolId() const override;

    void secureInbound(std::shared_ptr<connection::RawConnection> inbound,
                       SecConnCallbackFunc cb) override;

    void secureOutbound(std::shared_ptr<connection::RawConnection> outbound,
                        const peer::PeerId &p, SecConnCallbackFunc cb) override;

   private:
    common::Logger log_ = common::createLogger("Noise");
  };

}  // namespace libp2p::security

OUTCOME_HPP_DECLARE_ERROR(libp2p::security, Noise::Error);

#endif  // LIBP2P_INCLUDE_LIBP2P_SECURITY_NOISE_NOISE_HPP
