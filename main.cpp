//---------------------------------------------------------------------------


#include <stdlib.h>
#include <time.h>
#include "SubUnit.h"

#
int main(int argc, char* argv[])
{
    /*
     {//test scanf ... float, loop ???
     float f1, f2[2];
     scanf("%f", &f1);
     printf(" float f1 = %f\n", f1);
     scanf("%f", &f2[0]);
     printf(" f2[0] = %f\n", f2[0]);
     }   */
    {
        int     a[4][4];
        int**   iPPtr = (int**)a;// okokok
        //int**   iPPtr = a;//error
    }
    {
        using namespace testBaiduStudy;
        cout << " Factorial(18): " << Factorial(18) << "\n";
        cout << " FactorialCount0Num_1(18): " << FactorialCount0Num_1(18) << "\n";
        cout << " FactorialCount0Num_2(18): " << FactorialCount0Num_2(18) << "\n";
        int     a[5] = {2, 4, 3, 4, 7};
        int     N = sizeof(a)/sizeof(int);
        cout << " " << *SearchNMax(a, a+N, 5, less<int>() ) << "\n";
        //cout << " " << *SearchNMax(a, a+N, 2, less<int>() ) << "\n";
        //cout << " " << *SearchNMax(a, a+N, 2, less<int>() ) << "\n";
    }
    /*
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
    /*
        {
        using namespace testInitMemOrder;
        Play    p;
        p(1);
        }

    /*
        {// test--- strstr ---
        //char *strstr(const char *s1, const char *s2);     //C only
        //const char *strstr(const char *s1, const char *s2);   // C++ only
        //char *strstr(char *s1, const char *s2);              // C++ only

        //cout << " test--- strstr ---\n";
        char *str1 = "Borland International", *str2 = "nation", *ptr;
        ptr = strstr(str1, str2);
        printf("The substring is: %s\n", ptr);
        ptr = strStr(str1, str2);
        printf("The substring is: %s\n", ptr);
        const char* cptr = strStr(str1, str2);
        printf("The substring is: %s\n", cptr);
        }

    // --- �ַ��� ----
        {
        //cout << " ����������������\n";
        //int     a1[];// error --a1[0],error
        //int     n = 10, a2[n];//[C++ Error]  E2313 Constant expression required
        int     a3[10+1] = { 0 };// okokok
        //int     a4[3] = { 1,  2, 3, 4 };// error outԽ��
        }
        {
        using namespace testString;
        cout << " --����һ���ַ������������ִ��������Ӵ�--\n";
        string  str="1223333444455555";
        cout << str.substr(4, 1)<<"\n";
        pair<int,string>    rs;
        //cin>>str;
        //cin.ignore(100, '\n');
        //while(cin>>str)
        {
            rs = fun(str);
            cout << " substr:" <<rs.second << ", maxcount:" << rs.first << "\n";
        }
        }
    /*
        {
        cout << " �ַ��Ӵ����� --- \n";
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

    /*
        {
        // --- test �ַ����鴫���Ƿ�ı�Ϊһ���ַ�ָ�룬�ı�---
        using namespace testSizeof;
        char    str[10];
        sizeofFuncParam(str, str);
        }
        { // --- test error .....
        cout << " --- �ַ�����Խ������ ---\n";
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
    /*
        { // --- �����ַ�����ǰ�̺󳤣������ĸ������� ----
        cout << " --- �����ַ�����ǰ�̺󳤣������ĸ������� ---\n";
        char    str2[] = "0123456789";
        char    str1[] = "01234";
        cout << " str1: " <<str1 <<"\n";
        cout << " str2: " <<str2 <<"\n";
        cout << " &str1: " <<(&str1) <<"\n";
        cout << " &str1[strlen(str1)-1]: " <<&str1[strlen(str1)-1] <<"\n";
        cout << " &str2: " <<(&str2) <<"\n";
        cout << " &str2[strlen(str2)-1]: " <<&str2[strlen(str2)-1] <<"\n";
        cout << " ... strcpy(str1, str2); ... \n";
        strcpy(str1, str2);// warn--error !
        cout << " str1: " <<str1 <<"\n";
        cout << " str2: " <<str2 <<"\n";
        }
        {
        cout << "  --- test ������ѭ���ƶ� �ַ��� ----\n";
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

    /*
    // --- test �麯���빹�캯��֮��Ĺ�ϵ -----
        {
        cout << " --- test �麯���빹�캯��֮��Ĺ�ϵ -----\n";
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
    // --- test ��ʼ���б�ĳ�ʼ������˳�� -----
        {
        cout << " --- test ��ʼ���б�ĳ�ʼ������˳�� ----\n";
        using namespace testInitMemOrder;
        A   a1, a2(10);
        B   b1, b2(10);
        a1.printA();
        a2.printA();
        b1.printB();
        b2.printB();
        // ...
        C   c1 = play(5);
        C   c2;
        c2 = c1;
        }
        // --- test ��Ԫ���� ��ģ���� -----
        {
        cout << " --- test ��Ԫ���� ��ģ���� -----\n";
        using namespace testFriMemTemplateClass;
        Test<int>    t(999);
        cout << t;
        }
    /*
    // ---- ѭ�����ݹ������ ----
        //cout << " ----------ѭ�����ݹ������ ---------------------\n";
        {
        cout << " ----------ѭ�����ݹ� ---------------------\n";
        cout << std::dec;// �ָ�ʮ����---
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
        cout << " ----------������������ ---------------------\n";
        int     x, y;
        for(y=-4;y<=4;y++)
        {
            for(x=-4;x<=4;x++)
                printf(" %5d", Foo(x, y));
            printf("\n");
        }

        }
        {
        cout << " ----------���� ---------------------\n";
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
