

#include <cassert>
#include <cstring>

#include "unit2.h"

//---------------------------------------------------------------------------
//�жϸü�������� --��β���� or Сβ������ʾ������...��
bool Endianness1()
{
    int testnum = 1;
    char*	ptr;
    ptr	= (char*) &testnum;
    return (*ptr); //static_cast<bool>
}
bool Endianness2()
{
    typedef union EndianTest
    {
        int iNum;
        char	cByte;
    } EndianTest;
    EndianTest endiantest;
    endiantest.iNum = 1;
    return endiantest.cByte;
}
//---------------------------------------------------------------------------
//��������num �Ķ������С�1���ĸ���
int Count1InInt1(int num)
{
    int count = 0;
    while( num!=0 )
    {
        if(num%2==1)
            count++;
        num = num/2;
    }
    return count;
}
//---------------------------------------------------------------------------
int Count1InInt2(int num)
{
    int count = 0;
    while( num!=0 )
    {
        if( num& 1)
            count++;
        num = (num >> 1 );
    }
    return count;
}
//---------------------------------------------------------------------------
int Count1InInt3(int num)
{
    int count = 0;
    while( num!=0 )
    {
        count++;
        num = (num & (num-1));
    }
    return count;
}
//---------------------------------------------------------------------------
//�ַ�����ת
void ReverseString(char str[], int start, int end)//[start, end] revese
{
    if(start<0||end>=(signed) strlen(str)||start>=end)
        return;//error
    while(start<end)
    {
        char	temp;
        //char	temp1;
        temp = str[end];
        str[end] = str[start];//!!!!!!???????!///
        //cout << "	!!!!\n"; getch();
        str[start] = temp;
        end--;
        start++;
    }
    return;
}
//---------------------------------------------------------------------------
void ReverseWords(char words[] )
{
    int length = strlen(words);
    int start=0, end = 0;
    ReverseString(words, 0, length-1);
    //cout << words << endl;
    while(end<length-1)
    {
        start = end;
        while( words[end]!=' '&& end<length ) //isalnum(words[end])
        {
            end++;
        }
        end--;
        ReverseString(words, start, end);
        do
        {
            end++;
        }
        while(words[end]==' ');
    }
    return;
}
//---------------------------------------------------------------------------
//�������е���С �����ֵ
bool SearchMaxMin1(const int Array[], int start, int end, MValue& mValue)
{
    //cout << (sizeof(Array)/2-1) <<endl;
    if( start<0 || start>=end)// || end>(sizeof(Array)/2-1)
        return false;
    if( Array[start]>Array[start+1])
    {
        mValue.Max = Array[start];
        mValue.Min = Array[start+1];
    }
    else
    {
        mValue.Max = Array[start+1];
        mValue.Min = Array[start];
    }
    for(int i=start; i<end; i+=2)
    {
        mValue.Max = MAX(mValue.Max, MAX(Array[i], Array[i+1]));
        mValue.Min = MIN(mValue.Min, MIN(Array[i], Array[i+1]));
    }
    if( (end-start)%2==0)
    {
        mValue.Max = MAX(Array[end], mValue.Max);
        mValue.Min = MIN(Array[end], mValue.Min);
    }
    return true;
}
//---------------------------------------------------------------------------
MValue	SearchMaxMin2(const int Array[], int start, int end )//,MValue& mValue
{
    if(end-start<=1)
    {
        if( Array[start]>Array[end])
            return MValue( Array[start],  Array[end]);
        else
            return MValue( Array[end],  Array[start]);
    }

    MValue		mValueL=SearchMaxMin2(Array, start, start+(end-start)/2 );
    MValue		mValueR=SearchMaxMin2(Array, start+(end-start)/2+1, end );

    return MValue(MAX(mValueL.Max, mValueR.Max), MIN(mValueL.Min, mValueR.Min));
}
//---------------------------------------------------------------------------
// �ж�����head��ͷ��㣩�л��޻�
bool DetermineTermination(Node* head)
{
    Node	*fast, *slow;
    fast = slow = head;
    while(true)
    {
        if(!fast ||!fast->next)
            return false;//�޻�
        else if(fast==slow||fast->next==slow)
            return true ;//�л�
        else
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
}
//---------------------------------------------------------------------------
// �������е���mԪ��
Node*	FindmToLastElement(Node* head, int m)
{
    Node	*curNode, *mBehindNode;
    curNode = head;
    int i;
    for(i=0; i<m; i++)
        if(curNode->next)
            curNode = curNode->next;
        else
            return NULL;
    mBehindNode = head->next;// !!!head ???+;
    while(curNode->next)
    {
        curNode = curNode->next;
        mBehindNode = mBehindNode->next;
    }
    return mBehindNode;
}
//---------------------------------------------------------------------------
//����չ�� ��˫������
void Append(ListNode* child, ListNode** tail)
{
    ListNode*	curNode;
    (*tail)->next = child;
    child->prev = (*tail);
    for(curNode=child; curNode->next;
            curNode->next = curNode->next )
        ;
    *tail = curNode;
}
void FlattenList(ListNode* head, ListNode** tail)
{
    ListNode*	curNode = head;
    while(curNode->next)
    {
        if(curNode->child)
            Append(curNode->child, tail);
        curNode = curNode->next;
    }
}
//---------------------------------------------------------------------------
//ȡ�� ���ָ�����(չ��) ��˫������
void ExploreAndSeparate(ListNode* child)
{
    ListNode* curNode = child;
    while(curNode->next)
    {
        if(curNode->child)
        {
            curNode->child->prev->next = NULL;
            curNode->child->prev = NULL;
            ExploreAndSeparate(curNode->child);
        }
        curNode = curNode->next;
    }
}
void Unfatten(ListNode* head, ListNode** tail)
{
    ListNode* curNode;
    ExploreAndSeparate( head);
    for(curNode=head; curNode->next;
            curNode = curNode->next )
        ;
    (*tail) = curNode;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//�� 0 .....n �Ľ׳� 0��....n��
// �ݹ� ... ������̽�� ... ���߸�Ч��
int DoAllFactorials(int n, int results[], int level)
{
    if(n>0)
    {
        results[level]=n*DoAllFactorials(n-1, results, level+1);
        return results[level];
    }
    else
    {
        results[level] = 1;
        return 1;
    }
}
int* AllFactorials(int n)
{
    assert (n >= 0);
    int *results = new int[n+1];
    DoAllFactorials(n, results, 0) ;
    return results;
}
// �ǵݹ飬����ʵ�֣���Ч��....��������̽�������Ա��棩
long long Factorial(int n)//__int64
{
    long long val = 1;
    for(int i=n; i>1; i--)
        val *= i;
    return  val;
}
//---------------------------------------------------------------------------
//��������
#define	NOT_IN_ARRAY		-1
#define	ARRAY_UNORDEREED	-2	//����
#define	LIMITS_REVERSED		-3

int BinarySearch1(int array[], int lower, int upper, int target)
{
    //�ݹ� ��������
    int range = upper - lower;
    if(range<0)
        return LIMITS_REVERSED;
    if(range==0 && array[lower]!=array[upper])
        return NOT_IN_ARRAY;
    if(array[lower]>array[upper])
        return ARRAY_UNORDEREED;
    int center = (range/2)+lower;
    if(array[center]==target)
        return center;
    else if(array[center]>target)
        return BinarySearch1(array, lower, center-1, target);
    else //(array[center]>target)
        return BinarySearch1(array, center+1, upper, target);


}
int BinarySearch2(int array[], int lower, int upper, int target)
{
    //�ǵݹ� ��������

    if(upper<lower)
        return LIMITS_REVERSED;
    while(true)
    {
        int range = upper - lower;
        if(range==0 && array[lower]!=target)
            return NOT_IN_ARRAY;
        if(array[lower]>array[upper])
            return ARRAY_UNORDEREED;
        int center = (range/2)+lower;
        if(array[center]==target)
            return center;
        else if(array[center]>target)
            upper = center-1;
        else //(array[center]<target)
            lower = center+1;
    }
}
//---------------------------------------------------------------------------
//�ַ�����ȫ����
void DoPermute(const string& in, string out, bool used[], int level)
{
    if(level==in.length() )
    {
        cout << "[" << level << "] " << out << endl;// result
        return;
    }
    for(int i=0; i<in.length(); i++)
    {
        if(used[i]==true)
            continue;
        //else
        out.append(in, i, 1);//
        used[i] = true;
        DoPermute(in, out, used, level+1);
        used[i] = false;
        out.erase(out.end()-1);
    }

}
void Permute(const string&	str)
{
    bool *used = new bool[str.length()];
    for(int i=0; i<str.length(); i++)
        used[i] = false;
    string	out = "";
    DoPermute(str, out, used, 0);
    delete[] used;
}

//---------------------------------------------------------------------------
//�ַ�����ȫ���
void DoCombine(const string& in, string out, int level, int start)
{
    for(int i=start; i<in.length(); i++)
    {
        out.append(in, i, 1);
        if(i<in.length()-1)
            DoCombine(in, out, level+1, i+1);
        else
            cout << "[" << level << "] " << ( out.length()>1 ? out.c_str() : "" ) << endl;// result
        out.erase(out.end()-1);
    }
}
void Combine(const string& str)
{
    string	out;
    DoCombine(str, out, 0, 0);
}

//---------------------------------------------------------------------------
//  ����½����� N ��Ԫ��
NodePtr	 NewRandomList(int n )
{
//	time_t
    if(n<=0)
        return NULL;
    time_t t;
    srand((unsigned) time(&t));
    //srand( (unsigned int) time_t(NULL));
    NodePtr		head, last, temp;
    head = new Node;//����ͷ���
    last = head;

    for(int i=0; i<n; i++)
    {
        temp = new Node;
        temp->value = rand()%100;
        temp->next = NULL;
        last->next = temp;
        last = last->next;
        //cout << last->value << " - " ;
    }
    return head;//success
}
//��ʾ����
void PrintList(NodePtr	head)
{
    //cout << "!!!!!!!!!!!!!!!!\n";
    if(head==NULL)
        return;//error
    NodePtr	Pcur = head->next;
    while(Pcur!=NULL)//Pcur!=NULL
    {
        cout << Pcur->value << " - ";
        Pcur = Pcur->next;
    }
    cout << endl;
}
//ɾ������
void DeleteList(NodePtr	head)
{
    if(head==NULL||head->next==NULL)
        return;//error
    NodePtr	Phead = head->next;
    NodePtr	Pcur = Phead;
    Phead = Pcur->next;

    while(Phead!=NULL)//Pcur!=NULL &&
    {
        //cout << Pcur->value << " - ";
        delete	Pcur;
        Pcur = Phead;
        Phead = Pcur->next;
    }
    //cout << Pcur->value << " - ";
    delete	Pcur;
    head->next = NULL;
}
//��ת����----
NodePtr	ReverseList(NodePtr head)
{
    if(head==NULL||head->next==NULL)
        return head;//NULL
    NodePtr		Phead, Pcur;
    Phead = head->next;
    head->next = Phead->next;
    Phead->next = NULL;
    Pcur = Phead;
    Phead = head->next;
    while(Phead)
    {
        head->next = Phead->next;
        Phead->next = Pcur;
        Pcur = Phead;
        Phead = head->next;
    }
    head->next = Pcur;

    return head;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// --- �������� ----
bool Prime_1(int n)
{

    for(int i=2; i<n; i++)
        if(n%i==0)
            return false;
    return true;
}
int Root(int n)
{
    return (int)sqrt( double(n) );
}
bool Prime_2(int n)
{
    for(int i=2; i<=Root(n); i++)
        if(n%i==0)
            return false;
    return true;
}
bool Prime_3(int n)
{
    int bound = Root(n);
    for(int i=2; i<=bound; i++)
        if(n%i==0)
            return  false;
    return true;
}
bool Prime_4(int n)
{
    if( n%2==0||n%3==0||n%5==0 )
        return false;
    int bound = Root(n);
    for(int i=7; i<=bound; i+=2)
        if(n%i==0)
            return false;
    return true;
}
bool Prime_5(int n)
{
    if( n%2==0||n%3==0||n%5==0 )
        return false;
    for(int i=7; i*i<=n; i+=2)
        if(n%i==0)
            return false;
    return true;
}
//---------------------------------------------------------------------------
