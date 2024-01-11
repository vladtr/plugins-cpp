#include "plugin_interface.hpp"
#include <xplugin/xfactory.hpp>

#include <algorithm>

class AccumulatorMax : public acc::PluginBase {
public:
  AccumulatorMax() = default;
  virtual ~AccumulatorMax() = default;

  virtual void execute(PluginBase::FeatureMap &data) override {
    //return *std::max_element(data.begin(), data.end());
  }
  virtual std::string name() const override { return "Feature creation plugin - adds max value"; }
};

using factory_type = xp::xfactory<AccumulatorMax, acc::PluginBase>;
XPLUGIN_CREATE_XPLUGIN_FACTORY(factory_type);
