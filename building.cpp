#include "building.h"
#include <iostream>

Building::Building(int id, int maxAge, int initialCost) : id(id), maxAge(maxAge), initialCost(initialCost), currentAge(0) {}

int Building::GetCost() const {
    if (currentAge >= maxAge) {
        return 0;
    }
    else if (currentAge >= maxAge / 2) {
        return initialCost / 2;
    }
    else {
        return initialCost - currentAge * initialCost / maxAge;
    }
}

void Building::ToAge(int years) {
    currentAge += years;
    if (currentAge >= maxAge) {
        Destroy();
    }
}

void Building::Destroy() {
    std::cout << "Building with ID " << id << " has been destroyed!" << std::endl;
}
