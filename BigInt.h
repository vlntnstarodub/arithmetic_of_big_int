#pragma once
#include <string>
#include <vector>
#include <iostream>


class Mult;

class BigInt {
public:
	BigInt()=default;
	BigInt(int num);
	BigInt(const std::string & s);
	friend std::ostream & operator << (std::ostream & os, const BigInt & num);
	friend std::istream & operator >> (std::istream & is, BigInt & num);
	BigInt operator + (const BigInt& other);
	BigInt operator - (const BigInt& other);
	BigInt operator * (const BigInt& other);
	static void setMultMethod(Mult *mult) noexcept;
	friend class Mult;
	friend class SchoolMult;
	friend class Karatsuba;
private:
	static const int base = 10;
	void removeLeadingZeros();
	static Mult *m;
	BigInt multy10(int n);
	std::vector<int> numbers;
};