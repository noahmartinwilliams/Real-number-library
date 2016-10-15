#ifndef ARDUINO 
#include <iostream>
#include <assert.h>
#include "real.h"
#include <cmath>

using namespace std;
const double max_error=0.01;
const double pi=3.141592;

void test_equality()
{
	real a(1.0, 0.0), b(1.0, 0.0);
	assert(a==b);
}

void test_addition()
{
	class real a(1.0, 2.0), b(1.0, 1.0);
	a=a+b;
	assert(abs(a.error()-3.0) < 0.01);
}

void test_subtraction()
{
	class real a(0.0, 0.0);
	a=real(1.0, 2.0)-real(1.0, 1.0);
	assert(abs(a.error()-3.0) < 0.01);
}

void test_multiplication()
{
	class real a(0.0, 0.0);
	a=real(1.0, 2.0)*real(5.0, 2.0);
	assert(abs(a.number()-5.0) < 0.01);
	assert(abs(a.error() - 5.0*2.4) < 0.01);
}

void test_division()
{
	class real a(0.0, 0.0);
	a=real(1.0, 2.0)/real(5.0, 2.0);
	assert(abs(a.number()-0.2) < 0.01);
	assert(abs(a.error() - 0.2*2.4) < 0.01);

}

void test_greater_than_less_than()
{
	class real a(1.0, 1.0), b(1.5, 1.0);
	assert(a > b);
	assert( b < a);

}

void test_combine()
{
	class real a(1.0, 1.0), b(1.5, 0.5);
	a=a.combine(b);
	assert(abs(1.5-a.number()) <= max_error);
	assert(abs(0.5-a.error()) <= max_error);

}

void test_sine()
{
	class real a(pi/2.0, pi/180.0);
	a=sin(a);
	assert(abs(a.error()-0.0002) <= 0.001);
}

void test_cosine()
{
	class real a(pi/4.0, pi/180.0);
	a=cos(a);
	assert(abs(a.number()-sqrt(0.5)) <= 0.01);
	assert(abs(a.error())<= 0.02);
}

void test_atan2()
{
	class real y(1.0, 0.1), x(1.0, 0.1);
	assert(abs(atan2(y, x).error()-0.1) <= 0.01);

	y=real(-1.0, 0.1); x=real(1.0, 0.1);
	assert(abs(atan2(y, x).number()+pi/4.0) <= 0.1);
}

void test_sqrt()
{
	assert(sqrt(real(9.0, 0.0))==real(3.0, 0.0));
	assert(sqrt(real(9.0, 6.0))==real(3.0, 1.0));
}

int main()
{
	test_equality();
	test_addition();
	test_subtraction();
	test_multiplication();
	test_division();
	test_greater_than_less_than();
	test_combine();
	test_sine();
	test_cosine();
	test_atan2();
	test_sqrt();

	return 0;
}
#endif
