#ifndef ENUMERATOR_HPP
#define ENUMERATOR_HPP

#include <cstddef>

template <typename Type> class EnumeratorImpl
{
	Type& container;

public:
	struct item
	{
		typename Type::value_type& item;
		std::size_t index;
	};
	using value_type = item;

	class iterator
	{
		typename Type::iterator it;
		std::size_t counter;

	public:
		iterator(typename Type::iterator itParam, std::size_t counterParam = 0)
			: it(itParam), counter(counterParam)
		{}

		iterator operator++()
		{
			return iterator(++this->it, ++this->counter);
		}

		bool operator!=(iterator other)
		{
			return this->it != other.it;
		}

		value_type operator*()
		{
			return value_type{.item = *this->it, .index = this->counter};
		}

		std::size_t index()
		{
			return this->counter;
		}
	};

	EnumeratorImpl(Type& t)
		: container(t)
	{}

	iterator begin()
	{
		return iterator(this->container.begin());
	}

	iterator end()
	{
		return iterator(this->container.end());
	}
};

template <typename Type> auto enumerate(Type& t)
{
	return EnumeratorImpl<Type>(t);
}

#endif // ENUMERATOR_HPP
