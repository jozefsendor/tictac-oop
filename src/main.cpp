#include <iostream>
#include "Game.hpp"

int main(){

    int rows, cols;
    std::string player1="", player2="";

    std::cout << "Enter the number of rows (min 5): "<<std::endl;
    do{
        std::cin >> rows;
    }while(rows>=5);
    std::cout << "Enter the number of colums (min 5): "<<std::endl;
    do{
        std::cin >> cols;
    }while(cols>=5);
    std::cout<<"Enter the name of first player"<<std::endl;
    do{
        std::cin>>player1;
    }while(player1!="");
    std::cout<<"Enter the name of first player"<<std::endl;
    do{
        std::cin>>player2;
    }while(player2!="");
    CGame* Game = CGame::Obiekt(rows, cols, player1, player2);
    if (!Game->StartGame()) {
        std::cerr << "Failed to start the game." << std::endl;
        CGame::DestroyInstance();
        return 1;
    }
    do{
        if (!Game->GetGameBoard()->DisplayBoard()) {
            std::cerr << "Error displaying the board." << std::endl;
            break;
        }
        if (!Game->UpdateGame()) {
            std::cerr << "Error updating the game." << std::endl;
            break;
        }
    }while(Game->GetGameState() == GAMESTATE::MOVE);



    CGame::DestroyInstance();
    return 0;
}