#include <string>
#include "gtest/gtest.h"
#include "Inventory.h"
#include "GuitarSpec.h"
#include "MandolinSpec.h"

class GuitarTests : public ::testing::Test {
 public:
    const double STRAT_PRICE = 1499.95;
    const std::string STRAT_SN = "FS3450204059138";

    Instrument* fenderStrat;
    GuitarSpec* fenderStratAlder;
    GuitarSpec* fenderStratMapleTop;
    GuitarSpec* fenderStratMapleBack;
    GuitarSpec* fenderStratAny;
    GuitarSpec* taylor_6string;
    GuitarSpec* taylor_12string;
    GuitarSpec* anyGuitar;

    MandolinSpec* flatBack;

    GuitarTests() {
        fenderStrat = new Instrument(STRAT_SN,
                                     STRAT_PRICE,
                                     fenderStratAlder);

        fenderStratAlder = new GuitarSpec(InstrumentSpec::Fender,
                                          "Stratocaster",
                                          InstrumentSpec::Alder,
                                          InstrumentSpec::Alder,
                                          6);

        fenderStratMapleTop = new GuitarSpec(InstrumentSpec::Fender,
                                             "Stratocaster",
                                             InstrumentSpec::Maple,
                                             InstrumentSpec::Alder,
                                             6);

        fenderStratMapleBack = new GuitarSpec(InstrumentSpec::Fender,
                                              "Stratocaster",
                                              InstrumentSpec::Alder,
                                              InstrumentSpec::Maple,
                                              6);

        fenderStratAny = new GuitarSpec(InstrumentSpec::Fender,
                                        "Stratocaster",
                                        InstrumentSpec::AnyWood,
                                        InstrumentSpec::AnyWood,
                                        0);

        taylor_6string = new GuitarSpec(InstrumentSpec::Taylor,
                                        "110e",
                                        InstrumentSpec::Maple,
                                        InstrumentSpec::Alder,
                                        6);

        taylor_12string = new GuitarSpec(InstrumentSpec::Taylor,
                                         "710e",
                                         InstrumentSpec::Maple,
                                         InstrumentSpec::Alder,
                                         12);

        anyGuitar = new GuitarSpec(InstrumentSpec::AnyBuilder,
                                   "",
                                   InstrumentSpec::AnyWood,
                                   InstrumentSpec::AnyWood,
                                   0);

        flatBack  = new MandolinSpec(InstrumentSpec::Ibanez,
                                     "MA327",
                                     InstrumentSpec::Maple,
                                     InstrumentSpec::Spruce,
                                     MandolinSpec::FlatBack);
    }

    virtual ~GuitarTests() {
        delete fenderStratAny;
        delete fenderStratAlder;
        delete taylor_6string;
    }
};

TEST_F(GuitarTests, instrumentGetters) {
    EXPECT_EQ(fenderStrat->getPrice(), STRAT_PRICE);
    EXPECT_EQ(fenderStrat->getSerialNumber(), STRAT_SN);
}

TEST_F(GuitarTests, specGetters) {
    EXPECT_EQ(fenderStratAlder->getFrontWood(), InstrumentSpec::Alder);
    EXPECT_EQ(fenderStratAlder->getBackWood(), InstrumentSpec::Alder);
    EXPECT_EQ(fenderStratAlder->getBuilder(), InstrumentSpec::Fender);
    EXPECT_EQ(fenderStratAlder->getModel(), "Stratocaster");
}

TEST_F(GuitarTests, found) {
    Inventory inventory;
    inventory.addInstrument(STRAT_SN, STRAT_PRICE, fenderStratAlder);

    EXPECT_NE(inventory.getInstrument(STRAT_SN), nullptr);
    EXPECT_EQ(inventory.search(fenderStratAny).size(), 1);
}

TEST_F(GuitarTests, notFound) {
    Inventory inventory;
    inventory.addInstrument("T1234", 799, taylor_6string);

    EXPECT_EQ(inventory.search(fenderStratAny).size(), 0);
}

TEST_F(GuitarTests, notFoundSN) {
    Inventory inventory;
    inventory.addInstrument("T1234", 799, taylor_6string);

    EXPECT_EQ(inventory.getInstrument("T5678"), nullptr);
}


TEST_F(GuitarTests, noSpec) {
    Inventory inventory;
    inventory.addInstrument("T1234", 799, nullptr);

    EXPECT_EQ(inventory.search(fenderStratAny).size(), 0);
}



TEST_F(GuitarTests, multipleInstruments) {
    Inventory inventory;
    inventory.addInstrument("T1234", 799, taylor_6string);
    inventory.addInstrument("T4321", 799, taylor_6string);
    inventory.addInstrument("T6789", 799, taylor_6string);

    EXPECT_EQ(inventory.search(anyGuitar).size(), 3);
}

TEST_F(GuitarTests, get12String) {
    Inventory inventory;
    inventory.addInstrument("T1234", 1499, fenderStratAlder);
    inventory.addInstrument("T5678", 799, taylor_6string);
    inventory.addInstrument("T9101", 999, taylor_12string);

    InstrumentSpec* lookingFor = new GuitarSpec(InstrumentSpec::AnyBuilder,
            "",
            InstrumentSpec::AnyWood,
            InstrumentSpec::AnyWood,
            12);
    EXPECT_EQ(inventory.search(lookingFor).size(), 1);
}

TEST_F(GuitarTests, getNoGuitars) {
    Inventory inventory;
    inventory.addInstrument("T1234", 999, flatBack);

    EXPECT_EQ(inventory.search(fenderStratAny).size(), 0);
}

TEST_F(GuitarTests, wrongTop) {
    Inventory inventory;
    inventory.addInstrument("T1234", 999, fenderStratAlder);

    EXPECT_EQ(inventory.search(fenderStratMapleTop).size(), 0);
}

TEST_F(GuitarTests, wrongBack) {
    Inventory inventory;
    inventory.addInstrument("T1234", 999, fenderStratAlder);

    EXPECT_EQ(inventory.search(fenderStratMapleBack).size(), 0);
}
