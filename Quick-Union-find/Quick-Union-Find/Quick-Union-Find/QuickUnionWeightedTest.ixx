#include "pch.h"
#include <iostream>
#include <crtdbg.h>
#include <span>
#include<tuple>



export module quickunionweightedtest;

import unionfind;
import nodes;
import utilitytest;





class QuickUnionWeightedTest : public ::testing::Test {

public:
	std::unique_ptr<UnionFind> m_unionFind;
	const int size = 10;

	virtual void SetUp() override
	{
		ZeroBasedArray zeroBasedArray;
		m_unionFind = std::make_unique <QuickUnionWeighted>(size, zeroBasedArray);
		m_unionFind->initialize();
	}

	virtual void TearDown() override
	{

	}

};


TEST_F(QuickUnionWeightedTest, testUnionWeightedUnionMultipleNodes)
{
	MemoryLeakDetector leakDetector;
	int expected[] = { 6,2,6,4,6,6,6,2,4,4 };


	for (auto nodePair : std::initializer_list<std::tuple<int, int>>{ {4,3},{3,8},{6,5},{9,4},{2,1},{5,0},{7,2},{6,1},{7,3}  })
	{
		m_unionFind->union_nodes(get<0>(nodePair), get<1>(nodePair));
	}

	const std::vector<int>& values = m_unionFind->getAllValues();
	assert_that(values, expected);


}



TEST_F(QuickUnionWeightedTest, testMultipleUnion_pathCompressionWithSinglePass_13Nodes)
{
	MemoryLeakDetector leakDetector;
	std::unique_ptr<QuickUnionWeighted> quickUnion;
	constexpr int size = 13;
	ZeroBasedArray zeroBasedArray;
	quickUnion = std::make_unique <QuickUnionWeighted>(size, zeroBasedArray);

	quickUnion->setRoot(QuickUnion::RootFunctions::pathCompressionWithSinglePass);

	std::vector<int> values = { 0, 0, 0, 1, 1, 1, 3, 3, 6, 6, 8, 9, 9 };


	quickUnion->setAllValues(std::move(values));

	ASSERT_EQ( 0,	quickUnion->root(12) );

	int expected[size] = { 0, 0, 0, 1, 1, 1, 1, 3, 6, 6, 8, 9, 6 };
	const std::vector<int>& newValues = quickUnion->getAllValues();
	printAll(newValues);
	assert_that(newValues, expected);

}

