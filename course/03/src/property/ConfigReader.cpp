#include <filesystem>
#include "ConfigReader.h"

std::unique_ptr<cld::Property> cld::ConfigReader::readProperty() {
    auto configPath{"../resource/config.json"};
    pt::ptree tree{};
    pt::read_json(configPath, tree);

    auto property = std::make_unique<cld::Property>();
    property->setDb(std::make_unique<cld::Db>(
            tree.get<std::string>("config.db.host"),
            tree.get<unsigned int>("config.db.port"),
            tree.get<std::string>("config.db.user"),
            tree.get<std::string>("config.db.password")
    ));

    return property;
}
