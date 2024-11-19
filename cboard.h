#ifndef cboard_H
#define cboard_H
#include "cship.h"
#include <iostream>
#include <string>
using namespace std;

class cboard 
{
private:
    
public:

    char board[11][11];
    
    cboard();
    cship m4, m31, m32, m21, m22, m23, m11, m12, m13, m14;
    void showboard();
    void create_ship(int cl);
    void addship();
    char change_int_to_char(int nu1);
    int change_char_to_int(char ch);
    bool check_char(char z);
    bool check_ship_collision(int x, int y, bool hv, int l);
  
    ~cboard();
};
#endif
