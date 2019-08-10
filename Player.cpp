#include <iostream>
using namespace std;

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

class Human : public Player{
public:
    bool chooseField(char*);
    Human(int, char);
};

Player::Player(int player, char icon): m_player(player), m_icon(icon){}
Player::~Player(){}

int Player::getPlayer(){return m_player;}
char Player::getIcon(){return m_icon;} 

Human::Human(int player, char icon) : Player(player, icon){}

bool Human::chooseField(char * square){

    cout << "Player " << getPlayer() << ", your decision: ";
    int dec;
    cin >> dec;
    dec--;

    if ((dec == 0 && *(square+dec) == '1') ||
        (dec == 1 && *(square+dec) == '2')  ||
        (dec == 2 && *(square+dec) == '3')  ||
        (dec == 3 && *(square+dec) == '4')  ||
        (dec == 4 && *(square+dec) == '5')  ||
        (dec == 5 && *(square+dec) == '6')  ||
        (dec == 6 && *(square+dec) == '7')  ||
        (dec == 7 && *(square+dec) == '8')  ||
        (dec == 8 && *(square+dec) == '9')){
        
        *(square+dec) = getIcon();
        return true;

    } else if ((*(square+dec) == 'X') || (*(square+dec) == 'O') || (dec > 8) || (dec < 1)){
        cout << "Wrong entery. ";
        system("pause");
        return false;
    }


}
