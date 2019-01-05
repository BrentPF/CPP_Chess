#ifndef PIECES_H
#define PIECES_H
#include "board.h"

class pieces
{
    public:
        pieces();
        pieces(char (*state)[8][8][3]);
        virtual ~pieces();
        int checkMove(int (*pos)[2], int placeRow, int placeCol);
        int pawn();
        int rook();
        int bishop();
        int horse();
        int king();
        int queen();


    protected:

    private:
};

#endif // PIECES_H
