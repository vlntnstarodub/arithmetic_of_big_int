#pragma once
#include "Mult.h"

class Karatsuba : public Mult {
	// ������������ ����� Mult
	virtual BigInt mult(const BigInt first, const BigInt second) override;
};