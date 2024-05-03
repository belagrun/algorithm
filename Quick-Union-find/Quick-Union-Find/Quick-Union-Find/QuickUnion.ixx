#include "pch.h"
#include <functional>

export  module unionfind:quickunion;

import :uf;
import nodes;


using rootFunction = std::function<int(Nodes &, int)>;


export class QuickUnion : public UnionFind {
	
	rootFunction root_fn;

public:
	
	class RootFunctions {
	public:
		static int root(Nodes& nodes, int a)
		{
			for (; nodes[a] != a; a = nodes[a]);
			return a;
		}

		static int pathCompressionWithSinglePass(Nodes& nodes, int a)
		{
			for (; nodes[a] != a; nodes[a] = nodes[nodes[a]], a = nodes[a]);
			return a;
		}

		static int pathCompressionWithDoublePass(Nodes& nodes, int a)
		{
			int r = root(nodes, a);
			while ( r != a)
			{
				int parent = nodes[a];
				nodes[a] = r;
				a = parent;
			}
			return a;
		}


	};
	
	
	virtual ~QuickUnion() = default;

	QuickUnion(const int size, ArrayType& arrayType) :UnionFind(size, arrayType)
	{
		root_fn = RootFunctions::root;
	}

	virtual int getValue(const int index)
	{
		return m_nodes[index];
	}

	void setRoot(rootFunction rf)
	{
		root_fn = rf;
	}

	virtual int root(  int a)
	{
		return root_fn(m_nodes, a);
	}


	virtual void union_nodes(
		const int a, 
		const int b
		)
	{
		const int i = root( a );
		const int j = root( b );
		m_nodes.set(m_nodes.get(i), j);
	}

	virtual int depth(int a)
	{
		int depthOfNode = 1;
		for ( ; m_nodes[a] != a; a = m_nodes[a], depthOfNode++ );
		return depthOfNode;
	}

	virtual int maxDepth()
	{
		int depthestNode;
		for (int i = m_nodes.firstIndex(); i <= m_nodes.lastIndex(); i++)
			depthestNode = std::max( depthestNode, depth(i) );

		return depthestNode;
	}

};

