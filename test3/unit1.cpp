//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <cassert>
#include "Unit1.h"

using namespace std;

ostream& operator << (ostream& os, const TServerKey& k)
{
    os << k.PublicKey.c_str() << endl
       << k.Modulus.c_str() << endl
       << k.PrivateKey.c_str() << endl;
    return  os;
}
istream& operator >> (istream& is, TServerKey& k)
{
    string  strTemp;
    is >> strTemp;
    k.PublicKey = strTemp.c_str();
    is >> strTemp;
    k.Modulus = strTemp.c_str();
    is >> strTemp;
    k.PrivateKey = strTemp.c_str();
    return  is;
}

DWORD WINAPI IdleShowTime(LPVOID lpParameter)
{
	//assert (false);
	return 0;
}
DWORD WINAPI MonitorKeyEAC(LPVOID lpParameter)
{
    bool*   lpESCDown = reinterpret_cast<bool*>(lpParameter);
    char    ch;
    do
    {
        ch = getch();
    }while(ch!=27);
    *lpESCDown = true;
    return 1;
}
// ---- test MostDerived<...>  ---------------------
class Widget
{
public:
    int value_;
    Widget(int value) : value_(value) {}
    operator int ()
    {
        return  value_;
    }
    // ....
};
class ScrollBar : public Widget
{
    //...
};
class Button : public Widget
{
    // ...
};
class GraphicButton : public Button
{
    //...
};

// ---- test GenScatterHierarchy<...> -----------------
template <class T>
struct Holder
{
    T   value_;
    Holder() :value_( T(100) ) {}
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
