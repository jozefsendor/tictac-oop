#ifndef GAME_HPP
#define GAME_HPP

#include <cstddef>
#include "GameBoard.hpp"
#include "Player.hpp"
#include "Enums.hpp"

class CGame{
    private:
        static CGame* ms_pGame;
        CGame(int rows, int cols);
        ~CGame();
        
        CGameBoard* m_pGBoard;
        CPlayer* m_pPlayer1;
        CPlayer* m_pPlayer2;
    public:
        static CGame* Obiekt(int rows, int cols);
        static void DestroyInstance();
        bool StartGame();
        bool UpdateGame();
};


#endif //GAME_HPP