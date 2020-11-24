#include "spdlog/spdlog.h"

#include "Lib.h"

int main() {
    spdlog::info("Patch version {0} \n{1}", version(), "Hello, world");
    return 0;
}
