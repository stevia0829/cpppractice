#include<iostream>

using namespace std;

class base
{
public:
	base(int xx = 0, int yy = 0)
	{
		x = xx;
		y = yy;
	};
	virtual void disp() {
		cout << "base: " << x << " " << y << endl;
	}
private:
	int x, y;
};
class base1:public base
{
public:
	base1(int xx, int yy, int zz) :base(xx, yy)
	{
		z = zz;
	};
	void disp()
	{
		cout << "base1:" << z << endl;
	}

private:
	int z;

};

int main() {
	base obj(3, 4), *objp;// 创建基类的对象和对象指针
	base1 obj1(1, 2, 5),*objp1;//创建派生类的对象
	objp = &obj;//对象指针指向基类
	objp->disp();//调用基类成员函数
	objp = &obj1;//对象指针指向派生类
	objp->disp();//调用派生类成员函数
	objp1 = &obj1;
	objp1->disp();
	system("pause");
}
