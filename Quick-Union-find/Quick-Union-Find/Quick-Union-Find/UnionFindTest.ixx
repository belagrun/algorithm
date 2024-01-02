#include "pch.h"
#include <iostream>
#include <crtdbg.h>
#include <span>

import unionfind;

	class MemoryLeakDetector {
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

	class QuickFindTest : public ::testing::Test {
	public:
		std::unique_ptr<QuickFind> m_quickFind;
		const int size = 8;

		virtual void SetUp() override
		{
			m_quickFind = std::make_unique <QuickFind>(size);
			m_quickFind->initialize();
		}

		virtual void TearDown() override
		{

		}

	};

	class QuickUnionTest : public ::testing::Test {
	public:
		std::unique_ptr<QuickUnion> m_quickFind;
		const int size = 8;

		virtual void SetUp() override
		{
			m_quickFind = std::make_unique <QuickUnion>(size);
			m_quickFind->initialize();
		}

		virtual void TearDown() override
		{

		}

	};



	void assert_that( const std::span<const int> value,  const std::span<const int> expected)
	{
		ASSERT_EQ(std::ranges::equal(value, expected), true);
	}



	TEST_F(QuickFindTest, testInitialization) {
		MemoryLeakDetector leakDetector;

		int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		const std::vector<int>& values = m_quickFind->getAllValues();
		assert_that(values, expected);

	}

	TEST_F(QuickFindTest, testUnion2and6)
	{
		MemoryLeakDetector leakDetector;
		m_quickFind->union_nodes(2, 6);
		int expected[] = { 1, 6, 3, 4, 5, 6, 7, 8 };
		const std::vector<int>& values = m_quickFind->getAllValues();
		assert_that(values, expected);

	}



	TEST_F(QuickFindTest, testMultipleInsertionUnion)
	{
		MemoryLeakDetector leakDetector;
		
		m_quickFind->union_nodes(2, 6);
		m_quickFind->union_nodes(4, 8);
		m_quickFind->union_nodes(8, 3);
		m_quickFind->union_nodes(1, 2);
		m_quickFind->union_nodes(7, 5);
		m_quickFind->union_nodes(1, 5);
		m_quickFind->union_nodes(5, 3);

		int expected[] = { 3, 3, 3, 3, 3, 3, 3, 3 };
		const std::vector<int>& values = m_quickFind->getAllValues();
		assert_that(values, expected);

	}


	TEST_F(QuickFindTest, testUnion3and7)
	{
		MemoryLeakDetector leakDetector;

		m_quickFind->union_nodes(3, 7);

		int expected[] = { 1, 2, 7, 4, 5, 6, 7, 8 };
		const std::vector<int>& values = m_quickFind->getAllValues();
		assert_that(values, expected);

	}



	TEST_F(QuickUnionTest, testUnion3and7)
	{
		MemoryLeakDetector leakDetector;
		m_quickFind->union_nodes(3, 7);
		int expected[] = { 1, 2, 7, 4, 5, 6, 7, 8 };
		const std::vector<int>& values = m_quickFind->getAllValues();
		assert_that(values, expected);

	}

	
	TEST_F(QuickUnionTest, testMultipleUnion)
	{
		MemoryLeakDetector leakDetector;

		m_quickFind->union_nodes(3, 7);
		m_quickFind->union_nodes(2, 5);
		m_quickFind->union_nodes(2, 3);
		m_quickFind->union_nodes(3, 6);
		m_quickFind->union_nodes(1, 4);
		m_quickFind->union_nodes(8, 1);
		m_quickFind->union_nodes(4, 7);


		int expected[] = { 4, 5, 7, 6, 7, 6, 6, 4 };
		const std::vector<int>& values = m_quickFind->getAllValues();
		assert_that(values, expected);

	}