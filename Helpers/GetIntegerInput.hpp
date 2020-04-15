#ifndef GETINTEGERINPUT_HPP
#define GETINTEGERINPUT_HPP

#include <istream>
#include <ostream>
#include <optional>
#include <ios>
#include <limits>

template <typename Type> std::optional<Type> tryGetIntegerInput(std::istream& in, std::ostream& out)
{
	out << "Please enter a number: \n";

	Type result;
	in >> result;

	if (in.fail())
	{
		in.clear();
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return std::nullopt;
	}

	return result;
}

template <typename Type> Type getIntegerInput(std::istream& in, std::ostream& out)
{
	std::optional<Type> result;
	do
	{
		result = tryGetIntegerInput<Type>(in, out);
	} while (!result);

	return *result;
}

#endif // GETINTEGERINPUT_HPP
