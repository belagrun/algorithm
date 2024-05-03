#include "pch.h"
#include <vector>
#include <cassert>

export module unionfind:uf;
import nodes;

export class UnionFind {

	protected:
		Nodes m_nodes;

	public:

		UnionFind(const int size, ArrayType &arrayType ):
			m_nodes(arrayType)
		{
			m_nodes.resize(size);
			
		}

		virtual void initialize()
		{		
			assert(m_nodes.size() > 0);
			for (int i = m_nodes.firstIndex(); i <= m_nodes.lastIndex(); i++)
				m_nodes[i] = i;
		}

		virtual int getValue(const int index) = 0;
		const std::vector<int>& getAllValues() { return m_nodes.getAll(); }
		void setAllValues(std::vector<int>&& values) { m_nodes.setValues(std::move(values)); }
		constexpr int getSize() const { return m_nodes.size(); }
		virtual void union_nodes(const int a, const int b) = 0;

		virtual ~UnionFind() = default;
	};
