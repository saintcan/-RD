#include <iostream>
#include <vector>

using namespace std;

// класи персонажів
enum CharacterClass {
    Warrior,
    Mage,
};

// структури для даних персонажа
struct Character {
    int id;
    CharacterClass characterClass;
    float meleePower;
    float rangedPower;
};

// Функція для знаходження найсильнішого персонажа за сумою ближніх та дальніх атакк
int findStrongestCharacter(const vector<Character>& characters) {
    int strongestId = -1;
    float maxPower = -1;

    for (const Character& character : characters) {
        float totalPower = character.meleePower + character.rangedPower;
        if (totalPower > maxPower) {
            maxPower = totalPower;
            strongestId = character.id;
        }
    }

    return strongestId;
}

// Функція для знаходження найсильнішого персонажа в кожному класі
vector<int> findStrongestCharacterByClass(const vector<Character>& characters) {
    vector<float> maxPowers(3, -1); 
    vector<int> strongestIds(3, -1); 

    for (const Character& character : characters) {
        float totalPower = character.meleePower + character.rangedPower;
        if (totalPower > maxPowers[character.characterClass]) {
            maxPowers[character.characterClass] = totalPower;
            strongestIds[character.characterClass] = character.id;
        }
    }

    return strongestIds;
}

int main() {
    vector<Character> characters = {
        {1, Warrior, 10.5f, 8.3f},
        {2, Mage, 5.2f, 12.7f},
        {4, Warrior, 9.2f, 7.9f},
        {5, Mage, 8.4f, 10.1f},
    };

    int strongestId = findStrongestCharacter(characters);
    cout << "Strongest character: ID " << strongestId << endl;

    vector<int> strongestByClass = findStrongestCharacterByClass(characters);
    cout << "Strongest warrior: ID " << strongestByClass[Warrior] << endl;
    cout << "Strongest mage: ID " << strongestByClass[Mage] << endl;

    return 0;
}
