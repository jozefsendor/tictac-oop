#ifndef PLAYER_HPP
#define PLAYER_HPP
#include<iostream>
#include "Enums.hpp"

class CPlayer{
    private:
        SIGN m_Sign;
        std::string m_Name;
    public:
        CPlayer(std::string name);
        ~CPlayer();
        SIGN GetSign();
        void SetSign(SIGN player_sign);
        std::string GetName();
        int MakeMove();
};
#endif //PLAYER_HPP