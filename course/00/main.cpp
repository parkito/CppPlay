#include <spdlog/spdlog.h>

#include "lib.h"

int main() {
  spdlog::
  auto logger = spdlog::stdout_logger_mt("console");
  logger->info("version {} was started", version());

  return 0;
}
