#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

void swap(int *x, int*y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

char *max(char *a, char *b)
{
	return(strcmp(a, b) ? a : b);
}
int main()
{
	int a = 1;
	int *p1 = &a;
	void *p2 = p1;
	int *p3 = (int *)p2;
	cout << "*p3= " << *p3 << endl;
	const int *p4;
	int * const p5 = &a;
	const int *const p6 = &a;
	cout << "*p5= " << *p5 << endl;
	cout << "*p6= " << *p6 << endl;
	char *p7;
	p7 = max("hello", "good");
	cout << p7 << endl;
	system("pause");
}