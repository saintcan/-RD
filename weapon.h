#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <memory>

class Weapon {
public:
    virtual ~Weapon() = default;
    virtual float GetDamage() const = 0;
    virtual std::string GetName() const = 0;
};

class Sword : public Weapon {
public:
    float GetDamage() const override {
        return 20.0f; // Припустиме значення для меча
    }

    std::string GetName() const override {
        return "Sword";
    }
};

class Bow : public Weapon {
public:
    float GetDamage() const override {
        return 15.0f; // Припустиме значення для лука
    }

    std::string GetName() const override {
        return "Bow";
    }
};

class Spear : public Weapon {
public:
    float GetDamage() const override {
        return 25.0f; // Припустиме значення для списа
    }

    std::string GetName() const override {
        return "Spear";
    }
};

class FireStaff : public Weapon {
public:
    float GetDamage() const override {
        return 30.0f; // Припустиме значення для вогняного посоха
    }

    std::string GetName() const override {
        return "Fire Staff";
    }
};

class IceStaff : public Weapon {
public:
    float GetDamage() const override {
        return 30.0f; // Припустиме значення для крижаного посоха
    }

    std::string GetName() const override {
        return "Ice Staff";
    }
};

// Використання розумного вказівника для забезпечення автоматичного керування пам'яттю
using WeaponPtr = std::unique_ptr<Weapon>;

#endif
