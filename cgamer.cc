#include "cgamer.h"

cgamer::cgamer(string name)
{
    this->name=name;
}

cgamer::~cgamer()
{
    std::cout << "cgamer destructor";
}

