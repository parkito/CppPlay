#!/bin/bash
rm -r cmake-build-debug &&
  cmake -H. -Bcmake-build-debug &&
  cd cmake-build-debug &&
  make all &&
  make test &&
  make package &&
  dpkg -i allocator-0.0.1-Linux.deb &&
  ltrace -e malloc -e free allocator &&
  cd ..
