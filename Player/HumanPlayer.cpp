#include "HumanPlayer.hpp"
#include "Helpers/GetIntegerInput.hpp"
#include <fmt/format.h>

HumanPlayer::HumanPlayer(std::istream& inParam, std::ostream& outParam)
	: in{inParam}, out{outParam}
{

}

const char *HumanPlayer::describeSelf() const
{
	return "Player";
}

unsigned HumanPlayer::getNumberMatches([[maybe_unused]] unsigned currentMatches, unsigned maxMatches)
{
	while (true)
	{
		unsigned input = getIntegerInput<unsigned>(this->in, this->out);
		if (input >= 1 && input <= maxMatches)
			return input;

		this->out << fmt::format("Invalid input, expected number of matches between 1 and {}\n", maxMatches);
	}
}
