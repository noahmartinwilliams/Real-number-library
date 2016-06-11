#ifndef __REAL_H__
#define __REAL_H__

#ifdef ARDUINO
#include "Arduino.h"
#endif
#ifndef ARDUINO
#include <string>
#define String string
using namespace std;
#endif


class real {
	public:
		real(double number, double error);
		real(volatile class real&);
		real(const class real& r);
		real(class real& r);
		real(double d);
		real();
		class real combine(class real rhs);
		operator String();
		void operator = (class real rhs);
		void operator = (double d);
		int operator == (class real rhs);
		class real operator + (class real rhs);
		class real operator + (double d);
		class real operator - (class real rhs);
		class real operator - ();
		class real operator * (class real rhs);
		class real operator / (class real rhs);
		void operator += (double d);
		int operator > (class real rhs);
		int operator < (class real rhs);
		int operator > (int i);
		double error();
		void error(double in);
		double number();
		void number(double in);
	private:
		double num, err;
};
#undef String

#endif
