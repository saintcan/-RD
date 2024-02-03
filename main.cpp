#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Player {
    string playerName;
    float playerStrength;
    Player() = default;
    Player(const string& name, float strength) : playerName(name), playerStrength(strength) {}
};

class Clan {
private:
    map<string, Player> clanMembers;

public:
    // ƒодати гравц€ до клану
    void AddPlayer(const string& playerName, float playerStrength) {
        Player newPlayer(playerName, playerStrength);
        clanMembers[playerName] = newPlayer;
    }

    // ќтримати к≥льк≥сть гравц≥в у клан≥ за назвою
    int GetPlayerCount(const string& clanName) {
        return clanMembers.count(clanName);
    }

    // ќтримати результат поЇдинку м≥ж кланами
    int ClanFight(const string& firstClanName, const string& secondClanName) {
        float firstClanStrength = CalculateClanStrength(firstClanName);
        float secondClanStrength = CalculateClanStrength(secondClanName);

        if (firstClanStrength == secondClanStrength)
            return 0;
        else if (firstClanStrength > secondClanStrength)
            return 1;
        else
            return -1;
    }

private:
    // ќбчислити силу клану за його назвою
    float CalculateClanStrength(const string& clanName) {
        float totalStrength = 0;
        for (const auto& member : clanMembers) {
            if (member.first == clanName)
                totalStrength += member.second.playerStrength;
        }
        return totalStrength;
    }
};

int main() {
    Clan clanSystem;

    while (true) {
        string clanName, playerName;
        float playerStrength;

        cout << "Enter clan name (or stop to finish): ";
        cin >> clanName;
        if (clanName == "stop")
            break;

        cout << "Enter player name: ";
        cin >> playerName;

        cout << "Enter player strength: ";
        cin >> playerStrength;

        clanSystem.AddPlayer(clanName, playerStrength);
    }

    string firstClanName = "First Clan";
    string secondClanName = "Second Clan";

    int firstClanPlayerCount = clanSystem.GetPlayerCount(firstClanName);
    int secondClanPlayerCount = clanSystem.GetPlayerCount(secondClanName);

    int fightResult = clanSystem.ClanFight(firstClanName, secondClanName);

    cout << "First clan player count: " << firstClanPlayerCount << endl;
    cout << "Second clan player count: " << secondClanPlayerCount << endl;

    if (fightResult == 0)
        cout << "It's a draw!" << endl;
    else if (fightResult == 1)
        cout << "First clan wins!" << endl;
    else if (fightResult == -1)
        cout << "Second clan wins!" << endl;

    return 0;
}
