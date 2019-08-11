#include "Players.h"

Player::Player(int player, char icon): m_player(player), m_icon(icon){}
Player::~Player(){}

int Player::getPlayer(){return m_player;}
char Player::getIcon(){return m_icon;} 
