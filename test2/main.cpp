//---------------------------------------------------------------------------

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <typeinfo>
#include "unit1.h"
#include <Windows.h>
#include "unit2.h"
#include <cassert>
//#include "Base64.h"


using namespace std;

void func(int i )//(int& i )
{
    i += 2;
    cout << i << ",  ";
}
void printi(int i)
{
    cout << i << ",  ";
}
//---------------------------------------------------------------------------
#define  Bin0000 0x00
#define  Bin0001 0x01
#define  Bin0010 0x02
#define  Bin0011 0x03
#define  Bin0100 0x04
#define  Bin0101 0x05
#define  Bin0110 0x06
#define  Bin0111 0x07
#define  Bin1000 0x08
#define  Bin1001 0x09
#define  Bin1010 0x0A
#define  Bin1011 0x0B
#define  Bin1100 0x0C
#define  Bin1101 0x0D
#define  Bin1110 0x0E
#define  Bin1111 0x0F
#define  HEX_MK(x,y) (unsigned char)  ((x<<4) + y)
#define  BIN_MK_4(x1,x2,x3,x4)  Bin##x1##x2##x3##x4
#define  BIN_2(x,y)  HEX_MK(Bin##x,Bin##y)
#define  BIN_8(x1,x2,x3,x4,y1,y2,y3,y4)  \
         HEX_MK( BIN_MK_4(x1,x2,x3,x4), BIN_MK_4(y1,y2,y3,y4)  )
//end--------------------------------------------
#define UNARYSHOW(X) std::cout << #X << "\n";
#define BINARYSHOW(X,Y) std::cout << #X#Y << "\n";


