#include "pch.h"
#include <iostream>
#include <crtdbg.h>
#include <span>


export module utilitytest;

#ifdef GTEST

export class MemoryLeakDetector {
public:
	MemoryLeakDetector() {
		_CrtMemCheckpoint(&memState_);
	}

	~MemoryLeakDetector() {
		_CrtMemState stateNow, stateDiff;
		_CrtMemCheckpoint(&stateNow);
		int diffResult = _CrtMemDifference(&stateDiff, &memState_, &stateNow);
		if (diffResult)
			reportFailure(stateDiff.lSizes[1]);
	}
private:
	void reportFailure(unsigned int unfreedBytes) {
		FAIL() << "Memory leak of " << unfreedBytes << " byte(s) detected.";
	}
	_CrtMemState memState_;
};

export void printAll(const std::span<const int> v)
{
	std::copy(std::begin(v), std::end(v),
		std::ostream_iterator<int>(std::cerr, ", "));
}


export void assert_that(const std::span<const int> value, const std::span<const int> expected)
{
	ASSERT_EQ(std::ranges::equal(value, expected), true);
}

#endif