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
