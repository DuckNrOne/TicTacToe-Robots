#include "Players.h"

class MiniMax : public Player{
public:
    bool chooseField(char*);
    int endControll(char*, int, int);
    int possibleTake(char *, int, int);
    int selectField(char*, int, int, int);
    MiniMax(int, char);
};

char* copyArray(char*);

MiniMax::MiniMax(int player, char icon) : Player(player, icon){}

int MiniMax::selectField(char* square, int player, int depth, int index){
    char* temp = copyArray(square);
    *(temp+index) = (player==1)?'X':'O';
    return endControll(temp, player, --depth);
}

int MiniMax::possibleTake(char * square, int player, int depth){
    int sum = 0;

    for(int i = 0; i < 9; i++){
        if(*(square+i) != 'X' && *(square+i) != 'O'){
            sum += selectField(square, player, depth, i);
        }
    }

    return sum;

}

int MiniMax::endControll(char * square, int player, int depth){

    int check = checkwin(player, square);

    if(check == this->getPlayer())
        return depth*1;
    else if(check == 0)    
        return this->possibleTake(square, (player==1)?2:2, depth/2);
    else if(check == -1)
        return 0;
    else 
        return depth*-1;

}

bool MiniMax::chooseField(char * square){

    int max = -10000;
    int index=-1;
    int tempMax;

     for(int i = 0; i < 9; i++){
         if(*(square+i) != 'X' && *(square+i) != 'O'){
             tempMax = this->selectField(square, getPlayer(), (2^9), i);
             if(tempMax > max){
                index = i;
                max = tempMax;
             }
         }
     }

    if(index != -1){
        *(square+index) = this->getIcon();
        return true;
    }else{
        return false;
    }
    
}

char* copyArray(char * adress){
    char* copyArray = *(new char[3][3]);

    for(int i = 0; i < 9; i++)
        *(copyArray+i) = *(adress+i);

    return copyArray;
}
