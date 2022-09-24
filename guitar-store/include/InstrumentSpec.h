#ifndef INCLUDE_INSTRUMENT_SPEC_H_
#define INCLUDE_INSTRUMENT_SPEC_H_

#include <string>

class InstrumentSpec {
 public:
  /**
  * Instrument manufacturers
  */
  enum Builder {Gibson, Taylor, Fender, Ibanez, AnyBuilder};

  /**
  * Instrument woods
  */
  enum Wood {Alder, Maple, Ash, Spruce, Cedar, AnyWood};

  /**
  * @param b The manufacturer of the instrument.
  * @param m The model of the instrument.
  * @param fWood The type of wood used on the front of the instrument.
  * @param bWood The type of wood used on the back of the instrument.
  */
  InstrumentSpec(Builder b, std::string m,
            Wood fWood, Wood bWood) :
    builder(b), model(m),
    frontWood(fWood), backWood(bWood) {}

  virtual ~InstrumentSpec() { }

  /**
  * Get the builder of the guitar.
  */
  Builder getBuilder();

  /**
  * Get the model of the guitar.
  */
  std::string getModel();

  /**
  * Get the front wood of the guitar.
  */
  Wood getFrontWood();

  /**
  * Get the back wood of the guitar.
  */
  Wood getBackWood();

  /**
  * Determines if the passed in spec matches this spec.
  * @param spec The specification to compare.
  * @return bool Returns true if the specification matches, false otherwise.
  */
  virtual bool matches(InstrumentSpec* spec);

 private:
  Builder builder;
  std::string model;
  Wood frontWood;
  Wood backWood;
};
#endif
