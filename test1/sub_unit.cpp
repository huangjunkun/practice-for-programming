//---------------------------------------------------------------------------
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include "sub_unit.h"

using namespace std;
//---------------------------------------------------------------------------
int calc_value_hex2uint(char ch)
{
    if ('0' <= ch && '9' >= ch)
        return (ch - '0');
    else if ('a' <= ch && 'f' >= ch)
        return (ch - 'a') + 10;
    else if ('A' <= ch && 'F' >= ch)
        return (ch - 'A') + 10;

    return -1;
}

bool hex2uint(const char* str, unsigned int& res)
{
    if (!(NULL != str && '0' == *str))
        return false;
    const char* next = str;
    ++next;
    if (!(NULL != next && 'x' == *next))
        return false;
    unsigned int count = 0;
    ++next;
    while ('\0' != *next)
    {
        int value = calc_value_hex2uint(*next);
        if (-1 == value)
            return false;
        count *= 16;
        count += value;
        ++next;
    }
    //cout << count << "\n";
    res = count;
    return true;
}

void select_diff_set(vector<char>& all, vector<char>& part, vector<char>& diff_set)
{
    assert (all.size() >= part.size());
    char mark[256] = {0};
    memset(mark, 0, sizeof(mark));

    for (size_t i =0; i < all.size(); ++i)
        mark[(unsigned)all[i]] = 1;
    for (size_t i =0; i < part.size(); ++i)
        mark[(unsigned)part[i]] = 2;

    for (size_t i =0; i < sizeof(mark); ++i)
        if (1 == mark[i])
            diff_set.push_back(i);
    return;
}

void preorder_traversal(treeT* tree)
{
    if (NULL == tree)
        return;

    stack<treeT*> back_s;
    back_s.push(tree);
    while (!back_s.empty())
    {
        if (tree->left)
        {
            back_s.push(tree->left);
            tree = tree->left;
        }
        else
        {
            printf("[key] %d", tree->key);
            tree = back_s.top();
            back_s.pop();
            if (tree->right)
                back_s.push(tree->right);
        }
    }
}


//字符串的全排列
void	DoPermute(const string& in, string& out, bool used[], unsigned int level)
{
    if(level==in.length() )
    {
        //cout << level <<endl;
        cout << out <<"\n" ;// result
        return;
    }
    for(unsigned int i=0; i<in.length(); i++)
    {
        if(used[i]==true)
            continue;
        //else
        out.append(in, i, 1);// !!!!!!!!!!
        used[i] = true;
        DoPermute(in, out, used, level+1);
        used[i] = false;
        out.erase(out.end()-1);
        //out = out.substr(0, out.size()-1); //or
        //system("pause");
    }
}
void	Permute(const string&	str)
{
    bool	*used = new bool[str.length()];
	assert (used);
    for(unsigned int i=0; i<str.length(); i++)
        used[i] = false;
    string	out = "";
    DoPermute(str, out, used, 0);
	delete[] used;
}

//---------------------------------------------------------------------------
//字符串的全组合
void	DoCombine(const string& in, string& out, int level, int start)
{
    for(unsigned int i=start; i<in.length(); i++)
    {
        out.append(in, i, 1);
        if(i<in.length()-1)
            DoCombine(in, out, level+1, i+1);
        else if (out.length()>1)// ==5
            cout << out << "\n";// result
        out.erase(out.end()-1);
    }
}
void	Combine(const string& str)
{
    string	out;
    DoCombine(str, out, 0, 0);
}
//---------------------------------------------------------------------------
void    GetMemoryPtr(char**p, int num)
{
    *p = (char*)malloc(sizeof(char)*num);
}
void    GetMemoryRef(char*  &p, int num)
{
    p = (char*)malloc(sizeof(char)*num);
}
//---------------------------------------------------------------------------

int Bit_Reset(unsigned int* val, unsigned char pos)
{
    if(pos>=sizeof(unsigned int)*8)
        return  0;
    *val = (*val& ~BIT_MASK(pos));
    return 1;
}
unsigned int oct2dec(unsigned int oct)
{
    // 十进制=八进制/10*8+八进制%10 ；
    return oct/10*8+oct%10;
}

