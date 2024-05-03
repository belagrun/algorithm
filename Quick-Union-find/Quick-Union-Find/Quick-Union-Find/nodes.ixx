#include "pch.h"
#include <vector>

export module nodes:nd;
import :arraytype;

export class Nodes
{
	std::vector<int> m_nodes;

private:
	std::unique_ptr<ArrayType> m_arrayType;

public:


	Nodes(ArrayType& arrayType) :m_arrayType( arrayType.clone() ) { }

	constexpr int get(const int index) const {
		return m_nodes[m_arrayType->at(index)];
	}

	void set(const int index, const int value) {
		m_nodes[m_arrayType->at(index)] = value;
	}
	void resize(const int size)
	{
		m_nodes.resize(size);
	}

	void fillAll(int value = 0)
	{
		for (auto& node : m_nodes)
		{
			node = value;
		}
	}

	constexpr int size() const
	{
		return m_nodes.size();
	}

	int& operator[] (const int index)
	{
		return  m_nodes[m_arrayType->at(index)];
	}

	const std::vector<int>& getAll() { return m_nodes; }

	int firstIndex() const
	{
		return m_arrayType->firstIndex();
	}

	int lastIndex() const
	{
		return m_arrayType->lastIndex (m_nodes.size());
	}

	void setValues(const std::vector<int>&& values)
	{
		m_nodes = std::move(values);

	}

};