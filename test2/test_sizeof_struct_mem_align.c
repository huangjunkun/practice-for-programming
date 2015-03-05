struct P1
{
	int i;
	char c;
	int j;
	char d;
};

struct P2
{
	int i;
	char c;
	char d;
	int j;
};

struct P3
{
	short w[3];
	char a;
	char b;
	char d;
	double c;
};

struct P4
{
	short w[3];
	char* c[3];
};

struct P5
{
	struct P1 p1[2];
	struct P2* p_p2;
	struct P3 p_p3;
	struct P4 p4;
};

typedef struct 
{
	int a;
	int b;
} my;

enum TEST_P
{
	A = 1, 
	B = 2

};

int main()
{
	/**/
	cout << sizeof(P1) << endl;
	cout << sizeof(P2) << endl;
	cout << sizeof(P3) << endl;
	cout << sizeof(P4) << endl;
	cout << sizeof(P5) << endl;
	unsigned long long a = 123;
	unsigned long long b = 1;
	long long c = b-a;
	cout << c << endl;
	
	//my* my_a10 = (my*)malloc(sizeof(my)*10);
	//memset((void*)my_a10, 0, sizeof(my)*10);
	//my* my0 = my_a10;
	//my0->a = 1;
	//my0->b = 11;

	//my* my1 = my_a10+sizeof(my);
	//my1->a = 2;
	//my1->b = 22;

//	TEST_P * a;
//	a = new TEST_P [2];
//	memset(a, 0, sizeof(a));
//
//	cout << a[0] << " " << a[1] << endl;
//	cout << sizeof(TEST_P) * 2;
}
