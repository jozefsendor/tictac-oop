#include "Game.hpp"

CGame* CGame::ms_pGame = nullptr;

CGame::CGame(int rows, int cols){
    m_pGBoard = new CGameBoard(rows, cols);
    m_pPlayer1 = new CPlayer();
    m_pPlayer2 = new CPlayer();
}

CGame::~CGame(){
    delete m_pGBoard;
    delete m_pPlayer1;
    delete m_pPlayer2;
}
CGame* CGame::Obiekt(int rows, int cols){
    if(ms_pGame == nullptr){
        ms_pGame = new CGame(rows, cols);
    }
    return ms_pGame;
}

void CGame::DestroyInstance(){
    delete ms_pGame;
    ms_pGame=nullptr;
}
