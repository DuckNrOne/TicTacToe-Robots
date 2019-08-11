#pragma once

#include <iostream>
using namespace std;
int checkwin(int player, char * square);

// MOTHER OF EVERY PLAYER
class Player{
private:
    int m_player;
    char m_icon;
public:
    Player(int player, char icon);
    ~Player();
    int getPlayer();
    char getIcon();
    virtual bool chooseField(char*){};
};

// Humanplayer
class Human : public Player{
public:
    bool chooseField(char*);
    Human(int, char);
};

// Using MiniMax
class MiniMax : public Player{
public:
    bool chooseField(char*);
    MiniMax(int, char);
};


/* Example

class PlayerExample : public Player{
public:
    bool chooseField(char*);
    Human(int, char);
};

*/