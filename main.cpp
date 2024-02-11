#include "building.h"
#include <iostream>
#include <string>

int main() {
    std::string command;

    do {
        int id, maxAge, initialCost;

        std::cout << "Enter building ID: ";
        std::cin >> id;

        std::cout << "Enter maximum age of the building (in years): ";
        std::cin >> maxAge;

        std::cout << "Enter initial cost of the building: $";
        std::cin >> initialCost;

        Building building(id, maxAge, initialCost);

        std::cout << "Initial cost of the building: $" << building.GetCost() << std::endl;

        int yearsToAge;
        std::cout << "Enter number of years to age the building: ";
        std::cin >> yearsToAge;

        building.ToAge(yearsToAge);
        std::cout << "Cost of the building after aging: $" << building.GetCost() << std::endl;

        std::cout << "Type 'stop' to exit, or anything else to continue: ";
        std::cin >> command;
    } while (command != "stop");

    return 0;
}
