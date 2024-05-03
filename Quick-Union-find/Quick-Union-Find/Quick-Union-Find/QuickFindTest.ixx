#include "pch.h"

import unionfind;
import nodes;
import utilitytest;
import unionfindtest;

//export module quickfindtest;

class QuickFindTest : public ::testing::Test {
public:
	std::unique_ptr<QuickFind> m_quickFind;
	const int size = 8;

	virtual void SetUp() override
	{
		OneBasedArray oneBasedArray;
		m_quickFind = std::make_unique <QuickFind>(size, oneBasedArray);
		m_quickFind->initialize();
	}

	virtual void TearDown() override
	{

	}



};



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
	unionlistOfNodes(m_quickFind.get(), { {2,6},{4,8},{8,3},{1,2},{7,5},{1,5},{5,3} });
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