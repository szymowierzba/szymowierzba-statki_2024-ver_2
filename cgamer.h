#ifndef cgamer_H
#define cgamer_H
#include "cship.h"
#include "cboard.h"
#include <iostream>
#include <string>
using namespace std;

class cgamer
{
private:
    
public:
    string name;
    cboard my_board;
    cboard alien_board;
    cgamer(string name);
    ~cgamer();
};



#endif