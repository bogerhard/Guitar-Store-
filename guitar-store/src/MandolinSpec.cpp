#include "MandolinSpec.h"

MandolinSpec::Style MandolinSpec::getStyle() {
    return style;
}

bool MandolinSpec::matches(InstrumentSpec* wanted){
  MandolinSpec* ms = dynamic_cast<MandolinSpec*>(wanted);
  if(ms != nullptr){
    bool instrumentMatch = InstrumentSpec::matches(wanted);
    bool any = ms->getStyle() == MandolinSpec::AnyStyle;
    bool wanted = style == ms->getStyle();
    return instrumentMatch && (any || wanted);
  }
  return false;
}
