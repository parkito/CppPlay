#include <cstdio>

#include "spdlog/spdlog.h"
#include "lib.h"

int main() {
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    return 0;
}
