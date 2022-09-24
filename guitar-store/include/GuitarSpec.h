#ifndef INCLUDE_GUITAR_SPEC_H_
#define INCLUDE_GUITAR_SPEC_H_

#include "InstrumentSpec.h"
#include <string>

class GuitarSpec : public InstrumentSpec {
 public:
  /*
  * @param b The manufacturer of the guitar.
  * @param m The model of the guitar.
  * @param fWood The type of wood used on the front of the guitar.
  * @param bWood The type of wood used on the back of the guitar.
  * @param nStrngs The number of strings of the guitar.
  */
  GuitarSpec(Builder b, std::string m,
            Wood fWood, Wood bWood,
            unsigned int nStrings) : InstrumentSpec(b, m, fWood, bWood),
                                     numStrings(nStrings) {}

  virtual ~GuitarSpec() { }

  /**
  * Get the number of strings of the guitar.
  */
  unsigned int getNumStrings();

  /**
  * Determines if the passed in spec matches this spec.
  * @param spec The specification to compare.
  * @return bool Returns true if the specification matches, false otherwise.
  */
  bool matches(InstrumentSpec* spec);

 private:
  Builder builder;
  std::string model;
  Wood frontWood;
  Wood backWood;
  unsigned int numStrings;
};
#endif
