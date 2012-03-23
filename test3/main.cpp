//---------------------------------------------------------------------------

#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include <functional>
#include <iterator>
#include "base64.h"

#include <algorithm>
#include <iomanip>
#include <fstream>
#include <typeinfo>
#include <windows.h>

using namespace std;

#include ".\loki\SmartPtr.h"
#include ".\loki\Typelist.h"
#include ".\loki\HierarchyGenerators.h"

#include "unit1.h"
#include ".\loki\Threads.h"
using namespace Loki;


int main(int argc,char* argv[])
{
    {
        /// test base64 ...
        const unsigned TEST_CASE_COUNT = 10;
        const string TEST_STR[TEST_CASE_COUNT] = { "", "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999" };
        cout << " test case count:" << TEST_CASE_COUNT << "\n";
        for (size_t i = 0; i < TEST_CASE_COUNT; ++i)
        {
            string encode = Base64Encryption(TEST_STR[i]);
            string decode = Base64Decryption(encode);
            std::cout << " string:" << TEST_STR[i] << "\n";
            std::cout << " encode:" << encode << "\n";
            std::cout << " decode:" << decode << "\n";
            std::cout << " -- end --\n";
        }
    }


///*
    {
        // --- test Merge(...)---
        int     b[4] = {4, 5, 6, 7}, c[4] = {1, 2, 3, 4}, d[8];
        Merge(b, b+4, c, c+4, d, less<int>() );
        copy(d, d+8, ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";

        int     a[] = { 6, 5, 4, 3, 2, 1, 0, 7, 8, 9, 10, -1}; //
        int    *first = a, *last = a+sizeof(a)/sizeof(int);
        vector<int> iVec(first, last);
        //list<int>   iList(first, last);

        cout << " bubbleSort:\n";
        bubbleSort(first, last, less<int>() );// greater ...?
        copy(first, last, ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";
        bubbleSort(iVec.begin(), iVec.end(), greater<int>() );
        copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";
//        // complie error.
//        bubbleSort(iList.begin(), iList.end(), greater<int>() );
//        copy(iList.begin(), iList.end(), ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";
///* // error ...
//         cout << " heapSort:\n";
//         heapSort(first, last, less<int>() );// greater ...?
//         copy(first, last, ostream_iterator<int>(cout, " ") );
//         cout << "\n ----------------------------------------\n";
///* // error ...
//         cout << " mergeSort:\n";
//         mergeSort(first, last, less<int>() );// greater ...?
//         copy(first, last, ostream_iterator<int>(cout, " ") );
//         cout << "\n ----------------------------------------\n";
//         mergeSort(iVec.begin(), iVec.end(), greater<int>() );
//         copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " ") );
//         cout << "\n ----------------------------------------\n";

///*
        cout << " bubbleSort:\n";
        bubbleSort(first, last, less<int>() );// greater ...?
        copy(first, last, ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";
        bubbleSort(iVec.begin(), iVec.end(), greater<int>() );
        copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";
        cout << " selectSort:\n";
        selectSort(first, last, less<int>() );// greater ...?
        copy(first, last, ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";
        selectSort(iVec.begin(), iVec.end(), greater<int>() );
        copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";
        cout << " insertSort:\n";
        insertSort(first, last, less<int>() );// greater ...?
        copy(first, last, ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";
        insertSort(iVec.begin(), iVec.end(), greater<int>() );
        copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";
        cout << " quickSort:\n";
        quickSort(first, last, less<int>() );// greater ...?
        copy(first, last, ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";
        quickSort(iVec.begin(), iVec.end(), greater<int>() );
        copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " ") );
        cout << "\n ----------------------------------------\n";
    }
///*
    {
        long**    lPtr;
        long     temp = 999;
        //cin >> temp;
        lPtr = (long**)temp;
        cout << " temp = " << temp << "\n";
        cout << " &temp = " << &temp << "\n";
        cout << " lPtr = " << lPtr << "\n";
        //cout << " *lPtr = " << *lPtr << "\n";//error
    }
///*
    {
        long    l = 999999;
        long*    lPtr = &l;
        cout << "  lPtr = " << lPtr << "\n";
        cout << " *lPtr = " << *lPtr << "\n";
    }
///*
    { // Test std::string COW ok...
        string  str1 = "Hello, World ! ";
        string  str2 = str1;
        char*   cPtr1 = const_cast<char*>(str2.c_str() );
        cout << " cPtr1[0] " << cPtr1[0] << "\n";
        char*   cPtr2 = cPtr1;
        cout << " cPtr2[0] " << cPtr2[0] << "\n";
        cPtr2[0] = 'h';
        cout << " str1 : " << str1 << "\n";
        cout << " str2 : " << str2 << "\n";
        cout << " cPtr1 : " << cPtr1 << "\n";
        cout << " cPtr2 : " << cPtr2 << "\n";
    }

    {
        // long long interger, include 8 bytes
        __int64 ll = 1024 * 1024;
        ll = ll * 1024;
        ll = ll * 10; // ll = 10737418240
        printf( "ll = %I64d\n", ll );

        __int64 ll2 = 1024 * 1024 * 1024 * 10; // ll2 = -2147483648
        __int64 ll3 = 1024LL * 1024 * 1024 * 10; // ll2 = ??
        printf( "ll2 = %I64d\n", ll2 );
        printf( "ll3 = %I64d\n", ll3 );
    }

// /**
//   运行结果是：
//     ll = -2147483648
//     ll2 = -2147483648
//  首先是 BCB6.0/VC++6.0 不支持long long类型，微软自己定义了__int64类型。
//  其次，运行结果都错了，但你用单步调试看来变量值，ll = 10737418240，
//  是正确，那说明在 BCB6.0/VC++6.0 上printf()还只支持C89标准。
//  至于第二个结果为什么有问题呢，明显在连乘过程中，类型是按int来处理的。
//
///*

//---------------------------------------------------------------------------
///*
    {
        vector<TServerKey>  TServerKeyVec;
        ifstream    fin("test.txt");
        copy((istream_iterator<TServerKey>(fin)), istream_iterator<TServerKey>(),
             back_inserter(TServerKeyVec) );
        copy(TServerKeyVec.begin(), TServerKeyVec.end(),
             ostream_iterator<TServerKey>(cout, "\n"));
    }
//---------------------------------------------------------------------------
///*
    {
        cout << " argc : " << argc << ", sizeof(argv) : " << sizeof(argv) << endl;
        for(int i=0; i<argc; i++)
            cout << " argv[" << i << "] : " << argv[i] << endl;
    }


/////*  ---- test const ptr and ptr const 常量指针与指针常量
    {
        const int const_i = 100;
        int  non_const_i = 1000;
        const int* pconst_i = &non_const_i;
        int* pInt = const_cast<int*>(&const_i); //copy const_i
        *pInt = 99;
        cout << " const_i = " << const_i <<endl;// 100 not 99
        cout << " *pInt = " << *pInt <<endl;//  99

        pInt = &non_const_i;
        *pInt = 99;
        cout << " non_const_i = " << non_const_i <<endl;//  99

        cout << " *pconst_i = " << *pconst_i << endl;
        pInt = const_cast<int*>(pconst_i);
//   *pconst_i = 999;// [C++ Error] E2024 Cannot modify a const object
        *pInt = 999;
        cout << " *pconst_i = " << *pconst_i << endl;
//const_cast<int>(const_i) = 99;//[C++ Error]  E2024 Cannot modify a const object
    }

//---------------------------------------------------------------------------
    {
        bool     bESCDown = false;
        HANDLE   hThread1 = CreateThread(NULL, 0, IdleShowTime, &bESCDown, 0, NULL);
        HANDLE   hThread2 = CreateThread(NULL, 0, MonitorKeyEAC, &bESCDown, 0, NULL);

        WaitForSingleObject(hThread1, INFINITE);
        CloseHandle(hThread1);
        CloseHandle(hThread2);
        //::SetWindowLong(Application->Handle, GWL_EXSTYLE, WS_EX_TOOLWINDOW|WS_EX_TRANSPARENT);
    }


//---------------------------------------------------------------------------
///*
    {
        HINSTANCE hDll;
        hDll=LoadLibrary(_T("Project1.dll"));
        if (hDll!=NULL)
        {
            MyFun1 fun1;
            fun1 = (MyFun1)GetProcAddress(hDll, "c_exe_test2");
            if(fun1!=NULL)
            {
                for(int i=0; i<5; i++)
                {
                    printf("%d,%d,%d,%d\n",i,i+1,i+2,i+3);
                    printf("fun(...) return = %d\n", fun1(i,i+1,i+2,i+3));
                }
            }
            FARPROC  proc = GetProcAddress(hDll, "HelloWorld");
            proc();

            typedef char* (_stdcall *MyFun2) (char*, char*);
            MyFun2 fun2 = (MyFun2)GetProcAddress(hDll, "LinkPChar");
            char  *s1="11111", *s2="22222";
            std::string    Str = fun2(s1, s2);
            printf("%s\n", Str.c_str());
            FreeLibrary(hDll);
        }
    }

//---------------------------------------------------------------------------
    {
        const   char    c = 'a';
        cout << "const   char    c = 'a', c : " << c << endl;
        char    *pchar = const_cast<char*>(&c);
        *pchar = 'A';
        //c = 'A';
        cout << "*pchar(c) = 'A';, c : " << c << endl;
        cout << "*pchar(c) = 'A';, *pchar : " << *pchar  << endl;
        //char
        const   char*   const_ptr = "const_ptr";  //常量指针 -- 指针所指的值不能改变
        char* const   ptr_const = "ptr_const"; // 指针常量 --    指针的值不能改变
        char*    non_const_ptr = const_cast<char*>(const_ptr); //[C++ Error]  E2034 Cannot convert 'const char *' to 'char *'
//    const_ptr = const_cast<char*>(non_const_ptr);
        const_ptr = "Const_ptr";       // std::string("Const_ptr").c_str()
//    non_const_ptr[0] = 'C';
//    const_ptr[0] = 'C'; //[C++ Error]  E2024 Cannot modify a const object
        //ptr_const[0] = 'P'; //error !
//    ptr_const = "Ptr_const"; // [C++ Error]  E2024 Cannot modify a const object
        cout << "const_ptr :" << const_ptr <<endl;
        cout << "non_const_ptr :" << non_const_ptr <<endl;
        cout << "ptr_const :" << ptr_const <<endl;
        std::string  Str = "string";
        Str[1] = 'S';
        cout << Str.c_str() << endl;
        const_ptr = Str.c_str();
        //const_ptr[0] = 's';  //error
        Str[1] = 's'; // OK
        cout << const_ptr << endl;
    }

//---------------------------------------------------------------------------
    ///*
    {
        // read an integer and a float from stdin
        int i = 999;
        float f = 99.9;
        //cin >> i >> f;
        // output the integer and goes at the line
        cout << i << endl;
        // output the float and goes at the line
        cout << f << endl;
        // output i in hexa
        cout << hex << i << endl;
        // output i in octal and then in decimal
        cout << oct << i << dec << i << endl;
        // output i preceded by its sign

        cout << showpos << i << endl;
        // output i in hexa
        cout << setbase(16) << i << endl;
        // output i in dec and pad to the left with character
        // @ until a width of 20
        // if you input 45 it outputs 45@@@@@@@@@@@@@@@@@@
        cout << setfill('@') << setw(20) << left << dec << i;
        cout << endl;
        // output the same result as the code just above
        // but uses member functions rather than manipulators
        cout.fill('@');
        cout.width(20);
        cout.setf(ios_base::left, ios_base::adjustfield);

        cout.setf(ios_base::dec, ios_base::basefield);
        cout << i << endl;
        // outputs f in scientific notation with
        // a precision of 10 digits
        cout << scientific << setprecision(10) << f << endl;
        // change the precision to 6 digits
        // equivalents to cout << setprecision(6);
        cout.precision(6);
        // output f and goes back to fixed notation
        cout << f << fixed << endl;
    }

//    //---------------------------------------------------------------------------
//    // --- 多线程下的 Loki ThreadModel 的应用 ----
//    {
//        cout << "  --- test Loki Thread ClassLevelLockable Lock ---\n";
//        LockType  str;
//        // 锁定变量 .... 不同方法锁定同一变量 str
//        HANDLE  Thread1 = CreateThread(NULL,0,LockMethod::setStrDigit,&str,0,NULL);
//        HANDLE  Thread2 = CreateThread(NULL,0,LockMethod::setStrAlpha,&str,0,NULL);
//
//        // 锁定方法 .... 同一方法锁定同一变量 str    PrintStr
//        HANDLE  Thread3 = CreateThread(NULL,0,TString::PrintStr,&str,0,NULL);
//        HANDLE  Thread4 = CreateThread(NULL,0,TString::PrintStr,&str,0,NULL);
//
//
//        //    for(int i=0; i<LOOP; i++)
//        //    {
//        //        str = "ABCDEFGHIJ";
//        //        cout << str << "\n";
//        //    }
//
//        WaitForSingleObject(Thread1, INFINITE);
//        WaitForSingleObject(Thread2, INFINITE);
//        WaitForSingleObject(Thread3, INFINITE);
//        WaitForSingleObject(Thread4, INFINITE);
//        CloseHandle(Thread1);
//        CloseHandle(Thread2);
//        CloseHandle(Thread3);
//        CloseHandle(Thread4);
//    }
//    ///*
//    {
//        cout << " --- test exception throw and deconstructor 异常与析构 ---\n";
//        try
//        {
//            TestExcepDctor  test;
//            throw Exception("--- 异常与析构 ---");
//        }
//        catch(Exception& e)
//        {
//            cout << " catch : throw Exception(\"--- 异常与析构 ---\");\n";
//        }
//    }
    //---------------------------------------------------------------------------
    ///*  **********************************************************  */
    cout << "\n\n\n\n       Hello, World !" << endl;
    return 0;
}


//---------------------------------------------------------------------------




