#pragma once
#include<math.h>


class complex
{
	double real, imag;
public:
	complex(double real = 0, double imag = 0);//默认参数
	double abscomplex();
};

complex::complex(double r, double i) //构造函数
{
	real = r;
	imag = i;
}

double complex::abscomplex()// 成员函数
{
	double n;
	n = real * real + imag * imag;
	return sqrt(n);
}
