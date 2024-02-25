#ifndef DAMAGE_MODIFIER_H
#define DAMAGE_MODIFIER_H

class DamageModifier {
public:
    virtual ~DamageModifier() = default;
    virtual float CalculateDamage(float currentHealth, float damage) const = 0;
};

class MultiplicationDamageModifier : public DamageModifier {
private:
    float multiplicator;

public:
    explicit MultiplicationDamageModifier(float multiplicator);
    float CalculateDamage(float currentHealth, float damage) const override;
};

class AdditionDamageModifier : public DamageModifier {
private:
    float addition;

public:
    explicit AdditionDamageModifier(float addition);
    float CalculateDamage(float currentHealth, float damage) const override;
};

class ParityDamageModifier : public DamageModifier {
private:
    float multiplicator;

public:
    explicit ParityDamageModifier(float multiplicator);
    float CalculateDamage(float currentHealth, float damage) const override;
};

#endif
