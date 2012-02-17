

#ifndef _UNIT1_H_
#define _UNIT1_H_

#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

namespace MySpace
{
class MyString
{
public:
    MyString();
    MyString(const char *s);
    //拷贝构造函数
    MyString(const MyString& Str);
    ~MyString();
    char* Getstr() const;
    friend MyString MyStrCat( const MyString& str1,  const MyString& str2);
    friend ostream& operator << (ostream&  outs, const MyString& Str);
    MyString operator += (const MyString& Str);
    friend MyString operator + (const MyString& Str1,const MyString& Str2);
    friend bool operator == (const MyString& Str1,const MyString& Str2);
    friend bool operator != (const MyString& Str1,const MyString& Str2);
    MyString& operator = (const MyString& Str);
    virtual	void Print1()
    {
        cout << "MyString virtual	void Print1() : "<< str <<endl;
    }
    void Print2();
    void Print3(int i );//（信息）函数隐藏
    int GetObjectNum();
    static void SetObjectNum(int num)
    {
        ObjectNum = num;
    }
    const char* Ptr() const
    {
        return str;
    }
    int Length() const
    {
        return length;
    }
protected:
    char*		str;
    int		length;
private:
    static int ObjectNum;
public:
    static const int    MAXNUM = 10;
};
//---------------------------------------------------------------------------
int MyString::ObjectNum = 0 ;    //VC --OK
//---------------------------------------------------------------------------
class	String : public MyString
{
public:
    String()
        :MyString()
    {
    }
    String(const MyString& mystr)//:MyString(mystr), length(strlen(mystr.Getstr()))
    {
        /**/
        length = mystr.Length();
        str = new char[length+1];
        strcpy(str, mystr.Getstr());
    }
    String(const String& Str)
    {
        length = Str.Length();
        str = new char[length+1 ];
        strcpy(str, Str.str);
    }
    String(const char *s)
        : MyString(s) //调用基类函数
    {}

    ~String()
    {
    }

    friend ostream& operator << (ostream&  outs, const String& Str)
    {
        outs << "Length: " << Str.length << ", " << Str.str << endl;
        return outs;
    }
    virtual	void Print1() //覆盖
    {
        cout << "String virtual	void Print1(): "<< str << endl;
    }
    void Print2()//重定义
    {
        cout << "String 	void Print2() : "<< str <<endl;
    }
    void Print3(int i)//重载
    {
        cout << "String void Print3(int i) : "<< str <<endl;
    }
    void Print3(double d)//重载
    {
        cout << "String void Print3(double d) : "<< str <<endl;
    }
};
//---------------------------------------------------------------------------
class	Base1
{
protected:
    int iBase;
public:
    void Print()
    {
        cout << " I am Base1 : iBase1 = " << iBase << endl;
    }
};
class	Base2
{
protected:
    int iBase;
public:
    void Print()
    {
        cout << " I am Base2 : iBase2 = " << iBase << endl;
    }
};
//---------------------------------------------------------------------------
class	Derive : public	Base1, Base2
{
public:
    void SetiBase(int iNew, int index)
    {
        switch(index)
        {
        case 1 :
            Base1::iBase = iNew;
            break;
        case 2 :
            Base2::iBase = iNew;
            break;
        default:
            break;
        }
    }
    void Print()
    {
        cout << " I am Base1 : iBase1 = " << Base1::iBase << endl;
        cout << " I am Base2 : iBase2 = " << Base2::iBase << endl;
    }

};
//---------------------------------------------------------------------------
MyString::MyString()
    : str(0), length(0)
{
    ObjectNum++;
}
MyString::MyString(const char *s)
{
    if(s)
    {
        length = strlen(s);
        str = new char[length+1];
        assert (str);
        strcpy(str, s);
    }
    else
    {
        length = 0;
        str = new char[length+1];
        str[0] = '\0';
    }
    ObjectNum++;
}
//拷贝构造函数
MyString::MyString(const MyString& MSstr)
{
    length = MSstr.Length();
    str = new char[length + 1];
    strcpy(str, MSstr.str);
    ObjectNum++;
}

MyString::~MyString()
{
    delete[] str;
}
char* MyString::Getstr() const
{
    return str;
}
MyString MyStrCat( const MyString& MSstr1,  const MyString& MSstr2)  //friend
{
    int length = strlen(MSstr1.str)+strlen(MSstr2.str);
    cout << "length:" << length <<endl;
    char *str = new char[length+1];
    assert (str);
    strcpy(str, MSstr1.str);
    strcat(str, MSstr2.str);
    MyString MSstr;
    MSstr.str = str;
    MSstr.length = length;
    return MSstr;
}
ostream& operator << (ostream&  outs, const MyString& MSstr) // friend
{
    outs << MSstr.str <<endl;
    return outs;
}/**/
MyString MyString::operator += (const MyString& MSstr)
{
    *this = MyStrCat(*this, MSstr);
    return  *this;
}
MyString operator + (const MyString& MSstr1,const MyString& MSstr2)  // friend
{
    return MyString(MyStrCat(MSstr1, MSstr2));
}
bool operator == (const MyString& MSstr1,const MyString& MSstr2)//friend
{
    //return Str1.str==Str2.str;
    if(strcmp(MSstr1.str,MSstr2.str)==0)
        return true;
    else
        return false;
}
bool operator != (const MyString& MSstr1,const MyString& MSstr2)//friend
{
    return    !(operator == ( MSstr1,MSstr2));
}

MyString& MyString::operator = (const MyString& MSstr)
{

    if(&MSstr != this)
    {
        if(MSstr.Length() > Length()) //!!!
        {
            if(str!=NULL)
                delete[] str;
            str = new char[MSstr.Length()+1];
        }
        strcpy(str, MSstr.str);
        length = MSstr.Length();
    }
    return *this;
} /*
    virtual	void MyString::Print1()
    {
        cout << "MyString virtual	void Print1() : "<< str <<endl;
    }   */
void MyString::Print2()//
{
    cout << "MyString 	void Print2() : "<< str <<endl;
}
void MyString::Print3(int i )//（信息）函数隐藏
{
    cout << "MyString  void Print3(int i) : "<< str <<endl;
}
int MyString::GetObjectNum()
{
    return  ObjectNum;
}
//---------------------------------------------------------------------------
class   D1
{
public:
    virtual void foo()
    {
        cout << " D1 :: virtual void foo() \n ";
    }
    D1() {};
};
class   D2
{
public:
    virtual void bar()
    {
        cout << " D2 :: virtual void bar() \n ";
    }
    D2() {};
};
class   MI1 : public D1, public D2 // or private D2 // a problem to test...
{
    //
    virtual void foo()
    {
        cout << " MI1 :: virtual void foo() \n ";
    }
    virtual void bar()
    {
        cout << " MI1 :: virtual void bar() \n ";
    }
};
class   MI2 : public MI1
{
    //
    virtual void foo()
    {
        cout << " MI2 :: virtual void foo() \n ";
    }
    virtual void bar()
    {
        cout << " MI2 :: virtual void bar() \n ";
    }
};
//测试C++ 中新定义的关键字 typeid 和 dynamic_cast
//---------------------------------------------------------------------------
} //MySpace ---
using namespace MySpace;
MyString	TestCopyConstructor(const MyString& MSstr1, const MyString& MSstr2)
{
    return MSstr1+MSstr2;
}
//---------------------------------------------------------------------------

#endif //_UNIT2_H_