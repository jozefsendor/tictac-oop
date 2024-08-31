#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
#include <algorithm>
#include <iostream>
#include <cstdlib>

#include "Enums.hpp"

class CGame;

class CGameBoard{
    private:
        FIELD** m_pBoard;
        CGame* m_pGame;
        int m_Rows;
        int m_Cols;
    public:  
        CGameBoard(int rows, int cols, CGame* game);
        ~CGameBoard();
        int GetRows();
        int GetCols();
        bool DisplayBoard() const;
        bool UpdateBoard(int fieldNum, SIGN playerSign);
        FIELD GetField(int rows, int cols);
};

#endif //GAMEBOARD_HPP