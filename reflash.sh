#!/bin/bash
set -e
./build.sh
cd ./tkg-toolkit/linux
./reflash.sh ../../gh60_lufa.hex
