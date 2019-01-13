#include "board.h"
#include "pieces.h"
#include <string.h>
#include <iostream>
using namespace std;
static char state[8][8][3];
static int picked[2]={0};
static pieces piece(&state);
board::board()
{
    setDefaultState();
    printState();
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

int board::place(char (*input)[3]){
    int toPlace[2] = {0};
    toPlace[0] = '8' - (*input)[0];
    toPlace[1] = ((*input)[1]>'A')?(*input)[1] - 'A' - 32: (*input)[1] - 'A';
    if (legal(toPlace[0],toPlace[1])){
        char rem[3] = {*state[1][0]};
        for (int i = 0; i<3;i++){
        state[toPlace[0]][toPlace[1]][i] = state[picked[0]][picked[1]][i];
        state[picked[0]][picked[1]][i] = 0;
        }
        picked[0] = 0;
        picked[1] = 0;
        printState();
    }
}

int board::pickup(char (*input)[3]){
    picked[0] = '8' - (*input)[0];
    picked[1] = ((*input)[1]>'A')?(*input)[1] - 'A' - 32: (*input)[1] - 'A';
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
