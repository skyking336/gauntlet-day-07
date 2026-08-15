#include "Dice.hpp"
#include "catch_amalgamated.hpp"
#include <iostream>

struct RandomFixture {
    FakeRandom zero = FakeRandom(0);
    FakeRandom five = FakeRandom(5);
};

// two test cases pinning the edges of the mapping: rng value 0 must give
// face 1, rng value 5 must give face 6. Binary name: tests.


TEST_CASE_METHOD(RandomFixture, "rng_value_0") {
    Dice d = Dice(zero);
    CHECK(d.roll() == 1);
}

TEST_CASE_METHOD(RandomFixture, "rng_value_five") {
    Dice d = Dice(five);
    CHECK(d.roll() == 6);
}

