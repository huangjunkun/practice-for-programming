//---------------------------------------------------------------------------
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include "sub_unit.h"

using namespace std;
//---------------------------------------------------------------------------

void print_list(b_node* list)
{
    while (list)
    {
        printf("[%d] <=> ", list->key);
        list = list->next;
    }
    printf("null\n");
}

void delete_list(b_node* list)
{
    while (list)
    {
        b_node* tmp = list->next;
        delete list;
        list = tmp;
    }
}

b_node* push_back(b_node* list, b_node* node)
{
    if (NULL == node)
        return NULL;

    while (list->next)
        list = list->next;

    b_node* prev = list;
    prev->next = node;
    node->prev = prev;
    node->next = NULL;

    //printf(" key [%d]\n", node->key);
    return node;
}

b_node* push_back(b_node* list, b_node** nodes, size_t count)
{
    if (NULL == nodes || 0 == count)
        return NULL;

    b_node* last = push_back(list, nodes[0]);
    assert (last);
    for (size_t i = 1; i < count; ++i)
    {
        last->next = nodes[i];
        nodes[i]->prev = last;
        nodes[i]->next = NULL;
        last = nodes[i];
    }
    return nodes[count - 1];
}

b_node* delete_node(b_node* node) /// b_node*& node
{
    if (NULL == node)
        return NULL;

    b_node* ret = NULL;
    if (node->prev)
    {
        if (node->next)
        {
            b_node* prev = node->prev;
            b_node* next = node->next;
            next->prev = prev;
            prev->next = next;
            ret = next;
        }
        else
        {
            b_node* prev = node->prev;
            prev->next = NULL;
        }
    }
    else
    {// NULL == (node->prev)

        if (node->next)
        {
            b_node* next = node->next;
            next->prev = NULL;
            ret = next;
        }
        else {}
    }

     delete node;
     node = NULL;
     return ret;
}


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
/// ʱ�临�Ӷ� O (m + n + k) -> O (N)
void select_diff_set1(vector<char>& all, vector<char>& part, vector<char>& diff_set)
{
    diff_set.clear();
    assert (all.size() >= part.size());
    char mark[256] = {0};
    memset(mark, 0, sizeof(mark));

    for (size_t i =0; i < all.size(); ++i)
        mark[(unsigned char)all[i]] = 1;
    for (size_t i =0; i < part.size(); ++i)
        mark[(unsigned char)part[i]] = 2;

    for (size_t i =0; i < sizeof(mark); ++i)
        if (1 == mark[i])
            diff_set.push_back(i);
    return;
}

/// bad��ʱ�临�Ӷ� O (n(log(n) + m * log(n)) -> O (N*log(N))
void select_diff_set2(vector<char>& all, vector<char>& part, vector<char>& diff_set)
{
    assert (all.size() >= part.size());
    diff_set.clear();
    std::sort(part.begin(), part.end());
    for (size_t i = 0; i < all.size(); ++i)
    {
        if(!std::binary_search(part.begin(), part.end(), all[i]))
            diff_set.push_back(all[i]);
    }

}
/// ��������ʱ�临�Ӷ� O (m * n) -> O (N^2)
void select_diff_set3(vector<char>& all, vector<char>& part, vector<char>& diff_set)
{
    assert (all.size() >= part.size());
    diff_set.clear();
    for (size_t i = 0; i < all.size(); ++i)
    {
        size_t j = 0;
        for (; j < part.size(); ++j)
            if ( all[i] == part[j])
            {
                break;
            }
        if (part.size() == j)
            diff_set.push_back(all[i]);
    }
}

void insert_tree(treeT* tree, treeT* nodes, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        printf("insert_tree nodes.[key] %d\n", nodes[i].key);
        insert_tree(tree, nodes[i]);
    }
}

void insert_tree(treeT* tree, treeT& node)
{
    assert (tree);
    treeT*& next = tree;
    while (next)
    {
        if (next->key > node.key)
        {
            printf("next->left [key] %d\n", next->key);
			if (!next->left)
			{
				next->left = &node;
				break;
			}
			else
				next = next->left;
        }
        else
        {
            printf("next->right [key] %d\n", next->key);

			if (!next->right)
			{
				next->right = &node;
				break;
			}
			else
				next = next->right;
        }
    }
}

void bfs_tree(treeT* tree)
{
    if (!tree)
        return;

    deque<treeT*> deq_tree;
    deq_tree.push_back(tree);

    do
    {
        treeT* next = deq_tree.front();
        deq_tree.pop_front();
        printf("[key]%d ", next->key);
        if (next->left)
            deq_tree.push_back(next->left);
        if (next->right)
            deq_tree.push_back(next->right);
    } while (!deq_tree.empty());
    printf("\n");
}


