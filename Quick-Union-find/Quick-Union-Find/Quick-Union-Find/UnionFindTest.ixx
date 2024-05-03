#include "pch.h"

export module unionfindtest;

import unionfind;

export void unionlistOfNodes(UnionFind * unionFind, std::initializer_list<std::tuple<int,int>> listOfPairOfNodes)
{
	for (auto pairNode : listOfPairOfNodes )
	{
		unionFind->union_nodes(get<0>(pairNode), get<1>(pairNode));

	}

}


