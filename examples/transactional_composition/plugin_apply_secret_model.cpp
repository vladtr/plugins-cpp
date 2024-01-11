#include "plugin_interface.hpp"
#include <xplugin/xfactory.hpp>

#include <algorithm>

class XPLUGIN_API ApplyModel : public acc::PluginBase {
public:
  ApplyModel() = default;
  virtual ~ApplyModel() = default;

  virtual void execute(PluginBase::FeatureMap &data) override {
    // secret model output
    data["score"] = 800;
  }
  virtual std::string name() const override { return "Secret Model Executor Plugin"; }
};

using factory_type = xp::xfactory<ApplyModel, acc::PluginBase>;
XPLUGIN_CREATE_XPLUGIN_FACTORY(factory_type);
