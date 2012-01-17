//---------------------------------------------------------------------------

#ifndef SUB_UNIT_H_INCLUDE
#define SUB_UNIT_H_INCLUDE
//---------------------------------------------------------------------------
// ------------ 头文件包含 --------------------------
#include <iostream>
#include <iomanip>
#include <complex>
#include <assert.h>
#include <vector>
#include <iterator>
#include <stack>
#include <exception>

/*
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <functional>
#include <algorithm>
#include <fstream>
#include <typeinfo>
#include <windows.h>   */

using namespace std;
//---------------------------------------------------------------------------
// ------------ 函数声明 --------------------------
//字符串的全排列
void	Permute(const string& str);
//字符串的全组合
void	Combine(const string& str);
// --- 拷贝字符串 ----
char*   Strcpy(char* dest, char* source);
// --- 循环移动字符串 ----
char*   loopMoveStr(char* str, int steps);
char*   loopMoveStr_(char* str, int steps);
char*   strRotate(char* str, int steps);//call stl
// --- 查找一个字符串中连续出现次数最多的子串--
pair<int,string> find_most_substr(const string& str);
// --- 模拟实现C++ 函数strstr(...)
const char* strStr(const char* str, const char* substr);
char* strStr(char* str, const char* substr);

//---------------------------------------------------------------------------
namespace testDataStruct
{
// 用两个栈实现一个队列功能 ...C++
template <typename T>
class Queue
{
private:
    stack<int> in, out;
public:
    void push(const T& t)
    {
        in.push(t);
    }
    T front()
    {
        if(out.empty())
        {
//                if(in.empty())
//                    throw std::runtime_error(" in.empty(), error" );
            assert (!in.empty());
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    void pop()
    {
        if(out.empty())
        {
            /*
            if(in.empty())
                throw runtime_error(" in.empty(), error" );  */
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        return out.pop();
    }
    std::size_t size()
    {
        return in.size()+out.size();
    }
};
}
// ------------ 类型声明、定义 --------------------------
typedef struct  student
{
    int     id;
    char    name[20];
    double  value;
} student;
namespace testConst
{
class C
{
private:
    // mutable 修饰的成员变量，即使const修饰的成员函数也可以改变它
    mutable int iCount;
public:
    C(int i) : iCount(i) {}
    int incr() const
    {
        return  ++iCount;
    }
    int decr() const
    {
        return --iCount;
    }
};
}//namespace testConst
namespace testSizeof
{
/*
 void    sizeofFuncParam(char str[], char*  pStr)
 {
     cout << " sizeof(str): " << sizeof(str) << "\n";
     cout << " sizeof(pStr): " << sizeof(pStr) << "\n";
 }    */
struct  sizeofFuncParam
{
    void    operator() (char str[], char*  pStr)
    {
        cout << " sizeof(str): " << sizeof(str) << "\n";
        cout << " sizeof(pStr): " << sizeof(pStr) << "\n";
    }
};
struct A
{
    short a1;
    short a2;
    short a3;
};
struct B
{
    long  a1;
    short a2;
};
class   Empty1
{ };
class   Empty2
{ };
class   Derive1 : public Empty1
{ };
class   Derive2 : public virtual B
{ };
class   Derive3 : public Empty1, Empty2
{ };
class   Base
{
private:
    int value;
public:
    Base()
    {
        cout << " Base--ctor \n";
    }
    virtual ~Base()
    {
        cout << " ~Base--dtor\n";    //virtual ...
    }
    virtual void f(int)
    {
        cout << " Base::f(int)\n";
    }
    virtual void f(double)
    {
        cout << " Base::f(double)\n";
    }
    virtual void g(int i=10)
    {
        cout << " Base::g(int i) i = " << i << "\n";
    }
    void g_(int i=10)
    {
        cout << " Base::g_(int i) i = " << i << "\n";
    }
};
class   Derived : public Base
{
public:
    Derived()
    {
        cout << " Derived--ctor \n";
    }
    virtual ~Derived()
    {
        cout << " ~Derived--dtor\n";    //virtual ...
    }
    void f(int)
    {
        cout << " Derived::f(int)\n";
    }
    void f(double)
    {
        cout << " Derived::f(double)\n";
    }
    void f(complex<double>)
    {
        cout << " Derived::f(complex<double>)\n";
    }
    // [C++ Warning] W8022 'Derived::f(complex<double>)' hides virtual function 'Base::f(int)'
    virtual void g(int i=20)
    {
        cout << " Derived::g(int i) i = " << i << "\n";
    }
};
class C1
{
private:
    bool    bValue1;
    int     iValue;
    bool    bValue2;
};
class C2
{
private:
    int     iValue;
    bool    bValue1;
    bool    bValue2;
};
#pragma pack(1)//pack与处理指令禁止编译时的对齐调整
class C3
{
private:
    bool    bValue1;
    int     iValue;
    bool    bValue2;
};
#pragma pack()
}// namespace testSizeof
// ---- 传递动态指针 ----
void    GetMemoryPtr(char**p, int num);
void    GetMemoryRef(char*  &p, int num);
namespace testPtrRef
{

}
// ----------位运算 ---------------------;
#define BIT_MASK(bit_pos) (0x01<<(bit_pos))
int Bit_Reset(unsigned int* val, unsigned char pos);
// 十进制=八进制/10*8+八进制%10 ；
unsigned int oct2dec(unsigned int oct);

#define BIT3 (0x1 << 3)
void    SetBit3(int& a);
void    ClearBit3(int& a);
namespace testBitOper
{

union U
{
    unsigned char uc;
    unsigned int  ui;
};
}

// ---- 循环、递归与概率 ----
/*
f(m,n)  = n     (m=1)
        = m     (n=1)
        = f(m-1,n)+f(m,n-1) (m>1,n>1)
*/
// --- 递归 ----
int f1(int m, int n);
// --- 非递归 ----
int f2(int m, int n);
//" ----------螺旋队列问题 ---------------------\n";
#define MAX(a,b) ( (a)<(b)?(b):(a))
#define abs(a) ((a)>0 ? (a):-(a))
int Foo(int x, int y);

// --- test 虚函数与构造函数之间的关系 不同返回值的虚函数-----
namespace testVirFunCtor
{
// 虚函数在构造函数中没有多态表现 ，不同返回值的虚函数
class   A
{
public:
    inline A()
    {
        fun();    // inline ok
    }
    virtual void fun() const
    {
        cout << " A::fun()\n";
    }
    virtual const A&   virFun(int i= 0)
    {
        cout << " A::virFun(int)\n";
        return *this;
    }
    inline ~A() { } // inline ok
};
class   B : public A
{
public:
    B()
    {
        fun();
    }
    virtual void fun() const
    {
        cout << " B::fun()\n";
    }
    virtual const B&   virFun(int i= 0)
    {
        cout << " B::virFun(int)\n";
        return *this;
    }
};
class   C : public B
{
public:
    C()
    {
        fun();
    }
    virtual void fun() const
    {
        cout << " C::fun()\n";
    }
    virtual const C&   virFun(int i= 0)
    {
        cout << " C::virFun(int)\n";
        return *this;
    }
};
class   D : public C
{
public:
    D()
    {
        fun();
    }
    virtual void fun() const
    {
        cout << " D::fun()\n";
    }
    virtual const D&   virFun(int i= 0)
    {
        cout << " D::virFun(int)\n";
        return *this;
    }
};
}
// --- test 构造类的过程，初始化列表的初始化变量顺序 ----
// --- 是根据成员的声明次序来决定的 -----
namespace testInitMemOrder
{
class A
{
private:
    int iM;
    int iN;
public:
    A() : iM(0), iN(iM) {}
    A(int i) : iM(i), iN(iM) {}
    void printA()
    {
        cout << " A : iM = "<<iM << ", iN = " << iN << "\n";
    }
};
class B
{
private:
    int iN; // 顺序相反 ....
//warning: 'testInitMemOrder::B::iM' will be initialized after|
    int iM;
public:
    B() : iM(0), iN(iM) {}
    B(int i) : iM(i), iN(iM) {}
    void printB()
    {
        cout << " B : iM = "<<iM << ", iN = " << iN << "\n";
    }
};
class   C
{
private:
    int iValue;
public:
    C():iValue(0)
    {
        cout << " C() constructoriValue = " << iValue <<"\n";
    }
    C(int i):iValue(i)
    {
        cout << " C(int i) constructor iValue = " << iValue <<"\n";
    }
    C(const C& c)
    {
        cout << " C(const C& c) constructor iValue = " << c.iValue <<"\n";
        iValue = c.iValue;
    }
    ~C()
    {
        cout << " ~C() destructed iValue = " << iValue <<"\n";
    }
    C&  operator = (const C& c)
    {
        cout << " C&  operator = (C& c) iValue = " << c.iValue <<"\n";
        iValue = c.iValue;
        return  *this;
    }
};    /*
    C   play(C c)
    {
        return c;
    }   */
struct  Play
{
    C   operator() (C c)
    {
        return c;
    }
};
}
// --- test 友元函数 ，模板类 ----- !!!!
namespace testFriMemTemplateClass
{
template <class T>
class Test
{
    //private:
public:
    T value;
public:
    Test() : value(T(0)) {}
    Test(const T& t) : value(t) { }
    template <class U> //...
    friend ostream& operator << (ostream& os, const Test& t);
    //friend ostream& operator << <> (ostream& os, const Test<T>& t);// ????
};
template <class T>
ostream& operator << (ostream& os, const Test<T>& t)
{
    os << " Test: value = " << t.value << "\n";
    return os;
}
}
namespace testBaiduStudy
{
/*对任意输入的正整数N，编写C程序求N!的尾部连续0的个数，
并指出计算复杂度。如：18！＝6402373705728000，尾部连续0的个数是3。
（不用考虑数值超出计算机整数界限的问题）
*/
__int64 Factorial(int n);
int FactorialCount0Num_1(int n);
int FactorialCount0Num_2(int n);
/*
template <typename T, class Comp>
T SearchNMax(T* first, T* last, std::size_t n, Comp comp=less<int>)
{
    if(n<1||distance(first, last)<n)
        throw -1; // error
    std::size_t index;
    T   *low=first, *high=last-1;
    for(;;)
    {
        T   temp = *low;
        while(low<high)
        {
            while(low<high&&!comp(*high, temp) )
                high--;
            *low = *high;
            while(low<high&&comp(*low, temp) )
                low++;
            *high = *low;
        }
        *low = temp;
        index = distance(first, low)+1;
        if(index==n)
            break;
        else if(index>n)
        {
        }
        else //(index<n)
        {
        }
    }
}     */
template <class T>
struct	TypeTrait
{
    typedef	T	NoPtrResult;
};
template <class T>
struct TypeTrait<T*>
{
    typedef	T	NoPtrResult;
};
template <typename T,
class Comp >  //=less<T>
T   partition(T first, T last, Comp comp) //
{
    typename TypeTrait<T>::NoPtrResult temp = *first;
    --last;
    while(first<last)
    {
        while(first<last&&!comp(*last, temp) )
            last--;
        *first = *last;
        while(first<last&&comp(*first, temp) )
            first++;
        *last = *first;
    }
    *first = temp;
    return  first;
}
template <typename T, class Comp >  //=less<T>
T SearchNMax(T first, T last, std::size_t n, Comp comp) //
{
    if(first<last)
    {
        T   pos = partition(first, last, comp);
        std::size_t index = distance(first, pos)+1;
        if(index==n)
            return pos;
        else if(index>n)
            return SearchNMax(first, pos, n, comp);
        else //index<n
            return SearchNMax(pos+1, last, n-index, comp);
    }
    else
        return last;//error
}
}
namespace testString
{
// --查找一个字符串中连续出现次数最多的子串--
//    pair<int,string> fun(const string& str);// Complier error
}

//---------------------------------------------------------------------------

#endif// SUB_UNIT_H_INCLUDE
