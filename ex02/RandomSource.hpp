#pragma once
#include <random>

struct RandomSource{
    virtual int next(int max) =0;
    virtual ~RandomSource() = default;
};

struct FakeRandom : RandomSource{
    int fake_i;

    explicit FakeRandom(int val): fake_i(val){(void) val;}

    int next(int max) override {(void) max; return fake_i;}
};

struct RealRandom : RandomSource{
    int m_val;
    explicit RealRandom(int max) : m_val(rand() % max) {};
    int next(int max) override{
        m_val = rand() % max;
        return m_val;
    }
};
