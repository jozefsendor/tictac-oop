#include "GameBoard.hpp"

CGameBoard::CGameBoard(int rows, int cols) : m_rows(rows), m_cols(cols){
    m_board = new FIELD*[m_rows];
    for(int i=0;i<m_rows;i++){
        m_board[i] = new FIELD[m_cols];
        std::fill(m_board[i], m_board[i]+m_cols,FIELD::EMPTY);
    }
}
CGameBoard::~CGameBoard(){
    for(int i=0;i<m_rows;i++){
        delete[] m_board[i];
    }
    delete[] m_board;
}