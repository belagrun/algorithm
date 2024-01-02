#include "pch.h"


#include <vector>


export module unionfind:uf;


	export class UnionFind {
	protected:
		class Nodes
		{
			enum class array_type;
			array_type m_array_type;
			std::vector<int> m_nodes;
			private:
				constexpr int one_to_zero_based_array(int onebased)
				{
					return onebased - 1;
				}

				constexpr int zero_to_one_based_array(int zerobased)
				{
					return zerobased + 1;
				}
		
			public:
				enum class array_type { zero_based_array, one_based_array };
				Nodes(array_type at):m_array_type(at) { }

				constexpr int get(const int index) { 
					if (m_array_type == array_type::zero_based_array)
						return  m_nodes[index];
					else if (m_array_type == array_type::one_based_array)
						return m_nodes[one_to_zero_based_array(index)];
					 std::logic_error("array type not implemented");
				}

				void set(const int index, const int value) {
					if (m_array_type == array_type::zero_based_array)
						 m_nodes[index] = value;
					else if (m_array_type == array_type::one_based_array)
						 m_nodes[one_to_zero_based_array(index)] = value;
					 std::logic_error("array type not implemented");
				}
				void resize(const int size)
				{
					m_nodes.resize(size);
				}
				constexpr int size() const 
				{
					return m_nodes.size();
				}

				int& operator[] (const int index)
				{
					if (m_array_type == array_type::zero_based_array)
						return  m_nodes[index];
					else if (m_array_type == array_type::one_based_array)
						return m_nodes[one_to_zero_based_array(index)];
					else std::logic_error("array type not implemented");
				}

				const std::vector<int>& getAll() { return m_nodes; }
		};
	protected:
		Nodes m_nodes;
		UnionFind() = default;

	public:

		UnionFind(const int size):m_nodes(Nodes::array_type::one_based_array)
		{
			m_nodes.resize(size);
			
		}

		virtual void initialize()
		{

			for (int i = 1; i <= m_nodes.size(); i++)
			{
				m_nodes[i] = i;
			}
		}
		virtual int getValue(const int index) = 0;
		const std::vector<int>& getAllValues() { return m_nodes.getAll(); }
		constexpr int getSize() const { return m_nodes.size(); }
		virtual void union_nodes(const int a, const int b) = 0;

	};
