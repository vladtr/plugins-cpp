#ifndef PLUGIN_BASE_HPP
#define PLUGIN_BASE_HPP

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include <xplugin/xplugin_config.hpp> 

namespace acc {
class XPLUGIN_API PluginBase {
public:
  using AnyType = std::variant<bool, char, int, double, std::string>;
  using FeatureMap = std::unordered_map<std::string, AnyType>;

  virtual ~PluginBase() {}
  virtual void execute(FeatureMap &data) = 0;
  virtual std::string name() const = 0;
};
} // namespace acc

#endif // PLUGIN_BASE_HPP
