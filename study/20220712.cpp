// TextRPG 

#include <iostream>
using namespace std;

struct Entity
{
    bool isPlayer;
    int role;
    int hp;
    int att;
    int def;
};

void EnterLobby();
void StartGame();
void EnterField(Entity* player);
void RunBattle(Entity* player, Entity* monster);
void Attack(Entity* attack, Entity* defense);
Entity CreatePlayer(int role);
Entity CreateMonster(int role);

int main()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "Welcome! You're in." << endl;

    EnterLobby();

    cout << "--------------------------------------------------------" << endl;
    cout << "Bye!" << endl;
    cout << "--------------------------------------------------------" << endl;
}

void EnterLobby()
{
    while (true)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Do you want to play the game? yes(press 1) / no(press 0)" << endl;
        cout << "> ";

        int answer;
        cin >> answer;

        if (answer == 1)
        {
            while (true)
            {
                StartGame();
                cout << "--------------------------------------------------------" << endl;
                cout << "Replay? yes(1) / no (0)" << endl;
                cout << "> ";

                int replay;
                cin >> replay;

                if (replay == 1)
                    continue;
                else
                    return;
            }
        }
        else if (answer == 0)
            return;
        else
            continue;
    }
}

void StartGame()
{
    while (true)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Choose your role: knight(1) assassin(2) mage(3)" << endl;
        cout << "> ";

        int role;
        cin >> role;

        if (role == 1 || role == 2 || role == 3)
        {
            Entity player = CreatePlayer(role);
            EnterField(&player);
            return;
        }
        else
            continue;
    }
}

void EnterField(Entity* player)
{
    while (true)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Do you want to start the battle? yes(1) / no(0)" << endl;
        cout << "> ";

        int answer;
        cin >> answer;

        if (answer == 1)
        {
            srand(time(0));

            int monsterType = rand() % 3 + 1;  // 1, 2, 3
            Entity monster = CreateMonster(monsterType);
            while (player->hp > 0)
            {
                RunBattle(player, &monster);
            }
            return;
        }
        else if (answer == 0)
            return;
        else
            continue;
    }
}

void RunBattle(Entity* player, Entity* monster)
{
    cout << "Your hp: " << player->hp << endl;
    cout << "Monster hp: " << monster->hp << endl;

    int isPlayerWinner = false;
    while (true)
    {
        // player -> monster attack
        cout << "--------------------------------------------------------" << endl;
        cout << "You attacked the monster." << endl;
        Attack(player, monster);

        if (monster->hp == 0)
        {
            isPlayerWinner = true;
            break;
        }

        // monster -> player attack
        cout << "--------------------------------------------------------" << endl;
        cout << "The monster attacked you." << endl;
        Attack(monster, player);

        if (player->hp == 0)
        {
            break;
        }
    }

    if (isPlayerWinner == true)
        cout << "You win!" << endl;
    else
        cout << "You lose..." << endl;
}

void Attack(Entity* attack, Entity* defense)
{
    int damage = attack->att - defense->def;
    if (damage < 0)
        damage = 0;

    defense->hp -= damage;
    if (defense->hp < 0)
        defense->hp = 0;

    if (attack->isPlayer)
    {
        cout << "Your hp: " << attack->hp << endl;
        cout << "Monster hp: " << defense->hp << endl;
    }
    else
    {
        cout << "Your hp: " << defense->hp << endl;
        cout << "Monster hp: " << attack->hp << endl;
    }
}

Entity CreatePlayer(int role)
{
    enum PlayerRole
    {
        KNIGHT = 1,
        ASSASSIN,
        MAGE,
    };

    Entity player;
    player.isPlayer = true;
    player.role = role;

    if (role == KNIGHT)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Creating a knight..." << " ";
        player.hp = 80;
        player.att = 20;
        player.def = 5;
    }
    else if (role == ASSASSIN)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Creating an assassin..." << " ";
        player.hp = 70;
        player.att = 15;
        player.def = 10;
    }
    else  // mage
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Creating a mage..." << " ";
        player.hp = 60;
        player.att = 10;
        player.def = 8;
    }

    cout << "Done." << endl;

    return player;
}

Entity CreateMonster(int role)
{
    enum MonsterRole
    {
        SLIME = 1,
        ORC,
        GHOST,
    };

    Entity monster;
    monster.isPlayer = false;
    monster.role = role;

    if (role == SLIME)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Wild slime appeared!" << endl;
        monster.hp = 30;
        monster.att = 15;
        monster.def = 3;
    }
    else if (role == ORC)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Wild orc appeared!" << endl;
        monster.hp = 80;
        monster.att = 25;
        monster.def = 8;
    }
    else  // ghost
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Wild ghost appeared!" << endl;
        monster.hp = 50;
        monster.att = 12;
        monster.def = 5;
    }

    return monster;
}
