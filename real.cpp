#define __REAL_CPP__
#include "real.h"
#ifndef ARDUINO
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#define String string
using namespace std;
#else
#include "Arduino.h"
#endif

#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x > y) ? y : x)

const int num_sig_figs=3;

real::real(class real& r)
{
	err=r.err;
	num=r.num;
}

real::real(const class real& r)
{
	num=r.num;
	err=r.err;
}

real::real(double number, double error)
{
	num=number;
	err=error;
}


real::real(volatile class real& r)
{
	num=r.num;
	err=r.err;
}

class real real::operator + (class real rhs)
{
	return real(number()+rhs.number(), error()+rhs.error());
}

class real real::combine(class real rhs)
{
	double maximum=min(rhs.number()+rhs.error(), (*this).number()+(*this).error());
	double minimum=max(rhs.number()-rhs.error(), (*this).number()-(*this).error());
	return real((maximum+minimum)/2.0, (maximum-minimum)/2.0);
}

class real real::operator - (class real rhs)
{
	return real(number()-rhs.number(), error()+rhs.error());
}

class real real::operator * (class real rhs)
{
	double answer=number()*rhs.number();
	return real(answer, abs(answer)*((error()/number()) + (rhs.error()/rhs.number())));
}

class real real::operator / (class real rhs)
{
	double answer=number()/rhs.number();
	return real(answer, abs(answer)*((error()/number()) + (rhs.error()/rhs.number())));
}

int real::operator == (class real rhs)
{
	if (abs(number()-rhs.number()) <= error() || abs(number()-rhs.number()) <= rhs.error()) 
		return 1;
	else
		return 0;
}

real::operator String()
{
	#ifndef ARDUINO
	char *n=NULL;
	char *e=NULL;
	asprintf(&n, "%F", number());
	asprintf(&e, "%F", error());
	string n_s(n), e_s(e);
	string ret=n_s+"±"+e_s;
	free(n);
	free(e);
	return ret;
	#else
	return String(num, num_sig_figs)+String("±")+String(err, num_sig_figs);
	#endif
}

void real::operator = (class real rhs)
{
	error(rhs.error());
	number(rhs.number());
}

void real::operator = (double d)
{
	num=d;
	err=0.0;
}

double real::error()
{
	return err;
}

double real::number()
{
	return num;
}

void real::error(double in)
{
	err=in;
}

void real::number(double in)
{
	num=in;
}

int real::operator > (class real rhs)
{
	if ((number() + error()) > (rhs.number() - rhs.error()))
		return 1;
	else
		return 0;
}

int real::operator < (class real rhs)
{
	if ((number() - error()) < (rhs.number() + rhs.error()))
		return 1;
	else
		return 0;
}

class real real::operator + (double d)
{
	return real(number()+d, error());
}

void real::operator += (double d)
{
	num+=d;
}

real::real()
{
	num=0.0;
	err=0.0;
}

real::real(double d)
{
	num=d;
	err=0.0;
}

int real::operator > (int i)
{
	return (*this) > (double(i));
}

class real real::operator - ()
{
	return real(-number(), error());
}

class real sin(class real arg)
{
	return real(sin(arg.number())*cos(arg.error()), sin(arg.error())*cos(arg.number()));
}

class real cos(class real arg)
{
	return real(cos(arg.number())*cos(arg.error()), sin(arg.number())*sin(arg.error()));
}

class real atan2(class real y, class real x)
{
	class real ret(0.0, 0.0);
	double square=x.number()*x.number()+y.number()*y.number();
	double x_d=abs(x.number()), y_d=abs(y.number());
	ret=real(atan2(y_d, x_d), (y_d/square)*y.error()+(x_d/square)*x.error());
	return ret;
}
