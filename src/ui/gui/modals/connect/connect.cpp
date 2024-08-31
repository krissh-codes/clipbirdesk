// Copyright (c) 2023 Sri Lakshmi Kanthan P
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "connect.hpp"

namespace srilakshmikanthanp::clipbirdesk::ui::gui::modals {
/**
 * @brief Construct a new Abstract object
 *
 * @param parent
 */
Connect::Connect(QWidget * parent) : QDialog(parent) {
  // create root layout
  auto root = new QVBoxLayout(this);

  // create label
  auto label = new QLabel(QObject::tr("Enter the IP and Port of the server"), this);

  // create the ip and port input
  auto ipv4 = new QLineEdit(this);

  // create the ip and port input
  auto port = new QLineEdit(this);

  // create the button
  auto button = new QPushButton(QObject::tr("Join"));

  // set the placeholder
  ipv4->setPlaceholderText(QObject::tr("IPv4"));

  // set the placeholder
  port->setPlaceholderText(QObject::tr("Port"));

  // add the ip and port input to layout
  root->addWidget(label);
  root->addWidget(ipv4);
  root->addWidget(port);
  root->addWidget(button);

  // set the icon
  this->setWindowIcon(QIcon(constants::getAppLogo()));

  // set the title
  this->setWindowTitle(constants::getAppName());

  // set layout
  this->setLayout(root);

  // connect the slot
  connect(button, &QPushButton::clicked, this, [this, ipv4, port]() {
    emit onConnect(ipv4->text(), port->text());
  });

  // set up language
  this->setUpLanguage();
}

/**
 * @brief Function used to set up all text in the label, etc..
 */
void Connect::setUpLanguage() {
  // Nothing to do
}

/**
 * @brief change event
 */
void Connect::changeEvent(QEvent *event) {
  if (event->type() == QEvent::LanguageChange) {
    this->setUpLanguage();
  }

  QWidget::changeEvent(event);
}
}
