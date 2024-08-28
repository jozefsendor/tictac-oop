#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
#include <algorithm>
#include "Enums.hpp"

class CGame;

class CGameBoard{
    private:
        FIELD** m_board;
        int m_rows;
        int m_cols;
    public:  
        CGameBoard(int rows, int cols);
        ~CGameBoard();

        bool DisplayBoard() const;
};


#endif //GAMEBOARD_HPP