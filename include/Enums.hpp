#ifndef ENUMS_HPP
#define ENUMS_HPP
// Deklaracja typów wyliczeniowych
enum class SIGN { CIRCLE = 'O', CROSS = 'X' };
enum class FIELD { EMPTY, CROSS = static_cast<int>(SIGN::CROSS), CIRCLE = static_cast<int>(SIGN::CIRCLE) };
enum class GAMESTATE { NOTSTARTED, MOVE, WON, DRAW };

const int LINIE[12][5][2] = { { { 0,0 }, { 0,1 }, { 0,2 },{ 0,3 }, { 0,4 }}, 
                        { { 1,0 }, { 1,1 }, { 1,2 }, { 1,3 }, { 1,4 } },
                        { { 2,0 }, { 2,1 }, { 2,2 }, { 2,3 }, { 2,4 } },
                        { { 3,0 }, { 3,1 }, { 3,2 }, { 3,3 }, { 3,4 } },
                        { { 4,0 }, { 4,1 }, { 4,2 }, { 4,3 }, { 4,4 } },
                        { { 0,0 }, { 1,0 }, { 2,0 }, { 3,0 }, { 4,0 } }, 
                        { { 0,0 }, { 1,1 }, { 2,1 }, { 3,1 }, { 4,1 } }, 
                        { { 0,0 }, { 1,2 }, { 2,2 }, { 3,2 }, { 4,2 } },
                        { { 0,0 }, { 1,3 }, { 2,3 }, { 3,3 }, { 4,3 } }, 
                        { { 0,0 }, { 1,4 }, { 2,4 }, { 3,4 }, { 4,4 } }, 
                        { { 0,0 }, { 1,1 }, { 2,2 }, { 3,3 }, { 4,4 } },
                        { { 4,0 }, { 3,1 }, { 2,2 }, { 1,2 }, { 0,2 } } };

#endif //ENUMS_HPP