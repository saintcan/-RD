#ifndef DAMAGE_MODIFIER_H
#define DAMAGE_MODIFIER_H

class DamageModifier {
public:
    virtual float CalculateDamage(float currentHealth, float damage) const = 0;
};

class MultiplicationDamageModifier : public DamageModifier {
private:
    float multiplicator;

public:
    MultiplicationDamageModifier(float multiplicator);
    float CalculateDamage(float currentHealth, float damage) const override;
};

class AdditionDamageModifier : public DamageModifier {
private:
    float addition;

public:
    AdditionDamageModifier(float addition);
    float CalculateDamage(float currentHealth, float damage) const override;
};

class ParityDamageModifier : public DamageModifier {
private:
    float multiplicator;

public:
    ParityDamageModifier(float multiplicator);
    float CalculateDamage(float currentHealth, float damage) const override;
};

#endif
