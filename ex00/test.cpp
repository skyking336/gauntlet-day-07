// $ ./tests
// Randomness seeded to: 3567479892
// ===============================================================================
// All tests passed (7 assertions in 4 test cases)
// $ git log --oneline
// 1f6b2c9 green: removing a missing item is a no-op
// 84a0d3e red: removing a missing item is a no-op
// ...       (a red/green pair per behaviour)
// 7c3e91a green: adding an item raises the count
// b2d4f08 red: adding an item raises the count

#include "Inventory.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE("adding an item raises the count") {
    Inventory inv;
    inv.add("potion");
    CHECK(inv.count() == 1);
}

TEST_CASE("has() finds an added item and rejects a missing one") {
    Inventory inv;
    inv.add("potion");
    CHECK(inv.has("potion"));        
    CHECK_FALSE(inv.has("sword"));   
}

TEST_CASE("a inventory is added then remove, so ends with 0 count") {
    Inventory inv;
    inv.add("potion");
    inv.remove("potion");
    REQUIRE(inv.count() == 0);       // REQUIRE aborts the case; the line below is meaningless if this fails
    CHECK_FALSE(inv.has("potion"));  // CHECK reports and continues
}

TEST_CASE("removing a missing item is a no-op") {
    Inventory inv;
    inv.add("potion");
    inv.add("armor");
    inv.remove("weapon");
    REQUIRE(inv.count() == 2);     // 1. count unchanged
    CHECK(inv.has("potion"));      // 2. other items untouched
}
