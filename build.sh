#!/bin/bash
set -e
cd "$(dirname "$0")"
rm -fr build
mkdir build
cd build
cmake \
    -DCMAKE_INSTALL_PREFIX=$HOME/opt/gnuradio-3.9.4.0 \
    -DCMAKE_BUILD_TYPE=Release \
    ..
exec make -j$(nproc)
