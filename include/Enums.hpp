#ifndef ENUMS_HPP
#define ENUMS_HPP
// Deklaracja typów wyliczeniowych
enum class SIGN { CIRCLE = 'O', CROSS = 'X' };
enum class FIELD { EMPTY, CROSS = static_cast<int>(SIGN::CROSS), CIRCLE = static_cast<int>(SIGN::CIRCLE) };
enum class GAMESTATE { NOTSTARTED, MOVE, WON, DRAW };
#endif