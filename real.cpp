#include "real.h"
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>

#define max(x, y) ((x > y) ? x : y)
using namespace std;

real::real(double number, double error)
{
	num=number;
	err=error;
}

class real real::operator + (class real rhs)
{
	return real(number()+rhs.number(), error()+rhs.error());
}

class real real::operator - (class real rhs)
{
	return real(number()-rhs.number(), error()+rhs.error());
}

class real real::operator * (class real rhs)
{
	double answer=number()*rhs.number();
	return real(answer, answer*((error()/number()) + (rhs.error()/rhs.number())));
}

class real real::operator / (class real rhs)
{
	double answer=number()/rhs.number();
	return real(answer, answer*((error()/number()) + (rhs.error()/rhs.number())));
}

int real::operator == (class real rhs)
{
	if (abs(number()-rhs.number()) <= error() || abs(number()-rhs.number()) <= rhs.error()) 
		return 1;
	else
		return 0;
}

real::operator string()
{
	char *n=NULL;
	char *e=NULL;
	asprintf(&n, "%F", number());
	asprintf(&e, "%F", error());
	string n_s(n), e_s(e);
	string ret=n_s+"±"+e_s;
	free(n);
	free(e);
	return ret;
}

void real::operator = (class real rhs)
{
	error(rhs.error());
	number(rhs.number());
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
