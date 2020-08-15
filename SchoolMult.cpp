#include "SchoolMult.h"

using namespace std;

BigInt SchoolMult::mult(const BigInt first, const BigInt second) {
	BigInt result;
	result.numbers.resize(first.numbers.size() + second.numbers.size());
	for (size_t i = 0; i < first.numbers.size(); ++i) {
		int move = 0;
		for (size_t j = 0; j < second.numbers.size() || move; ++j) {
			long long cur = result.numbers[i + j] + first.numbers[i] * 1LL * (j < second.numbers.size() ? second.numbers[j] : 0) + move;
			result.numbers[i + j] = static_cast<int>(cur%BigInt::base);
			move = static_cast<int>(cur/ BigInt::base);
		}
	}
	result.removeLeadingZeros();
	return result;

}