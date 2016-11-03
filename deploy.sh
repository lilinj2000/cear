#! /bin/sh

home_app=~/app

home_cear=${home_app}/cear

./configure --prefix=${home_cear}

if test -d ${home_cear}; then
    rm -rf ${home_cear}
fi

make install

make distclean
