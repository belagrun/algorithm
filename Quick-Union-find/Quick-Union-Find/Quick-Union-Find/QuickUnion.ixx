#include "pch.h"

export  module unionfind:quickunion;

import :uf;


export class QuickUnion : public UnionFind {

public:
	QuickUnion(const int size) :UnionFind(size)
	{

	}

	int getValue(const int index)
	{
		return m_nodes[index];
	}

	int root( int a)
	{
		for (; m_nodes[a] != a; a = m_nodes[a]);
		return a;
	}


	void union_nodes(const int a, const int b)
	{
		const int i = root( a );
		const int j = root( b );
		m_nodes.set(m_nodes.get(i), j);
	}

};

