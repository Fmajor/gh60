#!/bin/bash
set -e
./build.sh
cd ./tkg-toolkit/linux
./setup.sh
./reflash.sh ../../gh60_lufa.hex
