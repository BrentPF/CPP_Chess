#include "board.h"
#include "pieces.h"
#include <string.h>
#include <iostream>
using namespace std;
//TODO: PLACE AND PICKUP METHODS; PIECES CLASS TO FIND ALL LEGAL MOVES ON PICKUP -> CONFIRM PLACEMENT ON PLACE
static char state[8][8][3];
static int picked[2]={0}; //co-ordinates of picked up piece
static pieces piece(&state);
board::board()
{
    setDefaultState();
    printState();
    pickup();
    place();
}

board::~board()
{
    delete &piece;
}

int board::setDefaultState(){
    char defaultState[8][8][3] = {
        {"BR", "BH", "BB", "BK", "BQ", "BB", "BH", "BR"},
        {"BP", "BP", "BP", "BP", "BP", "BP", "BP", "BP"},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {"WP", "WP", "WP", "WP", "WP", "WP", "WP", "WP"},
        {"WR", "WH", "WB", "WK", "WQ", "WB", "WH", "WR"},
    };
    memcpy(&state, &defaultState, sizeof(defaultState));
    return 1;
}

int board::place(){
    int toPlace[2] = {2,0};
    if (legal(2,0)){
        char rem[3] = {*state[2][0]};
        for (int i = 0; i<3;i++){
        state[2][0][i] = state[picked[0]][picked[1]][i];
        state[picked[0]][picked[1]][i] = 0;
        }
        picked[0] = 0;
        picked[1] = 0;
        printState();
    }
}

int board::pickup(){
    char testC[3];
    cin >> testC;
    picked[0] = '8' - testC[0];
    picked[1] = testC[1] - 'A';
    cout << picked[0] << endl;
    cout<<picked[1]<<endl;
}

int board::printState(){
    cout<<"  ";
    for (int h = 0; h < 8; h++){
        cout << "___ ";
    }
    cout<<endl;
    for (int i = 0; i < 8; i++){
        cout << 8-i;
        cout<<"|";
        for (int j = 0; j < 8; j++){
            cout << state[i][j];
            if (*state[i][j]!=0) cout << " |";
            else cout << "   |";
        }
        cout << endl;
        for (int k = 0; k < 1; k++){
            cout<<" |";
            for (int l = 0; l < 8; l++){
                cout << "___|";
            }
            cout<< endl;
        }
    }
    cout << "  ";
    for (int m = 0; m < 8; m++){
        cout << (char)((int)'A'+ m);
        cout << "   ";
    }
    cout<< endl;
    return 1;
}

int board::legal(int placeRow, int placeCol){
    return piece.checkMove(&picked, placeRow, placeCol);
}
