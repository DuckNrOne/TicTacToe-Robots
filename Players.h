#pragma once

#include <iostream>
using namespace std;
int checkwin(int, char*);

// MOTHER OF EVERY PLAYER
class Player{
private:
    int m_player;
    char m_icon;
public:
    Player(int, char);
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

// MAX
// Iterating through possible moves till finisch
// win >>> +1; lose >>> -1; nothing happen >>> -1 
class Max : public Player{
public:
    bool chooseField(char*);
    Max(int, char);
};


/* Example

class PlayerExample : public Player{
public:
    bool chooseField(char*);
    Human(int, char);
};

*/