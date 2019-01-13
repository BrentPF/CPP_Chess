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
        int place(char (*input)[3]);
        int pickup(char (*input)[3]);
    protected:

    private:
};

#endif // BOARD_H
