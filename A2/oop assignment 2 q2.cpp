#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
protected:
    int playerid;
    string playername;
    int health;

public:
    Player(int id, string name, int hp = 100)
        : playerid(id), playername(name), health(hp) {}
};

class Weapon : public Player {
private:
    vector<string> weaponsList;

public:
    Weapon() : Player(0, ""), weaponsList{"Axe", "Knife", "Dagger", "Sword", "Crossbow"} {}

    void use() {
        int i;
        cout << "Which weapon do you want to use?" << endl;
        cin >> i;
        cout << "You chose to use " << weaponsList[i] << endl;
    }
};

class Enemy : public Player {
protected:
    int damage;
    int enemyhealth;

public:
    Enemy(int dam, int enemyhp = 100)
        : Player(0, ""), damage(dam), enemyhealth(enemyhp) {}

    void attack() {
        Player::health = Player::health - damage;
        cout << "Enemy's attack completed" << endl;
    }
};

class Character : public Player, public Enemy {
private:
    int level;
    string experience;
    int point;

public:
    Character(int le = 0, string exp = "Beginner", int poi = 0)
        : Player(0, ""), Enemy(0), level(le), experience(exp), point(poi) {}

   void Levelup() {
    if (point >= 10) { 
        if (experience == "Beginner") {
            experience = "Intermediate";
            cout << "Congratulations, you are now an " << experience << " level player" << endl;
            point = 0;
        } else if (experience == "Intermediate") {
            experience = "Advanced";
            cout << "Congratulations, you are now an " << experience << " level player" << endl;
            point = 0;
        } else if (experience == "Advanced") {
            experience = "Expert";
            cout << "Congratulations, you are now an " << experience << " level player" << endl;
            point = 0;
        }
    }
}

    void playGame() {
        Enemy::enemyhealth = Enemy::enemyhealth - 5;
        point = point + 10;
        cout << "Attack completed.." << endl;
    }
};

int main() {
    Character c1(3, "hamza");
    c1.playGame();
    c1.Levelup();

    Weapon w;
    w.use();

    Enemy e1(6);
    e1.attack();

    return 0;
}

