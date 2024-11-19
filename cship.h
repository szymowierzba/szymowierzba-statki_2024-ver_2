#ifndef cship_H
#define cship_H
#include <iostream>
#include <string>
using namespace std;

class cship
{
private:
    
public:
    int x,y,l;   
    bool hv;
    int state_ship;

    cship();
    cship(int x, int y, bool hv,int l);
    ~cship();
};




#endif