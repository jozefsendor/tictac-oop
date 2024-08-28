#include <iostream>
#include "Game.hpp"

int main(){

    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of colums: ";
    std::cin >> cols;
    
    CGame* Game = CGame::Obiekt(rows, cols);


    std::cout<<"GIT GIT"<<std::endl;
    std::cin.get();
    CGame::DestroyInstance();
    return 0;
}