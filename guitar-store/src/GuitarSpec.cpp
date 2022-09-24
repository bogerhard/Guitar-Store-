#include "GuitarSpec.h"

unsigned int GuitarSpec::getNumStrings(){
  return numStrings;
}

bool GuitarSpec::matches(InstrumentSpec* wanted){
    GuitarSpec* gs = dynamic_cast<GuitarSpec*>(wanted);
    if(gs != nullptr){
      bool instrumentMatch = InstrumentSpec::matches(wanted);
      bool any = gs->getNumStrings() == 0;
      bool wanted = numStrings == gs->getNumStrings();
      return instrumentMatch && (wanted || any);
    }
    return false;
}
