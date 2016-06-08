#ifndef __REAL_H__
#define __REAL_H__

#include <string>
using namespace std;

class real {
	public:
		real(double number, double error);
		class real combine(class real rhs);
		operator string();
		void operator = (class real rhs);
		int operator == (class real rhs);
		real operator + (class real rhs);
		real operator - (class real rhs);
		real operator * (class real rhs);
		real operator / (class real rhs);
		int operator > (class real rhs);
		int operator < (class real rhs);
		double error();
		void error(double in);
		double number();
		void number(double in);
	private:
		double num, err;
};

#endif
