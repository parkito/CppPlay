#!/bin/bash
rm -r cmake-build-debug && cmake -H. -Bcmake-build-debug && cd cmake-build-debug && make all && make test && cd ..