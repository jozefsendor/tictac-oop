#include "GameBoard.hpp"
#include "Game.hpp"

CGameBoard::CGameBoard(int rows, int cols, CGame *game) : m_Rows(rows), m_Cols(cols), m_pGame(game)
{
    m_pBoard = new FIELD *[m_Rows];
    for (int i = 0; i < m_Rows; i++)
    {
        m_pBoard[i] = new FIELD[m_Cols];
        std::fill(m_pBoard[i], m_pBoard[i] + m_Cols, FIELD::EMPTY);
    }
}
CGameBoard::~CGameBoard()
{
    for (int i = 0; i < m_Rows; i++)
    {
        delete[] m_pBoard[i];
    }
    delete[] m_pBoard;
}
bool CGameBoard::DisplayBoard() const
{
    if (m_pGame->GetGameState() == GAMESTATE::NOTSTARTED)
    {
        return false;
    }

    system("clear");
    std::cout << "Actual game state:" << std::endl;

    for (int i = 0; i < m_Rows; i++)
    {
        for (int j = 0; j < m_Cols; j++)
        {
            if (m_pBoard[i][j] == FIELD::EMPTY)
            {
                std::cout << std::setw(2) << (i * m_Cols + j + 1);
            }
            else
            {
                std::cout << std::setw(2) << static_cast<char>(m_pBoard[i][j]);
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    return true;
}
int CGameBoard::GetCols()
{
    return m_Cols;
}
int CGameBoard::GetRows()
{
    return m_Rows;
}
bool CGameBoard::UpdateBoard(int fieldNum, SIGN playerSign)
{
    int row = (fieldNum - 1) / m_Cols;
    int cols = (fieldNum - 1) % m_Cols;

    if (row < 0 || row >= m_Rows || cols < 0 || cols >= m_Cols)
    {
        return false;
    }
    if (m_pBoard[row][cols] != FIELD::EMPTY)
    {
        return false;
    }
    m_pBoard[row][cols] = static_cast<FIELD>(playerSign);
    return true;
}
FIELD CGameBoard::GetField(int rows, int cols)
{
    return m_pBoard[rows][cols];
}