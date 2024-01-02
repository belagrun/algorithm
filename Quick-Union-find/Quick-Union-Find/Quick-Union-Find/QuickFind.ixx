#include "pch.h"

export  module unionfind:quickfind;

import :uf;


	export class QuickFind : public UnionFind {

	public:
		QuickFind(const int size):UnionFind(size)
		{

		}

		int getValue(const int index)
		{
			return m_nodes[index]; 
		}



		void union_nodes(const int a, const int b)
		{
			const int i = m_nodes.get(a);
			const int j = m_nodes.get(b);
			for (int idx = 1; idx <= m_nodes.size(); idx++)
				if (m_nodes.get(idx) == i)  m_nodes[idx] = j;
		}

	};

