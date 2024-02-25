#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include "DamageModifier.h"
#include <memory>

class Character {
private:
    std::unique_ptr<Weapon> weapon = nullptr;
    std::unique_ptr<DamageModifier> damageModifier = nullptr;

public:
    void SetWeapon(std::unique_ptr<Weapon> weapon);
    void SetDamageModifier(std::unique_ptr<DamageModifier> modifier);
    Weapon* GetWeapon() const;
    float GetModifiedDamage() const;
};

#endif
