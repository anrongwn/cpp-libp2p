/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LIBP2P_SERVER_ECHO_SESSION_HPP
#define LIBP2P_SERVER_ECHO_SESSION_HPP

#include <vector>

#include <boost/assert.hpp>
#include "connection/stream.hpp"
#include "protocol/echo/echo_config.hpp"

namespace libp2p::protocol {

  /**
   * @brief Echo session created by server.
   */
  class ServerEchoSession
      : public std::enable_shared_from_this<ServerEchoSession> {
   public:
    explicit ServerEchoSession(std::shared_ptr<connection::Stream> stream,
                               EchoConfig config = {});

    // start session
    void start();

    // stop session
    void stop();

   private:
    std::shared_ptr<connection::Stream> stream_;
    std::vector<uint8_t> buf_;

    void doRead();

    void onRead(outcome::result<size_t> rread);

    void doWrite(size_t size);

    void onWrite(outcome::result<size_t> rwrite);
  };

}  // namespace libp2p::protocol

#endif  // LIBP2P_SERVER_ECHO_SESSION_HPP
