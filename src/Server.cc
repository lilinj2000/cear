// Copyright (c) 2010
// All rights reserved.

#include "Server.hh"
#include "Log.hh"
#include "air/CearData.hh"

namespace cear {

Server::Server(int argc, char* argv[]) {
  CEAR_TRACE <<"Server::Server()";

  config_.reset(new Config(argc, argv));

  if (!config_->cearOptions()->data_file.empty())
    data_file_.reset(new air::MDataFile(config_->cearOptions()->data_file));

  md_service_.reset(cata::MDService::createService(
      config_->cataMDOptions(),
      this));

  cata::InstrumentSet instrus;
  instrus.insert(config_->cearOptions()->instru);
  md_service_->subMarketData(instrus);
}

Server::~Server() {
  CEAR_TRACE <<"Server::~Server()";
}

void Server::onRspMessage(const std::string& msg) {
  CEAR_TRACE <<"Server::onRspMessage()";

  CEAR_INFO <<msg;
}

void Server::onRtnMessage(const std::string& msg) {
  CEAR_TRACE <<"Server::onRtnMessage()";

  CEAR_INFO <<msg;

  if (data_file_.get()) {
    try {
      std::unique_ptr<air::CearData> data(new air::CearData());
      data->fromString(msg);

      data_file_->putData(data.release());
    } catch (std::exception& e) {
      CEAR_ERROR <<e.what();
    }
  }
}

};  // namespace cear
