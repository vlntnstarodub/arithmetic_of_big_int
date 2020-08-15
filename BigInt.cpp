#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "BigInt.h"
#include "Mult.h"

using namespace std;

Mult* BigInt::m = nullptr;

BigInt::BigInt(const string & s) {
	for (int i = s.length(); i > 0; i --) {
		this->numbers.push_back(atoi(s.substr(i - 1, 1).c_str()));
	}
	this->removeLeadingZeros();
}

void BigInt::setMultMethod(Mult * mult) noexcept
{
	m = mult;
}

void BigInt::removeLeadingZeros() {
	while (this->numbers.size() > 1 && this->numbers.back() == 0) {
		this->numbers.pop_back();
	}
}
BigInt::BigInt(int num) {
	do {
		this->numbers.push_back(num%BigInt::base);
		num /=BigInt::base;
	} while (num != 0);
	this->removeLeadingZeros();
}
istream & operator >> (istream & is, BigInt & num) {
	string s;
	is >> s;
	num = BigInt(s);
	return is;
}
ostream & operator << (ostream & os, const BigInt & num) {
	if (num.numbers.empty()) os << 0;
	for (int i = num.numbers.size()-1; i >= 0; --i) {
		os << num.numbers[i];
	}
	return os;
}
BigInt BigInt::operator + (const BigInt& other) {
	int move = 0;
	BigInt result;
	//result.numbers.resize(max(this->numbers.size(), other.numbers.size()) + 1);
	for (size_t i = 0; i < max(this->numbers.size(), other.numbers.size())/*|| move*/; ++i) {
		if (result.numbers.size() == i) result.numbers.push_back(0);
		result.numbers[i] = this->numbers[i] + move + (i < other.numbers.size() ? other.numbers[i] : 0);
		move = (result.numbers[i] >= BigInt::base);
		if (move) result.numbers[i] -= BigInt::base;
	}
	if (move) result.numbers.push_back(1);
	return result;
}
BigInt BigInt::operator - (const BigInt& other) {
	int move = 0;
	BigInt result = *this;
	for (size_t i = 0; i < other.numbers.size() || move; ++i) {
		result.numbers[i] = this->numbers[i] - (move + (i < other.numbers.size() ? other.numbers[i] : 0));
		move = (result.numbers[i] < 0);
		if (move) result.numbers[i] += BigInt::base;
	}
	result.removeLeadingZeros();
	
	return result;
}

BigInt BigInt::operator * (const BigInt& other) {
	
	return m->mult(*this, other);
	//return BigInt();
}
BigInt BigInt::multy10(int n) {
	BigInt res;
	//res.numbers.resize(this->numbers.size() + n);
	for (int i = 0; i < n; i++) {
		res.numbers.push_back(0);
	}
	for (int i = n + 1, j = 0; j < this->numbers.size(); i++, j++) {
		res.numbers.push_back(this->numbers[j]);
	}
	return res;
}