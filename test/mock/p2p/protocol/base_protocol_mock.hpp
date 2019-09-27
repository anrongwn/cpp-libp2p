/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LIBP2P_BASE_PROTOCOL_MOCK_HPP
#define LIBP2P_BASE_PROTOCOL_MOCK_HPP

#include <gmock/gmock.h>
#include "p2p/protocol/base_protocol.hpp"

namespace libp2p::protocol {

  struct BaseProtocolMock : public BaseProtocol {
    ~BaseProtocolMock() override = default;

    MOCK_CONST_METHOD0(getProtocolId, peer::Protocol());
    MOCK_METHOD1(handle, void(StreamResult));
  };

}  // namespace libp2p::protocol

#endif  // LIBP2P_BASE_PROTOCOL_MOCK_HPP
