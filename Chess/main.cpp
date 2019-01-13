/*
    Auth: Brent Pedro Flores
    A simple unregulated chess piece/board system. Room made for future functonality: illegal move checks, undo function, point system.
*/

#include <iostream>
#include "board.h"
#include "pieces.h"
using namespace std;

int main()
{
    board newBoard;
    char inp[3];
    int player = 1;
    while (true){
    cout << "\nPlayer " << player << ": Please choose a piece to pick up. Enter \"q\" to quit." << endl;
    cin >> inp;
    if (inp[0] == 'q') exit(1);
    newBoard.pickup(&inp);
    cout << "\nPlayer " << player << ": Please choose a square to place the chosen piece. Enter \"q\" to quit." << endl;
    cin >> inp;
    if (inp[0] == 'q') exit(1);
    newBoard.place(&inp);
    player = (player==1)?2:1;
    }
    return 1;
}

