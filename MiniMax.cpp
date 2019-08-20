#include "Players.h"

/*
* ROBOT: MiniMax
* Although the name of the robot is "MiniMax", it don't use the *real* MiniMax algorithm. 
* More than a modified version of it.
*/
class Max : public Player{
public:
    bool chooseField(char*);
    int endControll(char*, int, int);
    int possibleTake(char *, int, int);
    int selectField(char*, int, int, int);
    int kickPossible(char*);
    Max(int, char);
};

char* copyArray(char*);

Max::Max(int player, char icon) : Player(player, icon){}

int Max::selectField(char* square, int player, int depth, int index){
    char* temp = copyArray(square);
    temp[index] = (player==1)?'X':'O';
    return endControll(temp, player, --depth);
}

int Max::possibleTake(char * square, int player, int depth){
    int sum = 0;

    for(int i = 0; i < 9; i++){
        if(square[i] != 'X' && square[i] != 'O'){
            sum += selectField(square, player, depth, i);
        }
    }

    return sum;

}

int Max::endControll(char * square, int player, int depth){

    int check = checkwin(player, square);

    if(check == this->getPlayer())
    {
        delete[] square;
        return depth;
    }
    else if(check == 0)    
        return -depth+possibleTake(square, (player==1)?2:1, --depth);
    else if(check == -1)
        return 0;
    else 
    {
        delete[] square;
        return -2*depth;
    }

}

int Max::kickPossible(char* square){

    int tempCheck;

    for(int i = 0; i < 9; i++){
        if(square[i] != 'X' && square[i] != 'O'){
            char* temp = copyArray(square);
            temp[i] = (getPlayer() == 2)?'X':'O';
            tempCheck = checkwin(getPlayer(), temp);
            if(tempCheck == getPlayer() || tempCheck == ((getPlayer() == 2)?1:2))
                return i;
        }
    }
    return -1;
}

bool Max::chooseField(char * square){

    int max = -10000;
    int index=-1;
    int tempMax;
    int tempIndex;

     for(int i = 0; i < 9; i++){
         if(square[i] != 'X' && square[i] != 'O'){
             
            tempIndex = kickPossible(square);
            if(tempIndex != -1){
                square[tempIndex] = this->getIcon();
                return true;
            }

             tempMax = this->selectField(square, getPlayer(), 9, i);
             if(tempMax > max){
                index = i;
                max = tempMax;
             }
         }
     }

    if(index != -1){
        square[index] = this->getIcon();
        return true;
    }else{
        return false;
    }
    
}

char* copyArray(char * adress){
    char* copyArray = new char[9];

    for(int i = 0; i < 9; i++)
        copyArray[i] = adress[i];

    return copyArray;
}
