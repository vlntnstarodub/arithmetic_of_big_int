#pragma once
#include "Mult.h"

class SchoolMult: public Mult {
	// Унаследовано через Mult
	virtual BigInt mult(const BigInt first, const BigInt second) override;
};