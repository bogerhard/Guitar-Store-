#ifndef INCLUDE_INSTRUMENT_H_
#define INCLUDE_INSTRUMENT_H_

#include "InstrumentSpec.h"
#include <string>

class Instrument {
 public:
  virtual ~Instrument() { }
    /**
    * Representation of an instrument in the inventory.
    * @param sn The serial number of the instrument.
    * @param p The price of the instrument.
    * @param s The specs for the instrument.
    */
    Instrument(std::string sn, double p, InstrumentSpec* s) :
        serialNumber(sn), price(p), spec(s) {}

    /**
    * Get the serial number of the instrument.
    */
    std::string getSerialNumber();

    /**
    * Get the price of the instrument.
    */
    double getPrice();

    /**
    * Get the specifications of the instrument.
    */
    InstrumentSpec* getSpec();

 private:
    std::string serialNumber;
    double price;
    InstrumentSpec* spec;
};
#endif
