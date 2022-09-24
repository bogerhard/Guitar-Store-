#ifndef INCLUDE_INVENTORY_SPEC_H_
#define INCLUDE_INVENTORY_SPEC_H_

#include "Instrument.h"
#include "InstrumentSpec.h"
#include <vector>
#include <string>

class Inventory {
 public:
    virtual ~Inventory();
    /**
    * Adds an instrument to the inventory.
    * @param sn The serial number of the instrument.
    * @param p The price of the instrument.
    * @param s The specifications of the instrument.
    void addInstrument(std::string sn, double p, InstrumentSpec* s);

    */
    void addInstrument(std::string sn, double p, InstrumentSpec* s);

    /**
    * Gets an instrument from the inventory.
    * @param serialNum The serial number of the instrument.
    * @return The instrument with serial number serialNum
    */
    Instrument* getInstrument(std::string serialNum);

    /**
    * Find instrument in the inventory.
    * @param wanted The instrument that is sought.
    * @return A vector of instruments found.
    */
    std::vector<Instrument*> search(InstrumentSpec* wanted);

 private:
    std::vector<Instrument*> instruments;
};

#endif
