#include "Inventory.hpp"


void Inventory::add(const std::string& item){
    m_holdingItems.push_back(item);
    return;
}

int Inventory::count() const{
    return static_cast<int>(m_holdingItems.size());
}





