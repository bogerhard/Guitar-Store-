#include "Inventory.h"
#include "GuitarSpec.h"
#include "MandolinSpec.h"

Inventory::~Inventory() {
    for(unsigned int i=0; i<instruments.size(); ++i) {
        delete instruments.at(i);
    }
}

void Inventory::addInstrument(std::string sn, double p, InstrumentSpec* s) {
    if(s != nullptr){
      Instrument* i = new Instrument(sn, p, s);
      instruments.push_back(i);
    }
}

Instrument* Inventory::getInstrument(std::string serialNum) {
    for (Instrument* i : instruments) {
        if(serialNum.compare(i->getSerialNumber()) == 0) {
            return i;
        }
    }
    return nullptr;
}

std::vector<Instrument*> Inventory::search(InstrumentSpec* wanted) {
    std::vector<Instrument*> inStock;
    for(Instrument* i : instruments) {
        InstrumentSpec* spec = i->getSpec();
        if(spec != nullptr && spec->matches(wanted)){
          inStock.push_back(i);
      }
    }
    return inStock;
}
