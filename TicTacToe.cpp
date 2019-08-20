#include <ctime>
#include <cstdlib>
#include "Players.h"

Player* selectPlayer(char, int);
void board(char * square);
void setupBoard(char*);

int main() {

    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Available Character: Human [H], Max [M]" << endl;

    Player* player1 = selectPlayer('X', 1);
    Player* player2 = selectPlayer('O', 2);

    if(player1 == 0 || player2 == 0)
        return -1;

    char* square = new char[9];

    setupBoard(square);

    srand(time(0));
	int win;
    char icon;
    Player* actPlayer = (rand()%2)?player1:player2;

    cout << ((actPlayer->getPlayer()==1)?2:1) << " begins. ";
    system("pause");

    do {
        board(square);
        
        if(actPlayer == player1)
            actPlayer = player2;
        else 
            actPlayer = player1;


        do{} while (!actPlayer->chooseField(square));

        win = checkwin(actPlayer->getPlayer(), square);
        
    } while (win == 0);

    board(square);

    if(win == -1){
        cout << "Nobody won." << endl;
    } else {
        cout << "Player " << win << " won" << endl;
    }
    system("pause");
    delete[] square;
    return 0;
}

/*
* Selects a player and returns a pointer to the new instance
*/
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
        return new Max(num, icon);
        break;

    default:
        cout << "Wrong enter. ";
        system("pause");
        return 0;
        break;
    }

}

/*
* Checks if somebody won
* 0 >>> The play didn't end
* 1 >>> Player 1 won
* 2 >>> Player 2 won
* -1 >>> Nobody won
*/
int checkwin(int player, char * square){
    
    for(int i = 0; i < 3; i++){
        if((square[3*i+0] == square[3*i+1] && square[3*i+0] == square[3*i+2]) ||
            (square[0*3+i] == square[3*1+i] && square[3*0+i] == square[3*2+i])){
            return player;
        }
    }

    
    if((square[3*0] == square[3*1+1] && square[3*0+0] == square[2*3+2]) ||
        (square[0*3+2] == square[1*3+1] && square[0*3+2] == square[2*3+0])){
        return player;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(square[3*i+j] != 'X' && square[3*i+j] != 'O'){
                return 0;
            }
        }
    } 
    return -1;
}

/*
* Creates an update of the board
*/
void board(char * square){

	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;
	cout << "     |     |     " << endl << endl;
}

void setupBoard(char* square){
    square[0] = '1';
    square[1] = '2';
    square[2] = '3';
    square[3] = '4';
    square[4] = '5';
    square[5] = '6';
    square[6] = '7';
    square[7] = '8';
    square[8] = '9';
}

