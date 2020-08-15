#pragma once
#include "BigInt.h"

class Mult{
public:
	virtual BigInt mult(const BigInt first, const  BigInt second) = 0;
};