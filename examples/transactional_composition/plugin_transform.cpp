#include "plugin_interface.hpp"
#include <xplugin/xfactory.hpp>

#include <algorithm>

class XPLUGIN_API TransformPlugin : public acc::PluginBase {
public:
  TransformPlugin() = default;
  virtual ~TransformPlugin() = default;

  virtual void execute(PluginBase::FeatureMap &data) override {
    // plugin payload goes here
  }
  virtual std::string name() const override { return "Transformation Plugin"; }
};

using factory_type = xp::xfactory<TransformPlugin, acc::PluginBase>;
XPLUGIN_CREATE_XPLUGIN_FACTORY(factory_type);
