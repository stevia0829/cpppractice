#include"test2.h"
#include"point.h"
using namespace std;

class date
{
public:
	date(int m,int d,int y);
	void print();
private:
	int month, day, year;

};

date dates[4] = {date(7,7,2020),date(8,29,1997),date(2,1,2010),date(7,10,2001)};
date::date(int m,int  d,int y)
{
	month = m;
	day = d;
	year = y;
}

void date::print()
{
	cout << month << "\t" << day << "\t" << year << endl;
}

int main() {
	int i;
	for (int i = 0; i < 4; i++)
	{
		dates[i].print();
	}
	complex ob;
	complex ob1(1.1);
	complex ob2(1.1, 2.2);
	cout << "abs of complex ob1=" << ob1.abscomplex() << endl;
	cout << "abs of complex ob2=" << ob2.abscomplex() << endl;
	cout << "abs of complex ob3=" << ob.abscomplex() << endl;
	point p1(1.1, 2.2);
	p1.showpoint();
	point p2(p1);
	p2.showpoint();
	system("pause");
	
}