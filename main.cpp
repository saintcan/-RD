#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

class ClanSystem {
private:
    map<string, vector<float>> clanMembers;
    vector<string> clanNames;

public:
    // Додати гравця до клану
    void AddPlayer(const string& clanName, const string& playerName, float playerStrength) {
        clanMembers[clanName].push_back(playerStrength); 

        // Перевіряємо, чи клан вже збережено
        auto it = find(clanNames.begin(), clanNames.end(), clanName);
        if (it == clanNames.end()) {
            clanNames.push_back(clanName); 
        }
    }

    // Отримати кількість гравців у клані за назвою
    int GetPlayerCount(const string& clanName) {
        return clanMembers[clanName].size();
    }

    // Отримати результат поєдинку між кланами
    int ClanFight(const string& firstClanName, const string& secondClanName) {
        float firstClanStrength = accumulate(clanMembers[firstClanName].begin(), clanMembers[firstClanName].end(), 0.0f);
        float secondClanStrength = accumulate(clanMembers[secondClanName].begin(), clanMembers[secondClanName].end(), 0.0f);

        if (firstClanStrength == secondClanStrength)
            return 0;
        else if (firstClanStrength > secondClanStrength)
            return 1;
        else
            return -1;
    }

    // Отримати збережені імена кланів
    vector<string> GetClanNames() {
        return clanNames;
    }
};

int main() {
    ClanSystem clanSystem;

    while (true) {
        string clanName, playerName;
        float playerStrength;

        cout << "Enter clan name (or stop to finish): ";
        cin >> clanName;
        if (clanName == "stop")
            break;

        while (true) {
            cout << "Enter player name (or All to complete the clan): ";
            cin >> playerName;
            if (playerName == "All")
                break;

            cout << "Enter player strength: ";
            cin >> playerStrength;

            clanSystem.AddPlayer(clanName, playerName, playerStrength);
        }
    }

    // Отримання і виведення результату бою
    vector<string> clanNames = clanSystem.GetClanNames();
    if (clanNames.size() >= 2) {
        string firstClanName = clanNames[0];
        string secondClanName = clanNames[1];
        int fightResult = clanSystem.ClanFight(firstClanName, secondClanName);

        cout << "Result of the fight: ";
        if (fightResult == 0)
            cout << "It's a draw!" << endl;
        else if (fightResult == 1)
            cout << "First Clan wins!" << endl;
        else
            cout << "Second Clan wins!" << endl;
    }
    else {
        cout << "Not enough clans to simulate a fight." << endl;
    }

    return 0;
}
