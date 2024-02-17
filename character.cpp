#include "Character.h"

void Character::SetWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

Weapon* Character::GetWeapon() const {
    return weapon;
}

float Character::GetModifiedDamage() const {
    if (weapon) {
        return weapon->GetDamage();
    }
    return 0.0f;
}
