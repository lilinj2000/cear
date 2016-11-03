// Copyright (c) 2010
// All rights reserved.

#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>

#include "Config.hh"
#include "Log.hh"
#include "cata/MDService.hh"

namespace cear {

Options::Options():
    config_options_("cearConfigOptions") {
  namespace po = boost::program_options;

  config_options_.add_options()
      ("cear.instru", po::value<std::string>(&instru),
       "instrument")
      ("cear.data_file", po::value<std::string>(&data_file),
       "data file")
      ("cear.log_cfg", po::value<std::string>(&log_cfg),
        "log config file");
  return;
}

Options::~Options() {
}

po::options_description* Options::configOptions() {
  return &config_options_;
}

Config::Config(int argc, char* argv[]) {
  cear_options_.reset(new Options());
  cata_md_options_.reset(cata::MDService::createOptions());

  std::unique_ptr<soil::Config> config(soil::Config::create());
  config->registerOptions(cear_options_.get());
  config->registerOptions(cata_md_options_.get());

  config->configFile() = "cear.cfg";
  config->loadConfig(argc, argv);

  // init the log
  CEAR_LOG_INIT(cear_options_->log_cfg);

  return;
}

Config::~Config() {
}

};  // namespace cear
