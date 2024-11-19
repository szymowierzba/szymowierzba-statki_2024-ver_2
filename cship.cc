#include "cship.h"
cship::cship() {


}
cship::cship(int x, int y, bool hv,int l)
{
    this->x=x;
    this->y=y;
    this->hv=hv;
    this->l=l;
}

cship::~cship()
{
    // std::cout << "cship destructor" <<endl;
}
