#!/bin/bash
set -e
make
cd ./tkg-toolkit/linux
./setup.sh
./reflash.sh ../../gh60_lufa.hex
