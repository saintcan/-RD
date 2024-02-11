#ifndef BUILDING_H
#define BUILDING_H

class Building {
private:
    int id;
    int maxAge;
    int initialCost;
    int currentAge;

public:
    Building(int id, int maxAge, int initialCost);
    int GetCost() const;
    void ToAge(int years);

private:
    void Destroy();
};

#endif
