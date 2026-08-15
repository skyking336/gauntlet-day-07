#include "Inventory.hpp"


void Inventory::add(const std::string& item){
    m_holdingItems.push_back(item);
    return;
}

int Inventory::count() const{
    return static_cast<int>(m_holdingItems.size());
}

bool Inventory::has(const std::string& item) const{
    for(const auto& i : m_holdingItems){
        if (i == item){
            return true;
        }
    }
    return false;
}

void Inventory::remove(const std::string& item) {
    bool found = false;
    for(auto h = m_holdingItems.begin(); h != m_holdingItems.end();){
        if (*h == item){
            m_holdingItems.erase(h);
            found = true;
        }
        else{
            h++;
        }
        
    }
    if (!found){
        std::cout<< "didnt found anything to remove\n";
    }
    return;
}



