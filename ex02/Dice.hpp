#include <random>
#include "RandomSource.hpp"

// Dice.hpp: before the refactor, untestable
class Dice {
    public:
        explicit Dice(RandomSource& r) : rs(r) {};
        int roll(){ return rs.next(6) + 1;} 
    private:
        RandomSource& rs;
};
