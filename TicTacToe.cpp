#include <ctime>
#include <cstdlib>
#include "Players.h"

Player* selectPlayer(char, int);
void board(char * square);
int checkwin(int, char * square);

int main() {

    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Available Character: Human [H]" << endl;

    Player* player1 = selectPlayer('X', 1);
    Player* player2 = selectPlayer('O', 2);

    if(player1 == 0 || player2 == 0)
        return -1;

    char square[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    srand(time(0));
	int win;
    char icon;
    Player* actPlayer = (rand()%2)?player1:player2;

    do {
        board((char*) square);
        
        if(actPlayer == player1)
            actPlayer = player2;
        else 
            actPlayer = player1;


        do{} while (!actPlayer->chooseField((char*)square));

        win = checkwin(actPlayer->getPlayer(), (char*)square);
        
    } while (win == 0);

    board((char*)square);

    if(win == -1){
        cout << "Nobody won." << endl;
    } else {
        cout << "Player " << win << " won" << endl;
    }
    system("pause");
    return 0;
}


Player* selectPlayer(char icon, int num){
    char input;
    cout << "Player " << num << ": ";
    cin >> input;

    switch (input)
    {
    case 'h' :
        return new Human(num, icon);
        break;

    case 'm' :
        return new MiniMax(num, icon);
        break;

    default:
        cout << "Wrong enter. ";
        system("pause");
        return 0;
        break;
    }

}

/*
* 0 >>> The play didn't end
* 1 >>> Player 1 won
* 2 >>> Player 2 won
* -1 >>> Nobody won
*/
int checkwin(int player, char * square){
    
    for(int i = 0; i < 3; i++){
        if((*(square+3*i+0) == *(square+3*i+1) && *(square+3*i+0) == *(square+3*i+2)) ||
            (*(square+0*3+i) == *(square+3*1+i) && *(square+3*0+i) == *(square+3*2+i))){
            return player;
        }
    }

    
    if((*(square+3*0+0) == *(square+3*1+1) && *(square+3*0+0) == *(square+2*3+2)) ||
        (*(square+0*3+2) == *(square+1*3+1) && *(square+0*3+2) == *(square+2*3+0))){
        return player;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(*(square+3*i+j) != 'X' && *(square+3*i+j) != 'O'){
                return 0;
            }
        }
    } 
    return -1;
}

void board(char * square){

	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << *square << "  |  " << *(square+1) << "  |  " << *(square+2) << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << *(square+3) << "  |  " << *(square+4) << "  |  " << *(square+5) << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << *(square+6) << "  |  " << *(square+7) << "  |  " << *(square+8) << endl;
	cout << "     |     |     " << endl << endl;
}

