#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функція для знаходження найбільшої шкоди
vector<int> findMaxDamage(const vector<int>& damages) {
    vector<int> maxIndices;
    int maxDamage = *max_element(damages.begin(), damages.end());

    for (int i = 0; i < damages.size(); ++i) {
        if (damages[i] == maxDamage)
            maxIndices.push_back(i);
    }

    return maxIndices;
}

// Функція для знаходження найменшої шкоди
vector<int> findMinDamage(const vector<int>& damages) {
    vector<int> minIndices;
    int minDamage = *min_element(damages.begin(), damages.end());

    for (int i = 0; i < damages.size(); ++i) {
        if (damages[i] == minDamage)
            minIndices.push_back(i);
    }

    return minIndices;
}

// Функція для знаходження номерів, які представляють лікування
vector<int> findHealing(const vector<int>& damages) {
    vector<int> healingIndices;

    for (int i = 0; i < damages.size(); ++i) {
        if (damages[i] < 0)
            healingIndices.push_back(i);
    }

    return healingIndices;
}

// Функція для підрахунку загальної шкоди або лікування
int calculateTotal(const vector<int>& damages, bool isDamage) {
    int total = 0;
    for (int damage : damages) {
        if ((isDamage && damage > 0) || (!isDamage && damage < 0))
            total += damage;
    }
    return total;
}

// Функція, що перевіряє, чи є хтось, хто не завдав шкоди
bool hasZeroDamage(const vector<int>& damages) {
    for (int damage : damages) {
        if (damage == 0)
            return true;
    }
    return false;
}

int main() {
    vector<int> damages;
    int input;

    cout << "Enter the amount of damage (or healing if the number is negative) for each number:\n";
    while (true) {
        cin >> input;
        if (input == 0)
            break;
        damages.push_back(input);
    }

    vector<int> maxDamageIndices = findMaxDamage(damages);
    vector<int> minDamageIndices = findMinDamage(damages);
    vector<int> healingIndices = findHealing(damages);

    cout << "The most damage was caused under the following numbers: ";
    for (int index : maxDamageIndices)
        cout << index + 1 << " ";
    cout << endl;

    cout << "The least damage was caused under the following numbers: ";
    for (int index : minDamageIndices)
        cout << index + 1 << " ";
    cout << endl;

    cout << "The healing was carried out under the following numbers: ";
    for (int index : healingIndices)
        cout << index + 1 << " ";
    cout << endl;

    cout << "Total damage: " << calculateTotal(damages, true) << endl;
    cout << "Total healing: " << calculateTotal(damages, false) << endl;

    if (hasZeroDamage(damages))
        cout << "There is someone who has not harmed us\n";
    else
        cout << "Everyone has harmed us\n";

    return 0;
}
