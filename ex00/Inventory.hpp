// Inventory.hpp
#pragma once

#include <string>
#include <vector>
#include <algorithm>


class Inventory {
    public:
        void add(const std::string& item);
        void remove(const std::string& item);   // absent item: no-op, cycle 4 proves it
        bool has(const std::string& item) const;
        int  count() const;

    private:
        std::vector<std::string> m_holdingItems;
};