#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"

class Character {
private:
    Weapon* weapon = nullptr;

public:
    void SetWeapon(Weapon* weapon);
    Weapon* GetWeapon() const;
    float GetModifiedDamage() const;
};

#endif