int main(int argc, char* argv[])
{

    TestPokerLicensing();
    /***
    {
    // test 全排列与全组合
    Permute("12345");
    Combine("12345");
    }
    /**
    {
        cout << hex;
        unsigned char v;
        v = BIN_8(1,0,1,1,1,1,0,1);
        cout << (int)v << ", ";
        v = BIN_2(1011, 0000);
        cout << (int)v << "\n";
        cout << dec;
        UNARYSHOW(!@#$%^&*()_+|);
        BINARYSHOW(~!@#$%^&*_+|,|+_*&^%$#@!~);
    }

///*
    //enum _5Bit { _5bMin=00001u, _5bMax=11111u };
    {
        // test cout's member function
        cout << hex;// 十六进制
        cout << 0x1111 << "\n";
        cout << oct;//八进制
        cout << 0x1111 << "\n";
        cout << dec;//十进制
        cout << 0x1111 << "\n";
        cout << uppercase << "abcdefg\n";// ...
        cout << nouppercase << "ABCDEFG\n";// ...
        cout << showpos << 1111 << ", " << -1111 << "\n";
        cout << noshowpos << 1111 << "\n";
        //cout << showbase << 0x1111 << "\n";
        cout << setw(10) << setfill('*') << 1111 << "\n";// << right
        cout << left << setw(10) << setfill('*') << 1111 << "\n";
        float f = 1111;
        cout << f << ", " << showpoint << f << "\n";
        cout << setprecision(8) << f << "\n"; //小数点前后8位（左至右）
        cout << scientific << f << "\n"; // 小数点后8位
        cout << setprecision(6);// default ...
        cout << setbase(10); // cout << dec;//十进制
        cout << endl;// ends, flush;
    }
    {
        // test ... AllFactorials,Factorial
        int* results = NULL;
        results = AllFactorials(5);
        assert (results);
        cout << " AllFactorials(5): " << "\n";
        int* tmp = results;
        for(int i=0; i<=5; ++i)
            cout << *(tmp++) << " ";
        cout << "\n";
        delete[] results;
        cout << " Factorial(4): " << Factorial(4) << "\n";
        cout << " Factorial(18):" << Factorial(18) << "\n";
    }
///*
    {
        ofstream    fout("0-1000素数.txt");
        const int   N = 1000;
        fout << "\n ------------------ Prime_1 --------------------- \n";
        for(int i=2; i<=N; i++)
            if(Prime_1(i))
                fout << i << " ";
        fout << "\n ------------------ Prime_2 --------------------- \n";
        for(int i=2; i<=N; i++)
            if(Prime_2(i))
                fout << i << " ";
        fout << "\n ------------------ Prime_3 --------------------- \n";
        for(int i=2; i<=N; i++)
            if(Prime_3(i))
                fout << i << " ";
        fout << "\n ------------------ Prime_4 --------------------- \n";
        fout << 2 << " " << 3 << " " << 5 << " ";
        for(int i=2; i<=N; i++)
            if(Prime_4(i))
                fout << i << " ";
        fout << "\n ------------------ Prime_5 --------------------- \n";
        fout << 2 << " " << 3 << " " << 5 << " ";
        for(int i=2; i<=N; i++)
            if(Prime_5(i))
                fout << i << " ";
        fout.close();

        time_t t;
        srand(time(&t));
        vector<int> iVec;
        cout << " Sample_0(iVec, 10, 100);\n";
        Sample_0(iVec, 10, 100);
        copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " ") );
        cout << "\n";
        iVec.clear();
        cout << " Sample_1(iVec, 10, 100);\n";
        Sample_1(iVec, 10, 100);
        copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " ") );
        cout << "\n";
        iVec.clear();
        cout << " Sample_2(iVec, 10, 100);\n";
        Sample_2(iVec, 10, 100);
        copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " ") );
        cout << "\n";
        iVec.clear();
        cout << " Arrange(iVec, 10, 10);\n";
        Arrange(iVec, 10, 10);
        copy(iVec.begin(), iVec.end(), ostream_iterator<int>(cout, " ") );
        cout << "\n";
    }
///*
//	{ ////控制CPU占用率-- 观察任务管理器
// 	// 111111
// 	for(;; )
// 	{
// 		for(int i=0; i<9600000; i++)
// 			;
// 		Sleep(10);
// 	}

// 	// 22222222
// 	unsigned int busytime = 10;
// 	unsigned int idletime = busytime;
// 	long   starttime = 0;
// 	while(true)
// 	{
// 		starttime = GetTickCount();
// 		// busy loop
// 		while( (GetTickCount()-starttime)<=busytime)
// 			;
// 		Sleep(idletime);
// 	}

// 	// 333333333    C# code 利用 Performan.exe
// 	void MakeUsage(float level)
// 	{
// 		PerformanceCounter  p = new PerformanceCounter("Processor",
// 			"%ProcessorTime:", "_Total");
// 		while(true)
// 		{
// 			if(p.NextValue() > level)
// 				Sleep(10);
// 		}
// 	}

    //44444444444--CPU 利用率正弦曲线
//     const double SPLIT = 0.01;
//     const int   COUNT =  200;
//     const double PI = 3.14159265;  // CONUT * SPLIT * PI = 2PI -> 一周
//     const int INTERVAL = 100; //正弦周期
//     int half = INTERVAL/2;
//     double  radian = 0.0;
//     DWORD   busyspan[COUNT], idlespan[COUNT];
//     for(int i=0; i<COUNT; i++)
//     {
//         busyspan[i] = (DWORD)(half+(sin(PI*radian)*half));
//         idlespan[i] = INTERVAL - busyspan[i];
//         radian += SPLIT;
//     }
//     DWORD   starttime2 = 0;
//     int j =0;
//     while(true)
//     {
//         j = j%COUNT;
//         starttime2 = GetTickCount();
//         while( (GetTickCount()-starttime2)<=busyspan[j] )
//         {
//            ;// busy !!!
//         }
//         Sleep(idlespan[j]);// idle !!!!
//         j++;
//     }
// 	}
//*
    {
        using namespace MySpace;
        String  str = "A test for the class String.";
        cout << " str:" << str << endl;

        int i, j;
        i = 8, j =10;
        printf("i = 8, i =10; \n" );
        printf("ptintf : i = %d, j = %d, ++i = %d, j++ = %d \n", i, j, ++i, j++ );
        //输出   i = 9,  j = 11, ++i = 9, j++ = 10 --调用printf 函数 从右往左入栈
        i = 8, j =10;
        cout <<"cout << : i = " << i << ", j = " << j
             << ", ++i = " << ++i << ", j++ = " << j++ <<endl;
        //输出   i = 9,  j = 11, ++i = 9, j++ = 10 --调用cout << 函数 从右往左入栈

        char buffer[] = "Hello world\n";
        printf("Buffer before memset: %s\n", buffer);
        memset(buffer, '*', strlen(buffer) - 1);
        printf("Buffer after memset:  %s\n", buffer);

        char words[] = " Hello,  World !";
        cout << words <<endl;
        ReverseWords(words);
        cout << words <<endl;
        int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        MValue	mValue;
        if (SearchMaxMin1(a, 5, 9, mValue) )
            cout << "---OKOKOK---\n";
        else
            cout << "---NONONO---\n";
        cout << mValue;
        cout << SearchMaxMin2(a, 5, 9 );
    }
///*
    {

        using namespace MySpace;
//   MyString::SetObjectNum(0);
        char *m ="M M M M M M M M ",*n="N N N N N N N N ";
        MyString cMS(m);
        MyString dMS(n);
        MySpace::String*		pStr = new MySpace::String(dMS);
        cout << cMS.Getstr() << endl;
        cout << dMS.Getstr() << endl;
        cout << pStr->Getstr() << endl;
        cout << MySpace::MyStrCat(cMS, dMS);//
        cMS += dMS;
        cout << "cMS += dMs : " << cMS;
        cMS = cMS;
        cout << "cMS = cMs : " << cMS;
        cMS = MyString("1111111") ;
        cout << "cMS = cMs : " << cMS;
        cout << MyString(NULL);

        MySpace::String	 sStr("1111111111");
        cout << sStr;
        cout << MySpace::String("222222222222") ;//????? VC Bug !???

        MyString eMS(dMS);
        cout << "static MyString::ObjectNum = " << dMS.GetObjectNum() <<endl;
        cout << eMS;
        if( eMS==dMS)
            cout << "eMS == dMS \n";
        else
            cout << "eMS != dMS \n";

        if( eMS==cMS)
            cout << "eMS == cMS \n";
        else
            cout << "eMS != cMS \n";
        cout << (eMS = cMS) ;

        if( eMS==cMS)
            cout << "eMS == cMS \n";
        else
            cout << "eMS != cMS \n";

        cout << "MyString TestCopyConstructor(MyString str1, MyString str2) "
             << TestCopyConstructor(MyString("11111"), MyString("22222"));
        //using namespace MySpace;
        MySpace::String	*Str =new MySpace::String(cMS);
        cout << *Str ;
        cout << MySpace::String(*Str);//!!!!!!!!!!?????

        MySpace::String  *Str1 = new MySpace::String("123344");
        cout << *Str1;
        MyString *str1;
        str1 = Str1;

        Str1->Print1();
        str1->Print1();
        Str1->Print2();
        str1->Print2();
        Str1->Print3(1.0);
        Str1->Print3(1);
        str1->Print3(1);

    }
//*
    {
        using namespace MySpace;
        Derive	derive;
        derive.SetiBase(1111, 1);
        derive.SetiBase(2222, 2);
        derive.SetiBase(3333, 3);
        derive.Print();

        MyString *MSstr = new MySpace::String("111111");
        cout << *MSstr;
        MSstr->Print1();

        MySpace::String* Str = dynamic_cast<MySpace::String*>(MSstr);
        if(Str)
            cout << " Str =dynamic_cast<String*>(MSstr) Succeed !\n";
        else
            cout << " Str =dynamic_cast<String*>(MSstr) Failed !\n";

        if(typeid(*Str)==typeid(MySpace::String))
            cout << " (typeid(*Str)==typeid(MySpace::String)) Succeed !\n";
        else
            cout << " (typeid(*Str)==typeid(MySpace::String)) Failed !\n";
        if(typeid(*Str)==typeid(MyString))
            cout << " (typeid(*Str)==typeid(MyString)) Succeed !";
        else
            cout << " (typeid(*Str)==typeid(MyString)) Failed !";
        delete MSstr;
        //测试C++ 中新定义的关键字 typeid 和 dynamic_cast

        D2  *d2 = new MI2 ; //??????????
        MI2* mi2 = dynamic_cast<MI2*>(&(*d2));
        if(mi2)
            cout << " mi2 = dynamic_cast<MI2*>(d2) Succeed !\n";
        else
            cout << " mi2 = dynamic_cast<MI2*>(d2) Failed !\n";
        D1* d1 = dynamic_cast<D1*>(d2);
        if(d1)
            cout << " d1 = dynamic_cast<D1*>(d2) !\n";
        else
            cout << " d1 = dynamic_cast<D1*>(d2) !\n";

        if(typeid(*d2)==typeid(MI2))
            cout << " *typeid(*d2)==typeid(MI2))  Succeed !\n";
        else
            cout << " typeid(*d2)==typeid(MI2))  Failed !\n";
        if(typeid(*d2)==typeid(MI1))
            cout << " typeid(*d2)==typeid(MI1))  Succeed !\n";
        else
            cout << " typeid(*d2)==typeid(MI1))  Failed !\n";
        if(typeid(*d2)==typeid(D2))
            cout << " typeid(*d2)==typeid(D2)) Succeed !\n";
        else
            cout << " typeid(*d2)==typeid(D2))  Failed !\n";
        delete d2;
    }
    // ******
    {
        const int *iConstNum = new int(0);
        int *iNum = new int(5);
        cout << *iConstNum << endl;
        iNum = const_cast<int*>(iConstNum) ;  //  iNum = 5
        //iNum = iConstNum;  //error !!!! [C++ Error] Main.cpp(73): E2034 Cannot convert 'const int *' to 'int *'
        cout << *iConstNum << endl;
        cout << *iNum << endl;
        iNum = new int(5);
        cout << *iNum << endl;

        double *d1 = reinterpret_cast<double*>(iNum);
        cout << *d1 <<endl;
        delete d1;
        double *d2 = new double(1);
        cout << *d2 <<endl;
        delete d2;

    }
    /************************************************************************/
    cout << " Hello, World !\n";
//---------------------------------------------------------------------------
    getch();
    return 0;
}
//---------------------------------------------------------------------------
