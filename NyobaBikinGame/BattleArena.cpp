#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Character {
    string name;
    int hp;
    int maxHp;
    int attack;
    int healPower;
};

int randomInt(int a, int b) {
    return a + rand() % (b - a + 1);
}

void printStatus(const Character& p, const Character& e) {
    cout << "\n======== STATUS ========\n";
    cout << p.name << " HP: " << p.hp << "/" << p.maxHp << "\n";
    cout << e.name << " HP: " << e.hp << "/" << e.maxHp << "\n";
    cout << "========================\n\n";
}

int main() {
    srand((unsigned)time(0));

    Character player = {"PLAYER", 100, 100, 15, 20};
    Character enemy  = {"MONSTER", 120, 120, 12, 15};

    cout << "=== BATTLE ARENA ===\n";
    cout << "Kalahkan MONSTER!\n";

    while (player.hp > 0 && enemy.hp > 0) {

        printStatus(player, enemy);

        cout << "Aksi kamu:\n";
        cout << "1. Serang\n";
        cout << "2. Heal\n";
        cout << "Pilih: ";

        int pilih;
        cin >> pilih;

        cout << "\n";

        if (pilih == 1) {
            int dmg = randomInt(player.attack - 5, player.attack + 5);

            if (randomInt(1, 100) <= 20) {
                dmg *= 2;
                cout << "Critical Hit!!! ";
            }

            enemy.hp -= dmg;
            if (enemy.hp < 0) enemy.hp = 0;

            cout << "Kamu menyerang dan memberikan " << dmg << " damage!\n";
        } 
        else if (pilih == 2) {
            int heal = randomInt(player.healPower - 5, player.healPower + 5);
            player.hp += heal;
            if (player.hp > player.maxHp) player.hp = player.maxHp;
            cout << "Kamu memulihkan HP sebesar " << heal << "!\n";
        }
        else {
            cout << "Pilihan tidak valid. Kamu melewatkan giliran.\n";
        }

        if (enemy.hp <= 0) break;

        int enemyAction = randomInt(1, 3); 

        if (enemyAction <= 2) {
            int dmg = randomInt(enemy.attack - 4, enemy.attack + 4);

            if (randomInt(1, 100) <= 15) {
                dmg *= 2;
                cout << "Monster Critical Hit!!! ";
            }

            player.hp -= dmg;
            if (player.hp < 0) player.hp = 0;

            cout << "Monster menyerang dan memberikan " << dmg << " damage!\n";
        } 
        else {
            int heal = randomInt(enemy.healPower - 4, enemy.healPower + 4);
            enemy.hp += heal;
            if (enemy.hp > enemy.maxHp) enemy.hp = enemy.maxHp;

            cout << "Monster memulihkan HP sebesar " << heal << "!\n";
        }
    }

    cout << "\n===== HASIL PERTARUNGAN =====\n";
    if (player.hp <= 0 && enemy.hp <= 0) {
        cout << "Hasil seri! Kamu dan monster sama-sama tumbang!\n";
    }
    else if (player.hp <= 0) {
        cout << "Kamu kalah...\n";
    }
    else {
        cout << "Kamu menang! Monster telah dikalahkan!\n";
    }

    return 0;
}
