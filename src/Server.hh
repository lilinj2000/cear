// Copyright (c) 2010
// All rights reserved.

#ifndef CEAR_SERVER_HH
#define CEAR_SERVER_HH

#include <memory>
#include <string>

#include "Config.hh"
#include "cata/MDService.hh"
#include "air/MDataFile.hh"

namespace cear {

class Server : public cata::ServiceCallback {
 public:
  Server(int argc, char *argv[]);

  ~Server();

  virtual void onRspMessage(const std::string& msg);

  virtual void onRtnMessage(const std::string& msg);

 protected:

 private:
  std::unique_ptr<Config> config_;
  std::unique_ptr<air::MDataFile> data_file_;

  std::unique_ptr<cata::MDService> md_service_;
};

};  // namespace cear

#endif
