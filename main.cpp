#include <iostream>
#include "Character.h"
#include "Weapon.h"

int main() {
    Character character;

    std::unique_ptr<Weapon> swordPtr(new Sword());
    std::unique_ptr<Weapon> bowPtr(new Bow());
    std::unique_ptr<Weapon> spearPtr(new Spear());
    std::unique_ptr<Weapon> fireStaffPtr(new FireStaff());
    std::unique_ptr<Weapon> iceStaffPtr(new IceStaff());

    character.SetWeapon(std::move(swordPtr)); // Передача власності розумного вказівника
    character.SetWeapon(std::move(bowPtr));
    character.SetWeapon(std::move(spearPtr));
    character.SetWeapon(std::move(fireStaffPtr));
    character.SetWeapon(std::move(iceStaffPtr));

    Weapon* weapon = character.GetWeapon();
    if (weapon) {
        std::cout << "Character is using: " << weapon->GetName() << std::endl;
        std::cout << "Damage: " << weapon->GetDamage() << std::endl;
    }
    else {
        std::cout << "Character has no weapon assigned." << std::endl;
    }

    return 0;
}
