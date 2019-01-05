#include "pieces.h"
#include "board.h"
int checkMove(int (*pos)[2], int placeRow, int placeCol);
char (*check)[8][8][3];
int (*position)[2];
int put[2];
char picked[3];

pieces::pieces()
{
    //ctor
}

pieces::pieces(char (*state)[8][8][3])
{
    check=state;
}


pieces::~pieces()
{
    delete check;
}

int pieces::checkMove(int (*pos)[2], int placeRow, int placeCol){

    put[0]=placeRow;
    put[1]=placeCol;
    position = pos;
    for(int i =0; i<3; i++){
    picked[i]=(*check)[(*pos)[0]][(*pos)[1]][i];
    }
    position=pos;

    switch(picked[1]){
    case 'P':
        return pawn();
        break;
    case 'R':
        return pawn();
        break;
    case 'B':
        return pawn();
        break;
    case 'H':
        return pawn();
        break;
    case 'K':
        return pawn();
        break;
    case 'Q':
        return pawn();
        break;
    }

    return 0;
}

int pieces::pawn(){
    if (picked[0]=='B'){
        return 1;
    } else {

    }
    return 0;
}

int pieces::rook(){
    if (picked[0]=='B'){

    } else {

    }
}

int pieces::bishop(){
    if (picked[0]=='B'){

    } else {

    }
}

int pieces::horse(){
    if (picked[0]=='B'){

    } else {

    }
}

int pieces::king(){
    if (picked[0]=='B'){

    } else {

    }
}

int pieces::queen(){
    if (picked[0]=='B'){

    } else {

    }
}