#define BIT3 (0x1 << 3)
void    SetBit3(int& a)
{
    a |= BIT3;
}
void    ClearBit3(int& a)
{
    a &= ~BIT3;
}
//---------------------------------------------------------------------------
// ---- 循环、递归与概率 ----
/*
f(m,n)  = n     (m=1)
        = m     (n=1)
        = f(m-1,n)+f(m,n-1) (m>1,n>1)
*/
#define RECURSION 1
#define NO_RECURSION 1
// --- 递归 ---
//#if RECURSION
int f1(int m, int n)
{
    if(1==m)
        return  n;
    if(1==n)
        return  m;
    return f1(m-1,n)+f1(m,n-1);
}
//#endif
// --- 非递归 ----
//#if NO_RECURSION
int f2(int m, int n)
{
    int     **array;
    array = new int*[m];
    for(int i=0; i<m; i++)
        array[i] = new int[n];

    for(int i=0; i<m; i++)
        array[i][0] = i+1;
    for(int i=0; i<n; i++)
        array[0][i] = i+1;
    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            array[i][j] = array[i-1][j]+array[i][j-1];

    int     re = array[m-1][n-1];
    for(int i=0; i<m; i++)
        delete[] array[i];
    delete[] array;
    return  re;
}
//#endif
//" ----------螺旋队列问题 ---------------------\n";
int Foo(int x, int y)
{
    int t = MAX(abs(x), abs(y));
    int u = t + t;
    int v = u - 1;
    v = v*v;
    if(x==-t)
        v += 5*t - y;
    else if(y==-t)
        v += 7*t + x;
    else if(y==t)
        v += 3*t - x;
    else
        v += t + y;
    return  v;
}
//---------------------------------------------------------------------------
// --- 拷贝字符串 ----
char*   Strcpy(char* dest, char* source)
{
    assert( dest!=NULL&&source!=NULL);
    char*   dest_ = dest;
    while(*source!='\0')
        *(dest++) = *(source++);
    *dest = '\0';
    return  dest_;
}
//---------------------------------------------------------------------------
// --- 循环移动字符串 ---- steps>0 循环右移，steps<0循环左移
char*   loopMoveStr(char* str, int steps)//strcpy ...
{
    if(steps==0)
        return  str;
    int length = strlen(str);
    steps = steps%length;
    int n = length-abs(steps);
    char*   temp = new char[length+1];
    if(steps>0)
    {
        strcpy(temp, str+n);
        *(str+n) = '\0';
        strcpy(temp+steps, str);
    }
    else //steps<0
    {
        strcpy(temp, str-steps); //str+abs(steps) ...
        *(str-steps) = '\0';
        strcpy(temp+n, str);
    }
    *(temp+length) = '\0';
    strcpy(str, temp);
    delete[]  temp;
    return  str;
}
// ---- steps>0 循环右移，steps<0循环左移
char*   loopMoveStr_(char* str, int steps)//memcpy
{
    if(steps==0)
        return  str;
    int length = strlen(str);
    steps = steps%length;
    int n = length-abs(steps);
    char*   temp = new char[length+1];
    if(steps>0)
    {
        memcpy(temp, str+n, steps);
        memcpy(temp+steps, str, n);
    }
    else //steps<0
    {
        memcpy(temp, str+abs(steps), n); //str+abs(steps) ...
        memcpy(temp+n, str, abs(steps));
    }
    *(temp+length) = '\0';
    strcpy(str, temp);
    delete[]  temp;
    return  str;
}
// stl ... 循环左移，即逆时针循环
template <class _ForwardIter> // ,  class _Distance
_ForwardIter __rotate(_ForwardIter __first,
                      _ForwardIter __middle,
                      _ForwardIter __last,
//                      _Distance*,
                      const forward_iterator_tag &)
{
    if (__first == __middle)
        return __last;
    if (__last  == __middle)
        return __first;

    _ForwardIter __first2 = __middle;
    do
    {
        swap(*__first++, *__first2++);
        if (__first == __middle)
            __middle = __first2;
    }
    while (__first2 != __last);

    _ForwardIter __new_middle = __first;

    __first2 = __middle;

    while (__first2 != __last)
    {
        swap (*__first++, *__first2++);
        if (__first == __middle)
            __middle = __first2;
        else if (__first2 == __last)
            __first2 = __middle;
    }
    return __new_middle;
}
// ---- steps>0 循环右移，steps<0循环左移
char*   strRotate(char* str, int steps)//call stl
{
    if(steps==0)
        return  str;
    int length = strlen(str);
    steps = -steps%length; // 变换steps 适应__rotate的循环左移
    if(steps<0)
        steps = length+steps;
    __rotate(str, str+steps, str+length, forward_iterator_tag() );
    return  str;
}
//---------------------------------------------------------------------------
// --查找一个字符串中连续出现次数最多的子串-- ?????
pair<int,string> findMostSubstr(const string& str)
{
    vector<string>  substrs;
    int     maxcount=1, count=1;
    string      substr;
    int     len = str.length();
    for(int i=0; i<len; i++)
        substrs.push_back(str.substr(i, len-i) );
    cout << " --- substrs : ---\n";
    copy(substrs.begin(), substrs.end(), ostream_iterator<string>(cout, "\n") );
    for(int i=0; i<len; i++)
        for(int j=i+1; j<len; j++)
        {
            count = 1;
            if(substrs[i].substr(0, j-i)==substrs[j].substr(0, j-i))
            {
                count++;
                for(int k=j+(j-i); k<len; k+=j-i)
                    if(substrs[i].substr(0,j-i)==substrs[k].substr(0,j-i) )
                        count++;
                    else
                        break;
                if(count>maxcount)
                {
                    maxcount = count;
                    substr = substrs[i].substr(0,j-i);
                }
            }
        }
    //cout << " maxcount:" << maxcount << ", substr:" << substr <<"\n";
    return  pair<int,string>(maxcount, substr);
}
// --- 模拟实现C++ 函数strstr(...)
char* strStr(char* str, const char* substr)
{
    for(int i=0; str[i]!='\0'; i++)
    {
        int     j = 0;
        int     k = i;
        if(str[i]==substr[j])
        {
            while(str[i++]==substr[j++])
                if(substr[j]=='\0')
                    return  &str[i-j];
            i = k;
        }
    }
    return  NULL;
} /* */
const char* strStr(const char* str, const char* substr)
{
    // ....同上 ...
    return  NULL;
}
//---------------------------------------------------------------------------
namespace testBaiduStudy
{
__int64 Factorial(int n)
{
    if(n<0)
        throw -1;// error
    if(n<=1)
        return 1;
    //int f0=1, f1=1,
    __int64     f2=1;
    for(int i=2; i<=n; i++) //__int64
        f2 *= i;
    return f2;
}
int FactorialCount0Num_1(int n)
{
    __int64 product = Factorial(n);
    int count =0;
    while(product%10==0)
    {
        count++;
        product /= 10;
    }
    return count;
}
int FactorialCount0Num_2(int n)
{
    int     count =0;
    for(int i=5; i<=n; i+=5)
    {
        int j=i;
        while(j%5==0&&j!=0)
        {
            count++;
            j = j/5;
        }
    }
    return  count;
}
}
//---------------------------------------------------------------------------

