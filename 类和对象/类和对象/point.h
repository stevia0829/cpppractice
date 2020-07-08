#include<iostream>
using namespace std;
class point
{
public:
	point(point &p);
	point(double x,double y);
	void showpoint();
private:
	double fx, fy;

};

point::point(point &p)
{
	fx = p.fx + 10;
	fy = p.fy + 10;
}

point::point(double x,double y)
{
	fx = x;
	fy = y;
}
void point::showpoint() {
	cout << fx << " " << fy << endl;
}
