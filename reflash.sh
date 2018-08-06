#!/bin/bash
set -e
make
cd ./tkg-toolkit/linux
./reflash.sh ../../gh60_lufa.hex
