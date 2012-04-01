
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
//���� --NULL ���� ѭ�� ���ж�
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
//�жϸü�������� --��β����or Сβ������ʾ������...��
bool Endianness1();
bool Endianness2();
//��������num �Ķ������С�1���ĸ���
int Count1InInt1(int num);
int Count1InInt2(int num);
int Count1InInt3(int num);
//�ַ�����ת
void ReverseString(char* str, int start, int end);//[start, end] revese
void ReverseWords(char* words );
//�������е���С �����ֵ;;
bool SearchMaxMin1(const int Array[], int start, int end, MValue& mValue);
MValue	SearchMaxMin2(const int Array[], int start, int end );//,MValue& mValue
// �ж�����head��ͷ��㣩�л��޻�
bool DetermineTermination(Node* head);
// �������е���mԪ��
Node*	FindmToLastElement(Node* head, int m);
//����չ�� ��˫������
typedef	struct ListNode
{
    ListNode *next;
    ListNode *prev;
    ListNode *child;
    int  value;
} ListNode;
//void Append(ListNode* child, ListNode** tail);
void FlattenList(ListNode* head, ListNode** tail);
//ȡ�� ���ָ�����(չ��) ��˫������
//void ExploreAndSeparate(ListNode* child);
void Unfatten(ListNode* head, ListNode** tail);
//�� 0 .....n �Ľ׳� 0��....n��
int DoAllFactorials(int n, int results[], int level);
int*	AllFactorials(int n);
// �ǵݹ飬����ʵ��....
long long Factorial(int n);//__int64
//---------------------------------------------------------------------------
//��������
#define	NOT_IN_ARRAY		-1
#define	ARRAY_UNORDEREED	-2	//����
#define	LIMITS_REVERSED		-3

int BinarySearch1(int array[], int lower, int upper, int target);
int BinarySearch2(int array[], int lower, int upper, int target);
//�ַ�����ȫ����
//void DoPermute(const string& in, string out, bool used[], int level);
void Permute(const string& str);
//�ַ�����ȫ���
//void DoCombine(const string& in, string out, int level, int start);
void Combine(const string& str);
//---------------------------------------------------------------------------
//  ����½����� N ��Ԫ��
NodePtr		NewRandomList(int n );
//��ʾ����
void PrintList(NodePtr	head);
//ɾ������
void DeleteList(NodePtr	head);
//��ת����----
NodePtr	ReverseList(NodePtr head);
//---------------------------------------------------------------------------

// --- �������� ----
bool Prime_1(int n);
bool Prime_2(int n);
bool Prime_3(int n);
bool Prime_4(int n);
bool Prime_5(int n);

/*
// Floyd �㷨 -------���ȡ����������� ------
template <typename T>
// �ݹ鷽�� ---
void  Sample_1(vector<T>& vecSet, T M, T N );
// �ǵݹ鷽�� ---
template <typename T>
void  Sample_2(vector<T>& vecSet, T M, T N );
*/
// -------���ȡ����������� ------
// һ�㷽�� ---
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
// Floyd �㷨 -------���ȡ�� ------
template <typename T>
// �ݹ鷽�� ---
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
// �ǵݹ鷽�� ---
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
// Floyd �㷨 -----������� ------
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
