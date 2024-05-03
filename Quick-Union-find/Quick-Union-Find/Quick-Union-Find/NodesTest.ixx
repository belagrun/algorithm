#include "pch.h"

//export module nodestest;
import nodes;
import utilitytest;


class QuickUnionTestNodes : public ::testing::Test {
public:
	virtual void SetUp() override {}
	virtual void TearDown() override {}

};



void assertLimits(Nodes& nodes, const int size, int firstIndex, int lastIndex)
{
	nodes.resize(size);
	ASSERT_EQ(nodes.firstIndex(), firstIndex);
	ASSERT_EQ(nodes.lastIndex(), lastIndex);
}


TEST_F(QuickUnionTestNodes, InsertingElementsInto_OneBasedArray)
{
	OneBasedArray oneBasedArray;
	Nodes nodes{ oneBasedArray };
	nodes.resize(2);
	nodes.set(1, 42);
	nodes.set(2, 43);
	int expected[] = { 42, 43 };
	std::vector<int> values = nodes.getAll();
	assert_that(values, expected);
}





TEST_F(QuickUnionTestNodes, InsertingElementsInto_ZeroBasedArray)
{
	ZeroBasedArray zeroBasedArray;
	Nodes nodes{ zeroBasedArray };
	nodes.resize(3);
	nodes.set(0, 42);
	nodes.set(1, 43);
	nodes.set(2, 44);
	int expected[] = { 42, 43, 44 };
	std::vector<int> values = nodes.getAll();
	assert_that(values, expected);
}



TEST_F(QuickUnionTestNodes, testinglimits_ZeroBasedArray)
{
	ZeroBasedArray zeroBasedArray;
	Nodes nodes{ zeroBasedArray };

	assertLimits(nodes, 3, 0, 2);
	assertLimits(nodes, 2, 0, 1);
	assertLimits(nodes, 1, 0, 0);

}

TEST_F(QuickUnionTestNodes, testingInitialize_ZeroBasedArray)
{
	ZeroBasedArray zeroBasedArray;
	Nodes nodes{ zeroBasedArray };
	nodes.resize(10);

	for (int i = nodes.firstIndex(); i <= nodes.lastIndex(); i++)
	{
		nodes[i] = i;
	}

	int expected[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> values = nodes.getAll();
	assert_that(values, expected);
}

