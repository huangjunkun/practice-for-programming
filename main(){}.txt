
//---------------------------------------------------------------------------
    // --- 程序设计基本概念 ----
    // --- 赋值语句 ----
    cout << " ------------赋值语句-------------------\n";
    {
    int x = 2, y,  z;
    x *=(y=z=5);
    cout << x << "\n";
    z = 3;
    x==(y=z);
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
    }
//---------------------------------------------------------------------------
    {// 预定义 声明一个常熟表示一年中有多少秒
    #define SECONDS_PER_YEAR  (((__int64)60)*60*24*356 )
    cout <<  " SECONDS_PER_YEAR = "<< SECONDS_PER_YEAR <<"\n";
    cout << __int64(999999999999999)*2 << "\n";
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
    /*
    &a --->  0x0013feb0 ------- 高位  +4字节
    &b --->  0x0013feaf ------- 隔3字节 + 1字节
    &c --->  0x0013fea8 ------- 低位  +4字节
    */
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
    delete  str;   /* */
    GetMemoryRef(str, 20);
    strcpy(str, "2 .hello, world! ");
    cout << str << "\n";
    delete  str;
    /*
    int *ptr;
    ptr = (int*)0x8000;
    *ptr = 0xaaaa; // error
    cout << *ptr << "\n";// error    */
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
    cout << " ----------迷途指针 ---------------------\n";
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