void dfs_tree(treeT* tree)
{
    if (!tree)
        return;

    stack<treeT*> sta_tree;
    sta_tree.push(tree);
    treeT* next = tree;
    do
    {
        if (next->left)
        {
            sta_tree.push(next->left);
            next = next->left;
        }
        else
        {
            next = sta_tree.top();
            sta_tree.pop();
            printf("[key]%d ", next->key);
            if (next->right)
            {
                sta_tree.push(next->right);
                next = next->right;
            }
        }
    } while (!sta_tree.empty());
    printf("\n");
}

void preorder_traversal_tree(treeT* tree)
{
   dfs_tree(tree);
}


//�ַ�����ȫ����
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
//�ַ�����ȫ���
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
    // ʮ����=�˽���/10*8+�˽���%10 ��
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
// ---- ѭ�����ݹ������ ----
/*
f(m,n)  = n     (m=1)
        = m     (n=1)
        = f(m-1,n)+f(m,n-1) (m>1,n>1)
*/
#define RECURSION 1
#define NO_RECURSION 1
// --- �ݹ� ---
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
// --- �ǵݹ� ----
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
//" ----------������������ ---------------------\n";
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
// --- �����ַ��� ----
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
// --- ѭ���ƶ��ַ��� ---- steps>0 ѭ�����ƣ�steps<0ѭ������
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
// ---- steps>0 ѭ�����ƣ�steps<0ѭ������
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
// stl ... ѭ�����ƣ�����ʱ��ѭ��
template <class _ForwardIter> // ,  class _Distance
_ForwardIter rotate_from_stl(_ForwardIter __first,
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
// ---- steps>0 ѭ�����ƣ�steps<0ѭ������
char*   strRotate(char* str, int steps)//call stl
{
    if(steps==0)
        return  str;
    int length = strlen(str);
    steps = -steps%length; // �任steps ��Ӧ__rotate��ѭ������
    if(steps<0)
        steps = length+steps;
    rotate_from_stl(str, str+steps, str+length, forward_iterator_tag() );
    return  str;
}
//---------------------------------------------------------------------------
// --����һ���ַ������������ִ��������Ӵ�-- ?????
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
// --- ģ��ʵ��C++ ����strstr(...)
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
    // ....ͬ�� ...
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

} /// testBaiduStudy


/// guangzhou duoyi wangluo ��Ϸ��˾���Ա����
int str2int(const std::string& buffer )
{
    int value = 0;
    if (buffer.empty())
    {
        std::cerr << "buffer is empty.\n";
        return value;
    }
    int flag_value = 1;
    size_t i = 0;
    if (buffer[0] == '-')
    {
        flag_value = -1;
        ++i;
    }
    for (; i < buffer.size(); ++i)
    {
        if (isdigit(buffer[i]))
        {
            value = value * 10 + (buffer[i] - '0');
        }
        else
        {
            std::cerr << "char is not digit.\n";
            value = 0;
            break;
        }
    }
    value *= flag_value;
    return value;
}

std::string find_longest_sequential_digit_substr(const std::string& buffer)
{
    std::string longest = "";
    std::string sequential_digit_substr = "";
    for (size_t i = 0; i < buffer.size(); ++i)
    {
        if (isdigit(buffer[i]))
        {
            char next_digit;
            do
            {
                sequential_digit_substr.push_back(buffer[i]);
                next_digit = buffer[i] + 1;
                ++i;
            } while(isdigit(buffer[i]) && i < buffer.size() && buffer[i] == next_digit);
        }
        else
        {
            continue;
        }

        if (sequential_digit_substr.size() > longest.size())
        {
            longest = sequential_digit_substr;
        }
        sequential_digit_substr.clear();
    }
    return longest;
}

int find_value_of_max_occur_count(std::vector<int>& nums)
{
    int ret = -1;
    if (nums.size() == 1)
    {
        return nums[0];
    }
    if (nums.empty())
    {
        return ret;
    }
    std::sort(nums.begin(), nums.end());
    size_t max_occur_count = 0, occur_count;
    int max_occur_count_value;
    int pred = nums[0];
    occur_count = 1;
    for (size_t i = 1; i < nums.size(); ++i)
    {
        if (nums[i] == pred)
        {
            ++occur_count;
        }
        else
        {
            if (occur_count > max_occur_count)
            {
                max_occur_count = occur_count;
                max_occur_count_value = pred;
            }
            pred = nums[i];
        }
    }
    if (occur_count > max_occur_count)
    {
        max_occur_count = occur_count;
        max_occur_count_value = pred;
    }
    if (max_occur_count > nums.size()/2)
    {
        ret = max_occur_count_value;
    }
    return ret;
}
//---------------------------------------------------------------------------

