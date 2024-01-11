#include "plugin_interface.hpp"
#include <xplugin/xfactory.hpp>

#include <algorithm>

class XPLUGIN_API AccumulatorMin : public acc::PluginBase {
public:
  AccumulatorMin() = default;
  virtual ~AccumulatorMin() = default;

  virtual void execute(PluginBase::FeatureMap &data) override {
    /*return *std::min_element(data.begin(), data.end());*/
  }
  virtual std::string name() const override { return "Feature creation plugin - adds min value"; }
};

using factory_type = xp::xfactory<AccumulatorMin, acc::PluginBase>;
XPLUGIN_CREATE_XPLUGIN_FACTORY(factory_type);
