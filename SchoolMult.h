#pragma once
#include "Mult.h"

class SchoolMult: public Mult {
	// ������������ ����� Mult
	virtual BigInt mult(const BigInt first, const BigInt second) override;
};