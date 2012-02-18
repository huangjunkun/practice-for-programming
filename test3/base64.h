//---------------------------------------------------------------------------

#ifndef Base64H
#define Base64H
//---------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <string>
#include <strstream>
#include<sstream>
using namespace std;

typedef std::string string_t;
typedef std::istream istream_t;
typedef std::ostream ostream_t;
typedef std::istringstream istringstream_t;
typedef std::ostringstream ostringstream_t;

typedef unsigned char Byte;

//---------------------------------------------------------------------------
typedef struct MyChar
{
    char    ch;
    bool    used;
}   MyChar;

//---------------------------------------------------------------------------
void EncodeStream(istream_t* pInStream, ostream_t* pOutStream, string_t Key="");
Byte     SearchBase64Table(const Byte& b);
void DecodeStream(istream_t* pInStream, ostream_t *pOutStream, string_t Key="");
string_t  Base64Encryption(const string_t& InputStr);
string_t  Base64Decryption(const string_t& InputStr);
string_t  MakeRandomKey();

#endif
