#include "MandolinSpec.h"

InstrumentSpec::Builder InstrumentSpec::getBuilder() {
    return builder;
}

std::string InstrumentSpec::getModel() {
    return model;
}

InstrumentSpec::Wood InstrumentSpec::getFrontWood() {
    return frontWood;
}

InstrumentSpec::Wood InstrumentSpec::getBackWood() {
    return backWood;
}

bool InstrumentSpec::matches(InstrumentSpec* wanted){
    if(wanted->getBuilder() != InstrumentSpec::AnyBuilder
      && builder != wanted->getBuilder()) {
        return false;
  }

  if(wanted->getModel() != "" &&
      model != wanted->getModel()) {
      return false;
  }

  if(wanted->getFrontWood() != InstrumentSpec::AnyWood
    && frontWood != wanted->getFrontWood()) {
      return false;
  }

  if(wanted->getBackWood() != InstrumentSpec::AnyWood
    && backWood != wanted->getBackWood()) {
      return false;
  }
  return true;
}
