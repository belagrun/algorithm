#include "pch.h"
#include <iostream>
#include <crtdbg.h>
#include <span>
#include<tuple>


import unionfind;
import nodes;
import utilitytest;
import unionfindtest;

enum { index_node, parent_node };

class QuickUnion_RootFunctionsTest : public ::testing::Test {
protected:
	OneBasedArray oneBasedArray;
	ZeroBasedArray zeroBasedArray;
public:

	virtual void SetUp() override{}
	virtual void TearDown() override {}

};




void assignParent(Nodes &nodes, std::initializer_list<std::tuple<int, int>> listOfPairIndexAndParent)
{
	nodes.resize(listOfPairIndexAndParent.size() );

	for (auto pip : listOfPairIndexAndParent)
	{
		nodes.set(get<index_node>(pip), get<parent_node>(pip));

	}

}



void assertSinglePass(Nodes& nodes, int value, int expected)
{
	ASSERT_EQ(expected, QuickUnion::RootFunctions::pathCompressionWithSinglePass(nodes, value));
}

void assertDoublePass(Nodes& nodes, int value, int expected)
{
	ASSERT_EQ(expected, QuickUnion::RootFunctions::pathCompressionWithDoublePass(nodes, value));
}


TEST_F(QuickUnion_RootFunctionsTest, testRootFunctionsOnPathCompression_With2nodes)
{
	MemoryLeakDetector leakDetector;
	Nodes nodes{ zeroBasedArray };
	assignParent(nodes, { { 0,0 }, {1, 1} });

	assertSinglePass(nodes, 0, 0);
	assertSinglePass(nodes, 1, 1);


}

TEST_F(QuickUnion_RootFunctionsTest, testRootFunctionsOnPathCompression_3nodesWithSameParent)
{
	MemoryLeakDetector leakDetector;
	
	Nodes nodes{ oneBasedArray };
	int root = 1;
	assignParent(nodes, { {1,root},{2,root}, {3, root} });

	assertSinglePass(nodes, 1, root);
	assertSinglePass(nodes, 2, root);
	assertSinglePass(nodes, 3, root);

}

TEST_F(QuickUnion_RootFunctionsTest, testRootFunctionsOnPathCompression_WithGrandGrandParent)
{
	MemoryLeakDetector leakDetector;
	Nodes nodes{ oneBasedArray };
	assignParent(nodes, {{1,1},{2,1},{3,1},{4,1}});
	int root = 1;
	assertSinglePass(nodes, 1, root);
	assertSinglePass(nodes, 2, root);
	assertSinglePass(nodes, 3, root);
	assertSinglePass(nodes, 4, root);

}

TEST_F(QuickUnion_RootFunctionsTest, testRootFunctionsOnPathCompression_WithDoublePass)
{
	MemoryLeakDetector leakDetector;
	Nodes nodes{ zeroBasedArray };
	assignParent(nodes, { {0, 0}, {1, 0}, {2,0}, {3, 1},{4, 1}, {5, 1},	{6, 3},	{7, 3},	{8, 6}, {9, 6},	{10, 8},{11,9},{12, 9 } });
	int root = 0;
	assertDoublePass(nodes, 12, root);
}

