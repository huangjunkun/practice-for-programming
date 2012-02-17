//---------------------------------------------------------------------------

#ifndef _UNIT1_H_
#define _UNIT1_H_
//---------------------------------------------------------------------------
#include <Windows.h>
#include <string>
#include <iostream>

typedef struct TServerKey
{
    std::string  Modulus;
    std::string  PublicKey;
    std::string  PrivateKey;
	friend std::ostream& operator << (std::ostream& os, const TServerKey& k);
    friend std::istream& operator >> (const std::istream& is, TServerKey& k);
} TServerKey;

typedef int(*MyFun1)(int arg1,int arg2,int arg3,int arg4);
DWORD WINAPI IdleShowTime(LPVOID lpParameter);
DWORD WINAPI MonitorKeyEAC(LPVOID lpParameter);

//---------------------------------------------------------------------------

#endif
