#include "plugin_interface.hpp"
#include <xplugin/xfactory.hpp>
#include <xplugin/xplugin_registry.hpp>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string filename = "transactional_composition.ini";

using namespace acc;

int main(int argc, char **argv) {

  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " <plugin_directory>" << std::endl;
    return 1;
  }
  std::string plugin_directory = argv[1];

  using base_type = acc::PluginBase;
  using factory_base_type = xp::xfactory_base<base_type>;
  using plugin_registry_type = xp::xplugin_registry<factory_base_type>;

  plugin_registry_type registry(plugin_directory);

  std::cout << "Available plugins: [";
  for (auto p : registry) {
    std::cout << p.first << ", ";
  }
  std::cout << "]" << std::endl;

  // read config
  std::ifstream file(filename);
  std::vector<std::string> lines;
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return 1;
  }

  std::string line;
  while (std::getline(file, line)) {
    lines.push_back(line);
  }
  file.close();

  // execute
  PluginBase::FeatureMap features;

  for (const auto &ln : lines) {
    auto plugin = registry[ln]->create();
    std::cout << "Executing: " << ln << std::endl;
    plugin->execute(features);
  }

  // result -final score
  auto &val = features["score"];
  if (std::holds_alternative<int>(val)) {
    std::cout << "Score value: " << std::get<int>(val) << std::endl;
  } else {
    std::cout << "Value is not an integer." << std::endl;
  }
}
