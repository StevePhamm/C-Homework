#include <iostream>
using namespace std;
class Y;

class X
{
    Y *y; 
};

class Y
{
    X x;
};

