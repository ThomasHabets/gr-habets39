#!/bin/bash

set -ueo pipefail

cd "$(dirname "$0")"
rm -fr build
mkdir build
cd build

if [[ $1 = "thomas" ]]; then
    cmake \
	-DCMAKE_INSTALL_PREFIX=$HOME/opt/gnuradio-3.9.4.0 \
	-DCMAKE_BUILD_TYPE=Release \
	..
else
    cmake \
	..
fi
make -j$(nproc)
echo "Now 'cd build && make install' to install"
