//---------------------------------------------------------------------------
#include <strstream>
#include<sstream>
#include <iostream>
#include <vector>
#include "base64.h"

using namespace std;
//---------------------------------------------------------------------------
Byte g_base64_table[65] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                        'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
                        'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                        'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                        'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
                        '8', '9', '+', '-', '='};
//---------------------------------------------------------------------------

void EncodeStream(istream_t* pInStream, ostream_t* pOutStream, string_t Key )
{
    if(Key != "")
    {
        for(int i=0; i<Key.length()&&i<64; i++)
        {
            g_base64_table[i] = Key[i];
        }
    }
    int     Count, iI, iO;
    Byte    InBuf[45];
    char    OutBuf[63];
    Byte    Temp;
    std::fill(OutBuf, OutBuf+62, NULL);
    do
    {
        pInStream->read((char*)InBuf, sizeof(InBuf));
        Count = pInStream->gcount();
        if(Count==0)
            break;
        iI = 0;
        iO = 0;
        while(iI < Count-2)
        {
            //�����1���ֽ�
            Temp = (InBuf[iI] >> 2);
            OutBuf[iO] = char(g_base64_table[Temp&0x3f]);
            //�����2���ֽ�
            Temp = (InBuf[iI] << 4) | (InBuf[iI+1] >> 4);
            OutBuf[iO+1] = char(g_base64_table[Temp&0x3f]);
            //�����3���ֽ�
            Temp = (InBuf[iI+1] << 2) | (InBuf[iI+2] >> 6);
            OutBuf[iO+2] = char(g_base64_table[Temp&0x3f]);
            //�����4���ֽ�
            Temp = (InBuf[iI+2] & 0x3f);
            OutBuf[iO+3] = char(g_base64_table[Temp]);
            iI += 3;
            iO += 4;
        }
        if(iI <= Count-1)
        {
            //ShowMessage(String(InBuf[I]) );
            Temp = (InBuf[iI] >> 2 );
            //ShowMessage(String(Temp) );
            OutBuf[iO] = char(g_base64_table[Temp&0x3f] );
            if(iI==Count-1)
            {
                //һ�������ֽ�
                Temp = (InBuf[iI] << 4)& 0x30;
                OutBuf[iO+1] = char(g_base64_table[Temp&0x3f] );
                OutBuf[iO+2] = '=';
            }
            else //I==Count-2
            {
                //���������ֽ�
                Temp = ((InBuf[iI] << 4)& 0x30) | ((InBuf[iI+1] >> 4)& 0x0f);
                OutBuf[iO+1] = char(g_base64_table[Temp&0x3f] );
                Temp = (InBuf[iI+1] << 2) & 0x3c;
                OutBuf[iO+2] = char(g_base64_table[Temp&0x3f] );
            }
            OutBuf[iO+3] = '=';
            iO += 4;
        }
        pOutStream->write(OutBuf, iO);
    }
    while(!(Count < sizeof(InBuf)) );
}
//---------------------------------------------------------------------------
Byte SearchBase64Table(const Byte&   b)
{
    for(Byte i=0; i < 65; ++i)
    {
        if(g_base64_table[i]==b)
            return i;
    }
    return Byte(255);
}
//---------------------------------------------------------------------------
void DecodeStream(istream_t* pInStream, ostream_t* pOutStream, string_t Key )
{

    if(Key!="")
    {
        for(int i=0; i < Key.length()&& i<64; ++i)
        {
            g_base64_table[i] = Key[i];
        }
    }
    int     Count, iI, iO ;  //, c1, c2, c3
    Byte     c1, c2, c3;  //
    Byte    InBuf[88];
    Byte    OutBuf[66];
    Byte    Temp;
    do
    {
        pInStream->read((char*)InBuf, sizeof(InBuf));
        Count = pInStream->gcount();
        if(Count==0)
            break;
        iI = 0;
        iO = 0;
        while(iI<Count)
        {
            c1 = SearchBase64Table(InBuf[iI]);
            c2 = SearchBase64Table(InBuf[iI+1]);
            c3 = SearchBase64Table(InBuf[iI+2]);
            if( c1==Byte(255)||c2==Byte(255)||c3==Byte(255))
            {
                string_t errStr = "�Ƿ��ַ� ��������ֹ��";
                pOutStream->write(errStr.c_str(), errStr.length());
                return;   //throw; //???
            }
            OutBuf[iO] = ((c1<<2)|(c2>>4));
            iO++;
            if(char(InBuf[iI+2]!='=') )
            {
                OutBuf[iO] = ((c2<<4)|(c3>>2));
                iO++;
                if(char(InBuf[iI+3]!='='))
                {
                    OutBuf[iO] = ((c3<<6)|SearchBase64Table(InBuf[iI+3]));
                    iO++;
                }
            }
            iI += 4;
        }

        pOutStream->write((char*)OutBuf, iO);
    }
    while(!(Count < sizeof(InBuf)));

}
//---------------------------------------------------------------------------
string_t Base64Encryption(const string_t& InputStr)
{

    istringstream_t   inStream(InputStr);
    ostringstream_t   outStream;
    EncodeStream(&inStream, &outStream);

    return outStream.str();
}
//---------------------------------------------------------------------------
string_t Base64Decryption(const string_t& InputStr)
{
    istringstream_t   inStream(InputStr);
    ostringstream_t   outStream;
    DecodeStream(&inStream, &outStream);

    return outStream.str();
}
//---------------------------------------------------------------------------
string_t MakeRandomKey()
{
    /*
      time_t  t;
      srand((unsigned int)time(&t) );     */
    vector<MyChar>  mychar_vec(256);
    for(int i=0; i<256; i++)
    {
        mychar_vec[i].ch = (char)i;
        mychar_vec[i].used = false;
    }
    string_t Key;
    Key.resize(64);
    int     index = 0;
    while( index <64 )
    {
        int     i = rand()%256;
        if(mychar_vec[i].used==false)
        {
            Key[index++] = mychar_vec[i].ch;
            mychar_vec[i].used = true;
        }
    }
    return Key;
}
//---------------------------------------------------------------------------


