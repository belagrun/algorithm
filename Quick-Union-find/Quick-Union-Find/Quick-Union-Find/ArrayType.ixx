#include "pch.h"
#include <memory>

export module nodes:arraytype;



export class ArrayType { 

protected:
	constexpr int one_to_zero_based_array(int onebased) const
	{
		return onebased - 1;
	}

	constexpr int zero_to_one_based_array(int zerobased) const
	{
		return zerobased + 1;
	}




public: 
	virtual int at(const int index) const = 0 ;
	virtual std::unique_ptr<ArrayType> clone() = 0;
	virtual int firstIndex() const = 0;
	virtual int lastIndex(const int size) const = 0;
};

export class ZeroBasedArray : public ArrayType
{
public:
	int at(const int index) const override
	{
		return index;
	}

	virtual std::unique_ptr<ArrayType> clone() override
	{
		return std::make_unique<ZeroBasedArray>();
	}

	virtual int firstIndex() const override
	{
		return 0;
	}

	virtual int lastIndex(const int size) const override
	{
		return size - 1;
	}

};

export class OneBasedArray : public ArrayType
{
public:
	int at(const int index) const  override
	{
		return one_to_zero_based_array(index);
	}

	virtual std::unique_ptr<ArrayType> clone() override
	{
		return std::make_unique<OneBasedArray>();
	}

	virtual int firstIndex() const override
	{
		return 1;
	}

	virtual int lastIndex(const int size) const override
	{
		return size;
	}
};


