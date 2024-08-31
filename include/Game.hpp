#ifndef GAME_HPP
#define GAME_HPP

#include <cstddef>
#include <iostream>
#include <ctime>
#include "GameBoard.hpp"
#include "Player.hpp"
#include "Enums.hpp"

class CGame{
    private:
        static CGame* ms_pGame;
        CGame(int rows, int cols, std::string name1, std::string name2);
        ~CGame();
        GAMESTATE m_GameState;

        CGameBoard* m_pGBoard;
        CPlayer* m_pPlayer1;
        CPlayer* m_pPlayer2;
        CPlayer* m_pActPlayer;
    public:
        static CGame* Obiekt(int rows, int cols, std::string name1, std::string name2);
        static void DestroyInstance();
        bool StartGame();
        bool UpdateGame();
        GAMESTATE GetGameState();
        CGameBoard* GetGameBoard() const;
};


#endif //GAME_HPP