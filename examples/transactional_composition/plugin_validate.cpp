#include "plugin_interface.hpp"
#include <xplugin/xfactory.hpp>

#include <algorithm>

class XPLUGIN_API ValidatePlugin : public acc::PluginBase {
public:
  ValidatePlugin() = default;
  virtual ~ValidatePlugin() = default;

  virtual void execute(PluginBase::FeatureMap &data) override {
    // plugin payload goes here
  }
  virtual std::string name() const override { return "Validation Plugin"; }
};

using factory_type = xp::xfactory<ValidatePlugin, acc::PluginBase>;
XPLUGIN_CREATE_XPLUGIN_FACTORY(factory_type);
