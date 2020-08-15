#include <iostream>
#include "BigInt.h"
#include "Karatsuba.h"
#include "SchoolMult.h"

using namespace std;

int main() {
	BigInt a("2222222222222222222222222222222222222"), b("1111111111111111111111111111111111"), c(10), d;
	cout << a <<endl;
	cout << b <<endl;	
	cout << a + b<< endl;
	c.setMultMethod(new Karatsuba());
	c = a * b;
	d.setMultMethod(new SchoolMult());
	d = a * b;
	//cout << b << endl;
	//c = a - b - b;
	cout << c << endl;
	cout << d << endl;
	cout << c-d << endl;
	//cout << a.mult(b) << endl;
	//BigInt b;
	system("pause");
	return 0;
}