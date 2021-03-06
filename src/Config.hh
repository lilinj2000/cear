// Copyright (c) 2010
// All rights reserved.

#ifndef CEAR_CONFIG_HH
#define CEAR_CONFIG_HH

#include <string>
#include <memory>

#include "soil/Config.hh"

namespace cear {

namespace po = boost::program_options;

class Options : public soil::Options {
 public:
  Options();

  virtual ~Options();

  virtual po::options_description* configOptions();

  std::string instru;
  std::string data_file;
  std::string log_cfg;

 private:
  boost::program_options::options_description config_options_;
};

class Config {
 public:
  explicit Config(int argc = 0, char* argv[] = nullptr);
  ~Config();

  Options* cearOptions() {
    return cear_options_.get();
  }

  soil::Options* cataMDOptions() {
    return cata_md_options_.get();
  }

 private:
  std::unique_ptr<Options> cear_options_;
  std::unique_ptr<soil::Options> cata_md_options_;
};

};  // namespace cear

#endif
