#include "Karatsuba.h"
#include <algorithm>

using namespace std;

BigInt Karatsuba::mult(const BigInt first,const BigInt second){
	BigInt result;

	BigInt first_ = first;
	BigInt second_ = second;
	first_.removeLeadingZeros();
	second_.removeLeadingZeros();
if (first_.numbers.size() < 2 && second_.numbers.size() < 2) {
	return first_.numbers[0] * second_.numbers[0];
}
else {
	
	if (first_.numbers.size() % 2) first_.numbers.push_back(0);
	if (second_.numbers.size() % 2) second_.numbers.push_back(0);
	int m = max(first_.numbers.size(), second_.numbers.size());
	int n = (m / 2);
	first_.numbers.resize(m);
	second_.numbers.resize(m);
	BigInt a1;
	for (int i = n; i <= first_.numbers.size() - 1; ++i) {
		a1.numbers.push_back(first_.numbers[i]);
	}
	BigInt a0;
	for (int i = 0; i <= n - 1; ++i) {
		a0.numbers.push_back(first_.numbers[i]);
	}
	BigInt b1;
	for (int i = n; i <= second_.numbers.size() - 1; ++i) {
		b1.numbers.push_back(second_.numbers[i]);
	}
	BigInt b0;
	for (int i = 0; i <= n - 1; ++i) {
		b0.numbers.push_back(second_.numbers[i]);
	}
	
	BigInt a0b0 = mult(a0, b0);
	BigInt a1b1 = mult(a1, b1);
	BigInt a0a1 = a0 + a1;
	BigInt b0b1 = b0 + b1;
	BigInt a0a1b0b1 = mult(a0a1, b0b1);
	result = a1b1.multy10(m) + (a0a1b0b1 - a0b0 - a1b1).multy10(n) + a0b0;
	result.removeLeadingZeros();
	return result;
}
}
