#include "pch.h"
#include <iostream>
#include <crtdbg.h>
#include <span>
#include<tuple>


import unionfind;
import nodes;
import utilitytest;
import unionfindtest;



class QuickUnionTest : public ::testing::Test {
protected:
	std::unique_ptr<UnionFind> m_unionFind;
	OneBasedArray oneBasedArray;
	ZeroBasedArray zeroBasedArray;
	
public:


	virtual void SetUp() override
	{
		int size = 8;
		m_unionFind = std::make_unique <QuickUnion>(size, oneBasedArray);
		m_unionFind->initialize();

	}



	virtual void TearDown() override
	{

	}

};




TEST_F(QuickUnionTest, testUnion3and7)
{
	MemoryLeakDetector leakDetector;
	m_unionFind->union_nodes(3, 7);
	int expected[] = { 1, 2, 7, 4, 5, 6, 7, 8 };
	const std::vector<int>& values = m_unionFind->getAllValues();
	assert_that(values, expected);

}


TEST_F(QuickUnionTest, testMultipleUnion)
{
	MemoryLeakDetector leakDetector;
	unionlistOfNodes(m_unionFind.get(), {{3,7},{2,5},{2,3},{3,6},{1,4},{8,1},{4,7}});
	int expected[] = { 4, 5, 7, 6, 7, 6, 6, 4 };
	const std::vector<int>& values = m_unionFind->getAllValues();
	assert_that(values, expected);

}



TEST_F(QuickUnionTest, testMultipleUnion_pathCompressionWith2Nodes)
{
	MemoryLeakDetector leakDetector;
	std::unique_ptr<QuickUnion> quickUnion;
	constexpr int size = 2;
	ZeroBasedArray zeroBasedArray;
	quickUnion = std::make_unique <QuickUnion>(size, zeroBasedArray);

	quickUnion->setRoot(QuickUnion::RootFunctions::pathCompressionWithSinglePass);

	std::vector<int> values = { 0, 1 };

	quickUnion->setAllValues(std::move(values));

	quickUnion->union_nodes(0, 1);

	int expected[size] = { 1, 1 };
	const std::vector<int>& newValues = quickUnion->getAllValues();
	printAll(newValues);
	assert_that(newValues, expected);

}

