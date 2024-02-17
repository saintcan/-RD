#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
public:
    virtual float GetDamage() const = 0;
    virtual std::string GetName() const = 0;
};

class Sword : public Weapon {
public:
    float GetDamage() const override;
    std::string GetName() const override;
};

class Bow : public Weapon {
public:
    float GetDamage() const override;
    std::string GetName() const override;
};

class Spear : public Weapon {
public:
    float GetDamage() const override;
    std::string GetName() const override;
};

class FireStaff : public Weapon {
public:
    float GetDamage() const override;
    std::string GetName() const override;
};

class IceStaff : public Weapon {
public:
    float GetDamage() const override;
    std::string GetName() const override;
};

#endif
