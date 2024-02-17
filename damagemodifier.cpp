#include "DamageModifier.h"

MultiplicationDamageModifier::MultiplicationDamageModifier(float multiplicator) : multiplicator(multiplicator) {}

float MultiplicationDamageModifier::CalculateDamage(float currentHealth, float damage) const {
    return damage * multiplicator;
}

AdditionDamageModifier::AdditionDamageModifier(float addition) : addition(addition) {}

float AdditionDamageModifier::CalculateDamage(float currentHealth, float damage) const {
    float modifiedDamage = damage + addition;
    return (modifiedDamage < 0) ? 0 : modifiedDamage;
}

ParityDamageModifier::ParityDamageModifier(float multiplicator) : multiplicator(multiplicator) {}

float ParityDamageModifier::CalculateDamage(float currentHealth, float damage) const {
    if (static_cast<int>(currentHealth) % 2 == 0) {
        return damage * multiplicator;
    }
    else {
        return damage;
    }
}
