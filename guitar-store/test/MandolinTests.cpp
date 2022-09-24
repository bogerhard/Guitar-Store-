#include <string>
#include "gtest/gtest.h"
#include "Inventory.h"
#include "GuitarSpec.h"
#include "MandolinSpec.h"

class MandolinTests : public ::testing::Test {
 public:
    GuitarSpec* anyGuitar;

    MandolinSpec* neapolitan;
    MandolinSpec* flatBack;
    MandolinSpec* anyMandolin;

    MandolinTests() {
        anyGuitar = new GuitarSpec(InstrumentSpec::AnyBuilder,
                                   "",
                                   InstrumentSpec::AnyWood,
                                   InstrumentSpec::AnyWood,
                                   0);

        neapolitan  = new MandolinSpec(InstrumentSpec::Ibanez,
                                       "MA325",
                                       InstrumentSpec::Maple,
                                       InstrumentSpec::Spruce,
                                       MandolinSpec::Neapolitan);

        flatBack  = new MandolinSpec(InstrumentSpec::Ibanez,
                                     "MA327",
                                     InstrumentSpec::Maple,
                                     InstrumentSpec::Spruce,
                                     MandolinSpec::FlatBack);

        anyMandolin  = new MandolinSpec(InstrumentSpec::AnyBuilder,
                                        "",
                                        InstrumentSpec::AnyWood,
                                        InstrumentSpec::AnyWood,
                                        MandolinSpec::AnyStyle);
    }

    virtual ~MandolinTests() {
        delete anyGuitar;
        delete neapolitan;
        delete flatBack;
        delete anyMandolin;
    }
};

TEST_F(MandolinTests, getSuccess) {
    Inventory inventory;
    inventory.addInstrument("T1234", 999, neapolitan);

    EXPECT_EQ(inventory.search(anyMandolin).size(), 1);
}

TEST_F(MandolinTests, getFail) {
    Inventory inventory;
    inventory.addInstrument("T1234", 999, neapolitan);

    EXPECT_EQ(inventory.search(flatBack).size(), 0);
}


TEST_F(MandolinTests, multipleInstruments) {
    Inventory inventory;
    inventory.addInstrument("T1234", 799, neapolitan);
    inventory.addInstrument("T4321", 799, neapolitan);
    inventory.addInstrument("T6789", 799, neapolitan);

    EXPECT_EQ(inventory.search(anyMandolin).size(), 3);
}

TEST_F(MandolinTests, getNoMandolins) {
    Inventory inventory;
    inventory.addInstrument("T1234", 999, anyGuitar);

    EXPECT_EQ(inventory.search(neapolitan).size(), 0);
}
