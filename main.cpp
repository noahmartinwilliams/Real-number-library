#include <iostream>
#include <assert.h>
#include "real.h"
#include <cmath>

using namespace std;

int main()
{
	real a(1.0, 0.0), b(1.0, 0.0), c(0.0, 0.0);
	assert(a==b);
	a=real(1.0, 2.0)+real(1.0, 1.0);
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
	return 0;
}
