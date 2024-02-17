#include "Weapon.h"

float Sword::GetDamage() const {
    return 20.0f; // Припустиме значення для меча
}

std::string Sword::GetName() const {
    return "Sword";
}

float Bow::GetDamage() const {
    return 15.0f; // Припустиме значення для лука
}

std::string Bow::GetName() const {
    return "Bow";
}

float Spear::GetDamage() const {
    return 25.0f; // Припустиме значення для списа
}

std::string Spear::GetName() const {
    return "Spear";
}

float FireStaff::GetDamage() const {
    return 30.0f; // Припустиме значення для вогняного посоха
}

std::string FireStaff::GetName() const {
    return "Fire Staff";
}

float IceStaff::GetDamage() const {
    return 30.0f; // Припустиме значення для крижаного посоха
}

std::string IceStaff::GetName() const {
    return "Ice Staff";
}
