#ifndef INCLUDE_MANDOLIN_SPEC_H_
#define INCLUDE_MANDOLIN_SPEC_H_

#include "InstrumentSpec.h"
#include <string>

class MandolinSpec : public InstrumentSpec {
 public:
 /*
  * Mandolin styles
  */
  enum Style {Neapolitan, CarvedTop, FlatBack, AnyStyle};

  /**
  * @param b The manufacturer of the mandolin.
  * @param m The model of the mandolin.
  * @param fWood The type of wood used on the front of the mandolin.
  * @param bWood The type of wood used on the back of the mandolin.
  */
  MandolinSpec(Builder b, std::string m,
            Wood fWood, Wood bWood, Style s) :
              InstrumentSpec(b, m, fWood, bWood), style(s) {}

  virtual ~MandolinSpec() { }

  /**
  * Get the style of the mandolin.
  */
  Style getStyle();

  /**
  * Determines if the passed in spec matches this spec.
  * @param spec The specification to compare.
  * @return bool Returns true if the specification matches, false otherwise.
  */
  bool matches(InstrumentSpec* spec);

 private:
  Style style;
};
#endif
