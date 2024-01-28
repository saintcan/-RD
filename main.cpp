#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character
{
private:
    string Name, CharClass;
    int Power, Health, Maxhealth;

public:
    Character(string n, int h, string c, int p)
    {
        Name = n;
        Health = h;
        CharClass = c;
        Power = p;
        Maxhealth = h;
    }

    int GetHealth()
    {
        return Health;
    }

    void takeDamage(int damage)
    {
        if (Health > 0) {
            if (CharClass == "mage") {
                if (damage > 2 * Power) {
                    int chance = rand() % 2; // 50% chance
                    if (chance == 0) {
                        cout << "miss\n";
                        return;
                    }
                }
            }
            else if (CharClass == "warrior" && Health <= 0.3 * Maxhealth)
            {
                damage -= Power;
            }

            if (CharClass == "mage" && damage % 2 == 0)
                Health -= 2 * damage;
            else if (CharClass == "warrior" && damage % 2 != 0)
                Health -= 3 * damage;
            else if (CharClass == "warrior" && damage % 2 == 0)
                cout << "blocked\n";
            else
                Health -= damage;

            if (Health <= 0)
                cout << Name << " died!\n";
            else
                cout << Name << " left " << Health << " health\n";
        }
        else {
            cout << Name << " already dead!\n";
        }
    }
};

int main() 
{
    srand(time(0));

    string Name, CharClass;
    int Health, Power;

    cout << "character name: ";
    cin >> Name;
    cout << "amount of health: ";
    cin >> Health;
    cout << "Choose a character class (mage or warrior): ";
    cin >> CharClass;
    cout << "Enter the power of the character: ";
    cin >> Power;

    Character character(Name, Health, CharClass, Power);

    int EnemyDamage;
    do {
        cout << "Enter enemy damage value: ";
        cin >> EnemyDamage;
        if (EnemyDamage != 0)
            character.takeDamage(EnemyDamage);
    } while (character.GetHealth() != 0);

    return 0;
}