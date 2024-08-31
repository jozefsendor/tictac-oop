#include "Player.hpp"


CPlayer::CPlayer(std::string name){
    m_Name=name;
}
CPlayer::~CPlayer() = default;
SIGN CPlayer::GetSign(){
    return m_Sign;
}
void CPlayer::SetSign(SIGN player_sign){
    m_Sign = player_sign;
}
std::string CPlayer::GetName(){
    return m_Name;
}
int CPlayer::MakeMove(){
    int fieldNum;
    std::cout<<m_Name<<" choose the number:"<<std::endl;
    std::cin>>fieldNum;
    return fieldNum;
}