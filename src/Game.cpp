#include "Game.hpp"

CGame *CGame::ms_pGame = nullptr;

CGame::CGame(int rows, int cols, std::string name1, std::string name2)
{
    m_pGBoard = new CGameBoard(rows, cols, this);
    m_pPlayer1 = new CPlayer(name1);
    m_pPlayer2 = new CPlayer(name2);
    m_GameState = GAMESTATE::NOTSTARTED;
}
CGame::~CGame()
{
    delete m_pGBoard;
    delete m_pPlayer1;
    delete m_pPlayer2;
}
CGame *CGame::Obiekt(int rows, int cols, std::string name1, std::string name2)
{
    if (ms_pGame == nullptr)
    {
        ms_pGame = new CGame(rows, cols, name1, name2);
    }
    return ms_pGame;
}

void CGame::DestroyInstance()
{
    delete ms_pGame;
    ms_pGame = nullptr;
}
GAMESTATE CGame::GetGameState()
{
    return m_GameState;
}
bool CGame::StartGame()
{
    if (m_GameState != GAMESTATE::NOTSTARTED)
    {
        return false;
    }
    srand(static_cast<unsigned int>(time(NULL)));
    m_pPlayer1->SetSign(rand() % 2 == 0 ? SIGN::CIRCLE : SIGN::CROSS);
    m_pPlayer2->SetSign(m_pPlayer1->GetSign() == SIGN::CROSS ? SIGN::CIRCLE : SIGN::CROSS);
    std::cout << m_pPlayer1->GetName() << " your sign is: " << static_cast<char>(m_pPlayer1->GetSign()) << std::endl;
    std::cout << m_pPlayer2->GetName() << " your sign is: " << static_cast<char>(m_pPlayer2->GetSign()) << std::endl;
    std::cout << "Player with sign \"0\" starts" << std::endl;

    std::cout << "Press ENTER to start the game...";
    std::cin.ignore();
    std::cin.get();
    std::cout << "Game started!" << std::endl;

    m_pPlayer1->GetSign() == SIGN::CIRCLE ? m_pActPlayer = m_pPlayer1 : m_pActPlayer = m_pPlayer2;
    m_GameState = GAMESTATE::MOVE;
    return true;
}
CGameBoard *CGame::GetGameBoard() const
{
    return m_pGBoard;
}
bool CGame::UpdateGame()
{
    if (m_GameState != GAMESTATE::MOVE)
    {
        return false;
    }
    if (!m_pGBoard->UpdateBoard(m_pActPlayer->MakeMove(), m_pActPlayer->GetSign()))
    {
        return false;
    }

    for (int i = 0; i <= m_pGBoard->GetRows() - 5; i++)
    {

        for (int j = 0; j <= m_pGBoard->GetCols() - 5; j++)
        {

            for (int k = 0; k < 12; k++)
            {
                int counter = 0;

                for (int l = 0; l < 5; l++)
                {
                    int row = LINIE[k][l][0] + i;
                    int col = LINIE[k][l][1] + j;

                    if (m_pGBoard->GetField(row, col) == static_cast<FIELD>(m_pActPlayer->GetSign()))
                    {
                        counter++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (counter == 5)
                {
                    m_GameState = GAMESTATE::WON;
                    std::cout << m_pActPlayer->GetName() << " won. Congrats!" << std::endl;
                    return true;
                }
            }
        }
    }
    int emptyFields = 0;
    for (int i = 0; i < m_pGBoard->GetRows(); i++)
    {
        for (int j = 0; j < m_pGBoard->GetCols(); j++)
        {
            if (m_pGBoard->GetField(i, j) == FIELD::EMPTY)
            {
                emptyFields++;
            }
        }
    }
    if (emptyFields == 0 && m_GameState != GAMESTATE::WON)
    {
        m_GameState = GAMESTATE::DRAW;
        std::cout << "There is a draw!" << std::endl;
        return true;
    }

    // Zmiana aktywnego gracza
    m_pActPlayer = (m_pActPlayer == m_pPlayer1 ? m_pPlayer2 : m_pPlayer1);
    return true;
}