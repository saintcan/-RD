#include "Character.h"

void Character::SetWeapon(std::unique_ptr<Weapon> weapon) {
    this->weapon = std::move(weapon);
}

void Character::SetDamageModifier(std::unique_ptr<DamageModifier> modifier) {
    this->damageModifier = std::move(modifier);
}

Weapon* Character::GetWeapon() const {
    return weapon.get();
}

float Character::GetModifiedDamage() const {
    if (weapon && damageModifier) {
        float baseDamage = weapon->GetDamage();
        return damageModifier->CalculateDamage(100, baseDamage); // Передаємо 100 як приклад поточного здоров'я
    }
    return 0.0f;
}
