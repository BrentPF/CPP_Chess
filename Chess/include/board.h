#ifndef BOARD_H
#define BOARD_H
#include "pieces.h"

class board
{
    public:
        board();
        virtual ~board();
        int setDefaultState();
        int printState();
        int legal(int placeRow, int placeCol);
        int place();
        int pickup();
    protected:

    private:
};

#endif // BOARD_H
