#include <bitset>
#ifndef HANDLER_H
#define HANDLER_H

// Include needed standard library functions (STL)

// The <signature> function  declaration
bool circuit01(bool a, bool b);
bool circuit02(bool a, bool b, bool c);
bool circuit03(bool a, bool b, bool c);
std::bitset<8> bitEval01(std::bitset<8> a, std::bitset<8> b, std::bitset<8> c);
std::bitset<4> bitEval02(std::bitset<4> a, std::bitset<4> b);

#endif // HANDLER_H
