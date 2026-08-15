#include "Inventory.hpp"


void Inventory::add(const std::string& item){
    m_holdingItems.push_back(item);
    return;
}

int Inventory::count() const{
    return static_cast<int>(m_holdingItems.size());
}

bool Inventory::has(const std::string& item) const{
    for(auto h = m_holdingItems.begin(); h != m_holdingItems.end();){
        if (*h == item){
            return true;
        }
    }
    return false;
}

void Inventory::remove(const std::string& item) {
    for(auto h = m_holdingItems.begin(); h != m_holdingItems.end();){
        if (*h == item){
            m_holdingItems.erase(h);
        }
    }
    return;
}



