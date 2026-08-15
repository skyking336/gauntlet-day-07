#include "Inventory.hpp"
#include "catch_amalgamated.hpp"

struct InventoryFixture {
    Inventory inv;                 // Catch2 builds a FRESH instance for every test below
    InventoryFixture() { inv.add("potion"); inv.add("sword"); }
};

TEST_CASE_METHOD(InventoryFixture, "adding an item raises the count") {
    inv.add("potion");
    CHECK(inv.count() == 3);
}

TEST_CASE_METHOD(InventoryFixture, "has() finds an added item and rejects a missing one") {
    CHECK(inv.has("potion"));        
    CHECK_FALSE(inv.has("armor"));   
}


TEST_CASE_METHOD(InventoryFixture, "removing an item drops the count") {
    inv.remove("potion");
    REQUIRE(inv.count() == 1);       // REQUIRE aborts the case; the line below is meaningless if this fails
    CHECK_FALSE(inv.has("potion"));  // CHECK reports and continues
}

TEST_CASE_METHOD(InventoryFixture, "removing a missing item is a no-op") {
    inv.remove("armor");
    REQUIRE(inv.count() == 2);
    CHECK(inv.has("potion"));
}