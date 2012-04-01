
#ifndef _UNIT2_H_
#define _UNIT2_H_


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;


typedef	struct MValue
{
    int Max;
    int Min;
    friend ostream&	operator << (ostream& outs, const MValue& mValue)
    {
        outs << "Max: " <<mValue.Max <<", Min: " << mValue.Min <<endl;
        return outs;
    }

    MValue() {};
    MValue(int i, int j):Max(i), Min(j) {}

}	MValue;
//链表 --NULL 或是 循环 ，判断
typedef	int ValueType;
typedef	struct Node
{
    Node*		next;
    ValueType		value;
} Node;
typedef	Node*	NodePtr;

#define	MAX(i, j)	(i>j ? i :j)
#define	MIN(i, j)	(i<j ? i :j)

//---------------------------------------------------------------------------
//判断该计算机采用 --大尾数法or 小尾数法表示整数（...）
bool Endianness1();
bool Endianness2();
//计算整数num 的二进制中“1”的个数
int Count1InInt1(int num);
int Count1InInt2(int num);
int Count1InInt3(int num);
//字符串反转
void ReverseString(char* str, int start, int end);//[start, end] revese
void ReverseWords(char* words );
//求数组中的最小 ，最大值;;
bool SearchMaxMin1(const int Array[], int start, int end, MValue& mValue);
MValue	SearchMaxMin2(const int Array[], int start, int end );//,MValue& mValue
// 判断链表head（头结点）有环无环
bool DetermineTermination(Node* head);
// 求链表中倒数m元素
Node*	FindmToLastElement(Node* head, int m);
//链表展开 ，双向链表
typedef	struct ListNode
{
    ListNode *next;
    ListNode *prev;
    ListNode *child;
    int  value;
} ListNode;
//void Append(ListNode* child, ListNode** tail);
void FlattenList(ListNode* head, ListNode** tail);
//取消 ，恢复链表(展开) ，双向链表
//void ExploreAndSeparate(ListNode* child);
void Unfatten(ListNode* head, ListNode** tail);
//求 0 .....n 的阶乘 0！....n！
int DoAllFactorials(int n, int results[], int level);
int*	AllFactorials(int n);
// 非递归，迭代实现....
long long Factorial(int n);//__int64
//---------------------------------------------------------------------------
//二分搜索
#define	NOT_IN_ARRAY		-1
#define	ARRAY_UNORDEREED	-2	//无序
#define	LIMITS_REVERSED		-3

int BinarySearch1(int array[], int lower, int upper, int target);
int BinarySearch2(int array[], int lower, int upper, int target);
//字符串的全排列
//void DoPermute(const string& in, string out, bool used[], int level);
void Permute(const string& str);
//字符串的全组合
//void DoCombine(const string& in, string out, int level, int start);
void Combine(const string& str);
//---------------------------------------------------------------------------
//  随机新建链表 N 个元素
NodePtr		NewRandomList(int n );
//显示链表
void PrintList(NodePtr	head);
//删除链表
void DeleteList(NodePtr	head);
//反转链表----
NodePtr	ReverseList(NodePtr head);
//---------------------------------------------------------------------------

// --- 计算素数 ----
bool Prime_1(int n);
bool Prime_2(int n);
bool Prime_3(int n);
bool Prime_4(int n);
bool Prime_5(int n);

/*
// Floyd 算法 -------随机取样与随机排列 ------
template <typename T>
// 递归方法 ---
void  Sample_1(vector<T>& vecSet, T M, T N );
// 非递归方法 ---
template <typename T>
void  Sample_2(vector<T>& vecSet, T M, T N );
*/
// -------随机取样与随机排列 ------
// 一般方法 ---
template <typename T>
void  Sample_0(vector<T>& vecSet, T M, T N )
{
    while(vecSet.size() < M)
    {
        T t = T(rand()%N+1);
        if(find(vecSet.begin(), vecSet.end(), t)==vecSet.end() )
            vecSet.push_back(t);// t is not in vecSet
    }
}
// Floyd 算法 -------随机取样 ------
template <typename T>
// 递归方法 ---
void  Sample_1(vector<T>& vecSet, T M, T N )
{
    if(M == T(0))
        return;
    Sample_1(vecSet, M-T(1), N-T(1) );
    T t = T(rand()%N+1);
    if(find(vecSet.begin(), vecSet.end(), t)==vecSet.end() )
        vecSet.push_back(t);// t is not in vecSet
    else
        vecSet.push_back(N);// t is in vecSet
    return;
}
// 非递归方法 ---
template <typename T>
void  Sample_2(vector<T>& vecSet, T M, T N )
{
    for(int i=N-M+1; i<=N; i++)
    {
        T t = T(rand()%i+1);
        if(find(vecSet.begin(), vecSet.end(), t)==vecSet.end() )
            vecSet.push_back(t);// t is not in vecSet
        else
            vecSet.push_back(T(i));// t is in vecSet
    }
}
// Floyd 算法 -----随机排列 ------
template <typename T>
void Arrange(vector<T>& vecSet, T M, T N )
{
    for(int i=N-M+1; i<=N; i++)
    {
        T t = T(rand()%i+1);
        typename vector<T>::iterator it = std::find(vecSet.begin(), vecSet.end(), t);
        if(it==vecSet.end() )
            vecSet.insert(vecSet.begin(), t);// t is not in vecSet
        else
            vecSet.insert(it, T(i));// t is in vecSet
    }
}
//---------------------------------------------------------------------------
#endif //_UNIT2_H_
