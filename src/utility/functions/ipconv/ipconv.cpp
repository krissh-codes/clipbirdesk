// Copyright (c) 2023 Sri Lakshmi Kanthan P
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "ipconv.hpp"

namespace srilakshmikanthanp::clipbirdesk::utility::functions {
/**
 * @brief Convert the QByteArray to QHostAddress IPv4
 * @param host Host address
 * @return QHostAddress
 */
QHostAddress toIPV4QHostAddress(const QByteArray& host) {
  // Create the QHostAddress from the IP address
  QHostAddress address;

  // convert the IP address to QHostAddress
  address.setAddress(*(reinterpret_cast<const quint32*>(host.data())));

  // Done return the address
  return address;
}

/**
 * @brief Convert the QByteArray to QHostAddress IPv6
 * @param host Host address
 * @return QHostAddress
 */
QHostAddress toIPV6QHostAddress(const QByteArray& host) {
  // Create the QHostAddress from the IP address
  QHostAddress address;

  // convert the IP address to QHostAddress
  Q_IPV6ADDR ipv6;

  // copy the data
  std::copy(host.begin(), host.end(), ipv6.c);

  // set the address
  address.setAddress(ipv6);

  // Done return the address
  return address;
}

/**
 * @brief Convert the QHostAddress to QByteArray IPv4
 * @param host Host address
 * @return QByteArray
 */
QByteArray toIPV4QByteArray(const QHostAddress& host) {
  // get the address
  const auto address = host.toIPv4Address();

  // get cast
  const auto cast    = reinterpret_cast<const char*>(&address);

  // convert the IP address to QByteArray
  return QByteArray(cast, sizeof(address));
}

/**
 * @brief Convert the QHostAddress to QByteArray IPv6
 * @param host Host address
 * @return QByteArray
 */
QByteArray toIPV6QByteArray(const QHostAddress& host) {
  // get the address
  const auto address = host.toIPv6Address();

  // get cast
  const auto cast    = reinterpret_cast<const char*>(&address);

  // convert the IP address to QByteArray
  return QByteArray(cast, sizeof(address));
}
}  // namespace srilakshmikanthanp::clipbirdesk::utility::functions
