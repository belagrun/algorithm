#include "pch.h"

export  module unionfind:quickunionweighted;

import :uf;
import :quickunion;
import nodes;

export class QuickUnionWeighted : public QuickUnion {
	Nodes m_nodeSize;
public:
	virtual ~QuickUnionWeighted() = default;

	QuickUnionWeighted(const int size, ArrayType& arrayType): QuickUnion(size, arrayType), m_nodeSize{ arrayType }
	{
		m_nodeSize.resize(size);
		m_nodeSize.fillAll(1);
	}
	
	virtual int sizeofBranch(const int i) const
	{
		return m_nodeSize.get(i);
	}


	virtual void union_nodes(const int a, const int b) override
	{
		 int i = root(a);
		 int j = root(b);
		const int newSize = sizeofBranch(i) + sizeofBranch(j);
		if (sizeofBranch(i) < sizeofBranch(j))
		{
			m_nodes.set(i, j);
			m_nodeSize.set(j, newSize );
		}
		else
		{
			m_nodes.set(j, i);
			m_nodeSize.set(i, newSize );
		}


	}
	
};