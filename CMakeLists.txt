# Minimalna wersja CMake
cmake_minimum_required(VERSION 3.10)

# Nazwa projektu
project(GameProject VERSION 1.0)

# Ustaw standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dodaj katalogi z nagłówkami
include_directories(include)

# Pliki źródłowe
set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/GameBoard.cpp
    src/Player.cpp
)

# Utwórz plik wykonywalny
add_executable(game ${SOURCES})
