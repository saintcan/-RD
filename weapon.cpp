#include "Weapon.h"

float Sword::GetDamage() const {
    return 20.0f; // ���������� �������� ��� ����
}

std::string Sword::GetName() const {
    return "Sword";
}

float Bow::GetDamage() const {
    return 15.0f; // ���������� �������� ��� ����
}

std::string Bow::GetName() const {
    return "Bow";
}

float Spear::GetDamage() const {
    return 25.0f; // ���������� �������� ��� �����
}

std::string Spear::GetName() const {
    return "Spear";
}

float FireStaff::GetDamage() const {
    return 30.0f; // ���������� �������� ��� ��������� ������
}

std::string FireStaff::GetName() const {
    return "Fire Staff";
}

float IceStaff::GetDamage() const {
    return 30.0f; // ���������� �������� ��� ��������� ������
}

std::string IceStaff::GetName() const {
    return "Ice Staff";
}
