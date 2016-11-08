#!/bin/sh

home_app=~/app

####  ctp simnow  ###################
cd $home_app/cear_simnow/bin
source ./env.sh
./cear >/dev/null 2>&1 &

####  ctp citicsf  ###################
cd $home_app/cear_citicsf/bin
source ./env.sh
./cear >/dev/null 2>&1 &


####  ctp ht  ###################
cd $home_app/cear_ht/bin
source ./env.sh
./cear >/dev/null 2>&1 &


####  ctp sywg  ###################
cd $home_app/cear_sywg/bin
source ./env.sh
./cear >/dev/null 2>&1 &






