#ifndef ARDUINO 
#include <iostream>
#include <assert.h>
#include "real.h"
#include <cmath>

using namespace std;
const double max_error=0.01;

int main()
{
	real a(1.0, 0.0), b(1.0, 0.0), c(0.0, 0.0);
	assert(a==b);
	a=real(1.0, 2.0);
	b=real(1.0, 1.0);
	a=a+b;
	assert(abs(a.error()-3.0) < 0.01);

	a=real(1.0, 2.0)-real(1.0, 1.0);
	assert(abs(a.error()-3.0) < 0.01);

	a=real(1.0, 2.0)*real(5.0, 2.0);
	assert(abs(a.number()-5.0) < 0.01);
	assert(abs(a.error() - 5.0*2.4) < 0.01);

	a=real(1.0, 2.0)/real(5.0, 2.0);
	assert(abs(a.number()-0.2) < 0.01);
	assert(abs(a.error() - 0.2*2.4) < 0.01);

	a=real(1.0, 1.0);
	b=real(1.5, 1.0);
	assert(a > b);
	assert( b < a);

	a=real(1.0, 1.0);
	b=real(1.5, 0.5);
	a=a.combine(b);
	assert(abs(1.5-a.number()) <= max_error);
	assert(abs(0.5-a.error()) <= max_error);
	return 0;
}
#endif
