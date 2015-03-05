//---------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <vector>
//#include <stdint>
#include "sub_unit.h"
using namespace std;

int main(int argc, char* argv[])
{
    {
        std::string buffer;
        cout << "str2int=" << str2int("") << "\n";
        cout << "str2int=" << str2int("123") << "\n";
        cout << "str2int=" << str2int("-123") << "\n";
        cout << "str2int=" << str2int("12a") << "\n";
        buffer = "asdfa123sda12345678d23456789";
        cout << "find_longest_sequential_digit_substr=" << find_longest_sequential_digit_substr(buffer) << "\n";
        buffer = "asdfa1sda8d2";
        cout << "find_longest_sequential_digit_substr=" << find_longest_sequential_digit_substr(buffer) << "\n";
        buffer = "asdfasdf";
        cout << "find_longest_sequential_digit_substr=" << find_longest_sequential_digit_substr(buffer) << "\n";

        int nums[] = {1, 5, 2, 5, 5, 6, 5, 5};
        std::vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
        cout << "find_value_of_max_occur_count=" << find_value_of_max_occur_count(vec) << "\n";
        int nums2[] = {1};
        vec.assign(nums2, nums2 + sizeof(nums2)/sizeof(int));
        cout << "find_value_of_max_occur_count=" << find_value_of_max_occur_count(vec) << "\n";
        int nums3[] = {1,2};
        vec.assign(nums3, nums3 + sizeof(nums3)/sizeof(int));
        cout << "find_value_of_max_occur_count=" << find_value_of_max_occur_count(vec) << "\n";
        int nums4[] = {1,1};
        vec.assign(nums4, nums4 + sizeof(nums4)/sizeof(int));
        cout << "find_value_of_max_occur_count=" << find_value_of_max_occur_count(vec) << "\n";
        int nums5[] = {1,1,2};
        vec.assign(nums5, nums5 + sizeof(nums5)/sizeof(int));
        cout << "find_value_of_max_occur_count=" << find_value_of_max_occur_count(vec) << "\n";
        int nums6[] = {};
        vec.assign(nums6, nums6 + sizeof(nums6)/sizeof(int));
        cout << "find_value_of_max_occur_count=" << find_value_of_max_occur_count(vec) << "\n";
    }
    /***
    {/// test b_node ...
        const unsigned NODES_COUNT = 10;
        b_node* nodes[NODES_COUNT];
        for (unsigned i = 0; i < NODES_COUNT; ++i)
        {
            nodes[i] = new b_node(i);
        }
        b_node* list = new b_node(-1);/// head
        push_back(list, nodes, NODES_COUNT);
        print_list(list);
        printf("delete_node head.\n");
        list = delete_node(list);
        print_list(list);
        printf("delete_node tail.\n");
        delete_node(nodes[NODES_COUNT-1]);
        print_list(list);
        printf("delete_node middle.\n");
        delete_node(nodes[NODES_COUNT/2]);
        print_list(list);


        delete_list(list);
        list = NULL;
        printf("delete_list.\n");
        print_list(list);
    }

    /***
    {/// test treeT ...
    treeT nodes[] = { treeT(4), treeT(2), treeT(3), treeT(1), treeT(6), treeT(5), treeT(7)} ;
    const unsigned nodes_size = sizeof(nodes) / sizeof(treeT);
    cout << nodes_size << " [nodes_size]\n";
    treeT* tree = &nodes[0];
    insert_tree(tree, nodes+1, nodes_size-1);
    bfs_tree(tree);
    //dfs_tree(tree);
    preorder_traversal_tree(tree);

    }
    /*
    {
    unsigned int res = 0;
    cout << hex2uint(0, res);
    cout << " res: " << res << "\n";
    cout << hex2uint("", res);
    cout << " res: " << res << "\n";
    cout << hex2uint("0", res);
    cout << " res: " << res << "\n";
    cout << hex2uint("f", res);
    cout << " res: " << res << "\n";
    cout << hex2uint("0x", res);
    cout << " res: " << res << "\n";
    cout << hex2uint("0x1", res);
    cout << " res: " << res << "\n";
    cout << hex2uint("0xa", res);
    cout << " res: " << res << "\n";
    cout << hex2uint("0xa1", res);
    cout << " res: " << res << "\n";
    cout << "\n";
    }
    {
    char a[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    char b[] = { 'a', 'b', 'c' };
    vector<char> a_vec(a, a+sizeof(a)/sizeof(char));
    vector<char> b_vec(b, b+sizeof(b)/sizeof(char));
    vector<char> c_vec;
    select_diff_set1(a_vec, b_vec, c_vec);
    std::copy(c_vec.begin(), c_vec.end(), ostream_iterator<char>(std::cout, ""));
    cout << "\n";
    select_diff_set2(a_vec, b_vec, c_vec);
    std::copy(c_vec.begin(), c_vec.end(), ostream_iterator<char>(std::cout, ""));
    cout << "\n";
    select_diff_set3(a_vec, b_vec, c_vec);
    std::copy(c_vec.begin(), c_vec.end(), ostream_iterator<char>(std::cout, ""));
    cout << "\n";

    }
    /**
//---------------------------------------------------------------------------
    // --- 程序设计基本概念 ----
    // --- 赋值语句 ----
    cout << " ------------赋值语句-------------------\n";
    {
    int x = 2, y,  z;
    x *=(y=z=5);
    cout << x << "\n";
    z = 3;
    x == (y=z);// 警告：非赋值，仅判断！
    cout << x << "\n";
    x = (y==z);
    cout << x << "\n";
    x = (y&z);
    cout << x << "\n";
    x = (y&&z);
    cout << x << "\n";
    y = 4;
    x = (y|z);
    cout << x << "\n";
    x = (y||z);
    cout << x << "\n";
    }
//---------------------------------------------------------------------------
    // ---- i++ -------
    cout << " -------i++ ------------------------\n";
    {
    int a, x;
    for(a=0, x=0;a<=1&&!x++;a++)
        a++;
    cout << " 1 .a :"<< a << ", x "<<x <<"\n";
    for(a=0, x=0;a<=1&&!x++;)
        a++;
    cout << " 2 .a :"<< a << ", x "<<x <<"\n";
    int b =3;
    int arr[] ={ 6, 7, 8, 9, 10 };
    int *ptr = arr;
    *(ptr++) += 123;
    printf("%d, %d\n", *ptr,*(++ptr) );// 8 8 参数从左向右压栈
    }
//---------------------------------------------------------------------------
    // --- 编程风格 -----
    cout << " -------编程风格------------------------\n";
    {
    char     a = 'a';
    if('A'==a) // good --- error 'A'=a
        a = 'a';
    else
        a = 'A';
    if(a=='A') // good --- ok a = 'A'
        a = 'a';
    else
        a = 'A';
    }
//---------------------------------------------------------------------------
    // ----类型转换 ----
    cout << " ----------类型转换---------------------\n";
    {
    unsigned char a = 0xa5;
    unsigned char b = ~a>>4;//先 >> 再 ~
    cout << " b = " << (int)b << "\n";
    }

    {
    float   a = 1.0f;
    cout << (int)a << "\n";
    cout << &a << "\n";
    cout << (int&)a << "\n";
    cout << boolalpha << ((int)a==(int&)a) << "\n";
    float   b = 0.0f;
    cout << (int)b << "\n";
    cout << &b << "\n";
    cout << (int&)b << "\n";
    cout << boolalpha << ((int)b==(int&)b) << "\n";
    }
    {
    unsigned int    a = 0xfffffff7;
    unsigned char    i = (unsigned char)a;
    char*   b = (char*)&a;
    printf("i = %08x, *b = %08x\n", i, *b);
    }
//---------------------------------------------------------------------------
    // ---- 与非或问题----
    cout << " ----------与非或问题---------------------\n";
    {
    // 不用循环 ，用一个表达式 判断一个数 X 是否是 2^n 次方(2,  4, 8 ....)
    #define Check2_N(x)     !(x&(x-1))
    cout << boolalpha << " Check2_N(16) :"<<Check2_N(16) << "\n";
    cout << boolalpha << " Check2_N(15) :"<<Check2_N(15) << "\n";
    }
    {// 输出 m 的二进制 1的个数 --
    int count = 0;
    int     m = 9999;
    while(m)
    {
        count++;
        m &= (m-1);
    }
    cout << " m = 9999,m二进制 1的个数: " << count << "\n";
    }
//---------------------------------------------------------------------------
    // ---- a, b 比较、交换----
    cout << " ----------a, b 比较、交换---------------------\n";
    { // 不用判断语句找出两个数中比较大的一个
    int a = 1, b = 9;
    cout << " int a = 1, b = 9;\n";
    int max = (a+b+abs(a-b))/2;
    cout << " 1 . max = " << max << "\n";
    int c = a-b;
    char* str[2] = { "max: a", "max: b" };
    c = unsigned(c) >> (sizeof(int)*8-1);
    cout << " 2 . "<< str[c] << "\n";
    }
//---------------------------------------------------------------------------
    { // 不使用任何中间变量将 a, b 的值交换
    int a = 1, b = 9;
    cout << " int a = 1, b = 9;\n";
    a = a+b;
    b = a-b;
    a = a-b;
    // 1 有可能 a = a+b 会出现越界 ----
    cout << " 1 : a = " << a << ", b = " << b<< "\n";
    a = 1, b = 9;
    cout << " a = 1, b = 9;\n";
    // 2 不会出现越界现象 ----
    a = a^b;
    b = a^b;
    a = a^b;
    cout << " 2 : a = " << a << ", b = " << b<< "\n";
    }
//---------------------------------------------------------------------------
// --- 预处理、const、sizeof ---------
    // --- 宏定义 -------
    cout << " ----------宏定义  ---------------------\n";
    {//宏定义FIND 求一个结构体struc里某个变量相对struc的偏移量
    #define FIND(struc, e) (size_t)&(((struc*)0)->e)
    cout << " FIND(student, id): " << FIND(student, id) << "\n";
    cout << " FIND(student, name): " << FIND(student, name) << "\n";
    cout << " FIND(student, value): " << FIND(student, value) << "\n";
//---------------------------------------------------------------------------
    {// 预定义 声明一个常熟表示一年中有多少秒
    #ifndef __int64
    #define __int64 long long
    #endif
    #define SECONDS_PER_YEAR  (((__int64)60)*60*24*356 )
    cout <<  " SECONDS_PER_YEAR = "<< SECONDS_PER_YEAR <<"\n";
    //cout << __int64(999999999999999LL)*2 << "\n";
    }
//---------------------------------------------------------------------------
    // --- const using namespace testConst;-------
    cout << " ----------const  ---------------------\n";
    {
    using namespace testConst;
    // mutable 修饰的成员变量，即使const修饰的成员函数也可以改变它
    C   c1(0), c2(10);
    for(int i=0,tmp;i<10;i++)
    {
        tmp = c1.incr();
        cout << setw(tmp) << setfill(' ')<< tmp << "\n";
        tmp = c2.decr();
        cout << setw(tmp) << setfill(' ')<< tmp << "\n";
    }
    }
//---------------------------------------------------------------------------
    // --- sizeof using namespace testSizeof;-------
    cout << " ----------sizeof  ---------------------\n";
    {
    using namespace testSizeof;
    // ...数组首地址，指针，字符串首地址，字符串指针....
    char*   ss1 = "0123456789";
    char    ss2[] = "0123456789";
    char    ss3[100] = "0123456789";
    int     ss4[100];
    char    q1[] = "abc";
    char    q2[] = "a\n";
    char*   q3 = "a\n";
    char*   str1 = (char*) malloc(100);
    void*   str2 = (void*) malloc(100);

    cout << " sizeof(ss1) = " << sizeof(ss1) << "\n";
    cout << " sizeof(ss2) = " << sizeof(ss2) << "\n";
    cout << " sizeof(ss3) = " << sizeof(ss3) << "\n";
    cout << " sizeof(ss4) = " << sizeof(ss4) << "\n";
    cout << " sizeof(q1) = " << sizeof(q1) << "\n";
    cout << " sizeof(q2) = " << sizeof(q2) << "\n";
    cout << " sizeof(q3) = " << sizeof(q3) << "\n";
    cout << " sizeof(A) = " << sizeof(A) << "\n";
    cout << " sizeof(B) = " << sizeof(B) << "\n";
    cout << " sizeof(str1) = " << sizeof(str1) << "\n";
    cout << " sizeof(str2) = " << sizeof(str2) << "\n";
    cout << " sizeof(*str1) = " << sizeof(*str1) << "\n";
    //cout << " sizeof(*str2) = " << sizeof(*str2) << "\n";
    free(str1);
    free(str2);
    }
//---------------------------------------------------------------------------
    {
    using namespace testSizeof;
    // ..多态，绑定，继承，构造函数，虚析构函数，虚函数...
    cout << " sizeof(Empty1): " << sizeof(Empty1) << "\n";
    cout << " sizeof(Derive1): " << sizeof(Derive1) << "\n";
    cout << " sizeof(Derive2): " << sizeof(Derive2) << "\n";
    cout << " sizeof(Derive3): " << sizeof(Derive3) << "\n";
    // ....
    cout << " sizeof(Base): " << sizeof(Base) << "\n";
    cout << " sizeof(Derived): " << sizeof(Derived) << "\n";
    Base    b;
    Derived d;
    Base    *pb = new Derived;
    Derived    *pd = new Derived;
    cout << " sizeof(b): " << sizeof(b) << "\n";
    cout << " sizeof(d): " << sizeof(d) << "\n";
    cout << " sizeof(pb): " << sizeof(pb) << "\n";
    cout << " sizeof(pd): " << sizeof(pd) << "\n";
    cout << " sizeof(*pb): " << sizeof(*pb) << "\n";
    cout << " sizeof(*pd): " << sizeof(*pd) << "\n";
    pb->f(10);
    pb->f(10.0);
    pd->f(10);
    pd->f(10.0);
    pd->f(complex<double>(10.0));
    pd->Base::f(10);
    pd->Base::f(10.0);

    delete  pb;
    delete  pd;
    }
//---------------------------------------------------------------------------
    { // ---内存的数据对齐规则 以2^n 对齐为准，提高CPU访问效率----
    using namespace testSizeof;
    int a;
    char    b;
    int c;
    printf("&a --->  0x%08x \n", &a);
    printf("&b --->  0x%08x \n", &b);
    printf("&c --->  0x%08x \n", &c);
    // BCB : c(4字节) -- z中间相隔3 字节 -- b(占1字节)--a(4字节)

//    &a --->  0x0013feb0 ------- 高位  +4字节
//    &b --->  0x0013feaf ------- 隔3字节 + 1字节
//    &c --->  0x0013fea8 ------- 低位  +4字节

    cout << " sizeof(C1):" << sizeof(C1) << "\n";
    cout << " sizeof(C2):" << sizeof(C2) << "\n";
    cout << " sizeof(C3):" << sizeof(C3) << "\n";
    }
//---------------------------------------------------------------------------
// ---- C 和 C++ 的关系 ----
    //cout << " ----------C 和 C++ 的关系 ---------------------\n";
    // ---- 程序设计的一些其他问题 ----
    cout << " ----------程序设计的一些其他问题 ---------------------\n";
    {
    //--- 求五位数 abcde*4=edcba ，这五个数字不重复
    // ---- 可以运用排列组合另解 更为高效 ---
    for(int i=10234;i<100000;i++)
    {
        int j =0;
        int t=i;
        while(t!=0)
        {
            j = j*10+t%10;
            t /= 10;
        }
        if((i<<2)==j)
            cout << i << " ";
    }
    cout << "\n";
    }
    cout << " 字符串\"1234\" 的全排列\n";
    //Permute("1234");
    cout << " 字符串\"1234\" 的全组合\n";
    Combine("1234");
    }
//---------------------------------------------------------------------------
// ---- 指针与引用 ----
    //cout << " ----------指针与引用 ---------------------\n";
    {
    // ---- 传递动态指针 ----
    cout << " ----------传递动态指针 ---------------------\n";
    //using namespace testPtrRef;
    char    *str = NULL;
    //delete  str;// ...ok ...
    GetMemoryPtr(&str, 20);
    strcpy(str, "1 .hello, world! ");
    cout << str << "\n";
    delete  str;
    GetMemoryRef(str, 20);
    strcpy(str, "2 .hello, world! ");
    cout << str << "\n";
    delete  str;

//    int *ptr;
//    ptr = (int*)0x8000;
//    *ptr = 0xaaaa; // error
//    cout << *ptr << "\n";// error
    }
	{
    cout << " ----------函数指针 ---------------------\n\n";
    //def是一个二级指针，它指向的是一个指向一维数组的指针，数组元素是float
    float (**fpp10)[10];//... ???
    //gh是一个指针，它指向一个一维数组10个元素，数组元素都是 double*
    double* (*dp10)[10];
    //d是一个数组，d有10个元素，元素都是函数指针，
    // 指向的是函数类型没有参数且返回double类型的函数
    double (*d[10])();
    //类似于 double* (*gh)[10];
    int* ((*b)[10]);
    //函数指针：参数为int，返回类型为long
    long (*fun)(int);
    //F是一个函数指针 指向一个函数类型是有两个int参数并且返回一个函数指针 ，
    //返回也是函数指针--指向一个int参数并且返回int的函数
    int (*(F)(int, int))(int);
    // ....
    float   f3[1][2][10];
    float   f2[1][10];
    float   (*fp1)[10] = f2;
    fpp10 = &fp1; // ....
    float   f1[10];
    float   (*fp2) = f1;
    float (**fpp0);
    fpp0 = &fp2;
    // ....
    double*     dPtrArray[2][10];//[...][10]!!!
    dp10 = dPtrArray;
    }
    {
    cout << " ----------指针数组和数组指针 ---------------------\n";
    int v[2][10] = { {1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20}};
    int (*a)[10] = v; // 数组指针
    cout << " **a = " << **a << "\n";
    cout << " *(*a+1) = " << *(*a+1) << "\n";
    a++;
    cout << " **a = " << **a << "\n";
    cout << " *(*a+1) = " << *(*a+1) << "\n";
    }
//---------------------------------------------------------------------------
    {
    cout << " ----------迷途指针，即野指针 ---------------------\n";
    }
    {
    cout << " ----------位运算 ---------------------\n";
    printf("%f\n", 5);
    printf("%d\n", 5.01);
    unsigned int x = 0xffffffff;
    unsigned char y = 4;
    Bit_Reset(&x, y);
    std::cout << std::hex << x << "\n";
    cout << std::dec;// 恢复十进制---
    cout << " oct2dec(87): " << oct2dec(87) << "\n";
    unsigned short int i=0;
    int j=8, p;
    p = j << 1;
    i = i-1;
    cout << " i = " << i <<"\n";
    cout << " p = " << p << "\n";
    // 内存中数据低位字节存入低地址，高位字节存入高地址，而数据的地址
    // 采用它的低地址来表示
    using namespace testBitOper;
    U   u;
    u.ui = 0xf0f1f2f3;
    cout << " u.ui = " << hex << u.ui << "\n";
    cout << " (int)u.uc = " << hex << (int)u.uc << "\n";
    // ...
    int     a = 0;
    SetBit3(a);
    cout << " a = " << a << "\n";
    ClearBit3(a);
    cout << " a = " << a << "\n";
    // ...
    int *pa = NULL;
    int *pb = pa+15;// 0 + 15*4
    printf("pb = %d \n", pb); // dangerous
    printf("pb = %x \n", pb); // dangerous
    }
//---------------------------------------------------------------------------

//     {//test scanf ... float, loop ???
//     float f1, f2[2];
//     scanf("%f", &f1);
//     printf(" float f1 = %f\n", f1);
//     scanf("%f", &f2[0]);
//     printf(" f2[0] = %f\n", f2[0]);
//     }
    { /// just a test for C array and pointer.
//    int     a[4][4];
//    int**   iPPtr = (int**)a;// okokok
//    int**   iPPtr = a;//error
    }
    {
        using namespace testBaiduStudy;
        cout << " Factorial(18): " << Factorial(18) << "\n";
        cout << " FactorialCount0Num_1(18): " << FactorialCount0Num_1(18) << "\n";
        cout << " FactorialCount0Num_2(18): " << FactorialCount0Num_2(18) << "\n";
        int     a[5] = {2, 4, 3, 4, 7};
        const int     N = sizeof(a)/sizeof(int);
        cout << " " << *SearchNMax(a, a+N, N, less<int>()) << "\n";
        //cout << " " << *SearchNMax(a, a+N, 2, less<int>() ) << "\n";
        //cout << " " << *SearchNMax(a, a+N, 2, less<int>() ) << "\n";
    }
    ///*
        { // test namespace testDataStruct;
        using namespace testDataStruct;
        Queue<int> queInt;
        queInt.push(1);
        queInt.push(2);
        queInt.push(3);
        cout << " queInt.size(): " << queInt.size() << "\n";

        while(!(queInt.size()==0) )
        {
            cout << " queInt.front(): " << queInt.front()<<"\n";
            queInt.pop();
            cout << " queInt.size(): " << queInt.size() << "\n";
        }
        //queInt.pop(); //throw ...
        //queInt.front(); //throw ...
        } //namespace testDataStruct;
    ///*
        {
        using namespace testInitMemOrder;
        Play    p;
        p(1);
        }

    ///*
        {// test--- strstr ---
        //char *strstr(const char *s1, const char *s2);     //C only
        //const char *strstr(const char *s1, const char *s2);   // C++ only
        //char *strstr(char *s1, const char *s2);              // C++ only

        //cout << " test--- strstr ---\n";
        const char *str1 = "Borland International", *str2 = "nation", *ptr;
        ptr = strstr(str1, str2);
        printf("The substring is: %s\n", ptr);
        ptr = strStr(str1, str2);
        printf("The substring is: %s\n", ptr);
        const char* cptr = strStr(str1, str2);
        printf("The substring is: %s\n", cptr);
        }

    // --- 字符串 ----
        {   /// just a test for C array.
//        cout << " 数字流与数组声明\n";
//        int     a1[];// error --a1[0],error
//        int     n = 10, a2[n];//[C++ Error]  E2313 Constant expression required
//        int     a3[10+1] = { 0 };// okokok
//        int     a4[3] = { 1, 2, 3, 4 };// error out越界
        }

        {
        using namespace testString;
        cout << " --查找一个字符串中连续出现次数最多的子串--\n";
        string  str="1223333444455555";
        cout << str.substr(4, 1)<<"\n";
        pair<int,string>    rs;
        rs = findMostSubstr(str);
        cout << " substr:" <<rs.second << ", maxcount:" << rs.first << "\n";
        }
    ///*
        {
        cout << " 字符子串问题 --- \n";
        cout << " Enter the numbers: ";
        string  str;
        char    reschar[50];
        reschar[0] = '\0';
        getline(cin, str);
        int     len = str.length();
        int     count = 1;
        int     i;
        for(i=0;i<len;i++)
            if(str[i+1]==str[i])
                count++;
            else
            {
                sprintf(reschar+strlen(reschar),"%c%d", str[i],count);
                count = 1;
            }
        if(str[i]==str[i-1])
            count++;
        else
            count = 1;
        cout << " str[i]"<<str[i] <<"\n";
        sprintf(reschar+strlen(reschar),"%c%d", str[i],count);
        cout << " reacahr : "<< reschar <<"\n";

        }

    ///*
        {
        // --- test 字符数组传参是否改变为一般字符指针，改变---
        using namespace testSizeof;
        char    str[10];
        sizeofFuncParam test;
		test(str, str);
        }
        { // --- test error .....
        cout << " --- 字符数组越界问题 ---\n";
        #define MAX_SIZE 255
        char    p[MAX_SIZE+1];
        unsigned char    ch; // char: -127 ... 128, unsigned char 0...255
        for(ch=0;ch<MAX_SIZE;ch++)//char ch, ch<=MAX ==> true,error !!
        {
            p[ch] = ch; //
            cout << p[ch] << " ";
        }
        cout << "\n ch: " << (int)ch << " ";
        }
    ///*
        { // --- 连续字符串（前短后长）拷贝的覆盖现象 ----
        cout << " --- 连续字符串（前短后长）拷贝的覆盖现象 ---\n";
        char    str2[] = "0123456789";
        char    str1[] = "01234";
        cout << " str1: " <<str1 <<"\n";
        cout << " str2: " <<str2 <<"\n";
        cout << " &str1: " <<(&str1) <<"\n";
        cout << " &str1[strlen(str1)-1]: " <<&str1[strlen(str1)-1] <<"\n";
        cout << " &str2: " <<(&str2) <<"\n";
        cout << " &str2[strlen(str2)-1]: " <<&str2[strlen(str2)-1] <<"\n";
        cout << " ... strcpy(str1, str2); ... \n";
        //strcpy(str1, str2);// error !
        cout << " str1: " <<str1 <<"\n";
        cout << " str2: " <<str2 <<"\n";
        }
        {
        cout << "  --- test 拷贝，循环移动 字符串 ----\n";
        char    str1[] = "0123456789", str2[11], str3[20];
        Strcpy(str3, Strcpy(str2, str1) );
        cout << "str1: " << str1 << "\n";
        cout << "str2: " << str2 << "\n";
        cout << "str3: " << str3 << "\n";
        //char    *pNull = NULL;
        //Strcpy(str1, pNull);// error !!! assert(...)
        loopMoveStr(str1, 14);
        cout << " loopMoveStr(str1, 14);str1: " << str1 << "\n";
        loopMoveStr(str1, -14);
        cout << " loopMoveStr(str1, -14);str1: " << str1 << "\n";
        loopMoveStr_(str1, 4);
        cout << " loopMoveStr_(str1, 4);str1: " << str1 << "\n";
        loopMoveStr_(str1, -4);
        cout << " loopMoveStr_(str1, -4);str1: " << str1 << "\n";
        loopMoveStr_(loopMoveStr_(str1, -4), 4);
        cout << " loopMoveStr_(loopMoveStr_(str1, -4), 4);str1: " \
             << str1 << "\n";
        cout << strRotate(str1, 14) << "\n";
        }

   ///*
    // --- test 虚函数与构造函数之间的关系 -----
        {
        cout << " --- test 虚函数与构造函数之间的关系 -----\n";
        using namespace testVirFunCtor;
        D d;
        A*  pA = new B;
        B*  pB = new C;
        C*  pC = new D;
        pA->virFun().fun();
        pB->virFun();
        pC->virFun();

        delete pA;
        delete pB;
        delete pC;
        }
    // --- test 初始化列表的初始化变量顺序 -----
        {
        cout << " --- test 初始化列表的初始化变量顺序 ----\n";
        using namespace testInitMemOrder;
        A   a1, a2(10);
        B   b1, b2(10);
        a1.printA();
        a2.printA();
        b1.printB();
        b2.printB();
        // ...
        C   c1 = Play()(5);
        C   c2;
        c2 = c1;
        }
        // --- test 友元函数 ，模板类 -----
        {
        cout << " --- test 友元函数 ，模板类 -----\n";
        using namespace testFriMemTemplateClass;
        Test<int>    t(999);
        cout << t;
        }
    ///*
    // ---- 循环、递归与概率 ----
        //cout << " ----------循环、递归与概率 ---------------------\n";
        {
        cout << " ----------循环、递归 ---------------------\n";
        cout << std::dec;// 恢复十进制---
        cout << " f1(1, 5) = " << f1(1, 5) << "\n";
        cout << " f1(10, 1) = " << f1(10, 1) << "\n";
        cout << " f1(5, 5) = " << f1(5, 5) << "\n";
        cout << " f1(10, 10) = " << f1(10, 10) << "\n";
        cout << " f2(1, 5) = " << f2(1, 5) << "\n";
        cout << " f2(10, 1) = " << f2(10, 1) << "\n";
        cout << " f2(5, 5) = " << f2(5, 5) << "\n";
        cout << " f2(10, 10) = " << f2(10, 10) << "\n";
        }
        {
        cout << " ----------螺旋队列问题 ---------------------\n";
        int     x, y;
        for(y=-4;y<=4;y++)
        {
            for(x=-4;x<=4;x++)
                printf(" %5d", Foo(x, y));
            printf("\n");
        }

        }
        {
        cout << " ----------概率 ---------------------\n";
        #define LOOP 1000
        int     rgnC = 0;
        time_t  t;
        srand( time(&t) );
        for(int i=0;i<LOOP;i++)
        {
            int     x, y;
            x = y = rand();
            if(x*x+y*y<RAND_MAX*RAND_MAX)
                rgnC++;
        }
        printf(" rgnC = %d", rgnC);//700~800
        }

    /*  **********************************************************  */
    cout << "\n\n\n\n       Hello, World !" << endl;
    system("pause");
    return 0;
}
//---------------------------------------------------------------------------
