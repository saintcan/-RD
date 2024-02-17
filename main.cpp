#include <iostream>
#include "Character.h"
#include "Weapon.h"

int main() {
    Character character;

    Sword sword;
    Bow bow;
    Spear spear;
    FireStaff fireStaff;
    IceStaff iceStaff;

    //character.SetWeapon(&sword); //���
    character.SetWeapon(&bow); //���
    //character.SetWeapon(&spear); //����
    //character.SetWeapon(&fireStaff); //�������� �����
    //character.SetWeapon(&iceStaff); //�������� �����

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
