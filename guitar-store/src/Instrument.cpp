#include "Instrument.h"

  std::string Instrument::getSerialNumber(){
    return serialNumber;
  }

  double Instrument::getPrice(){
    return price;
  }

  InstrumentSpec* Instrument::getSpec(){
    return spec;
  }
