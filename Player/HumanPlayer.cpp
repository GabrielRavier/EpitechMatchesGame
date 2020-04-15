#include "HumanPlayer.hpp"
#include "Helpers/GetIntegerInput.hpp"

HumanPlayer::HumanPlayer(std::istream& inParam, std::ostream& outParam)
	: in{inParam}, out{outParam}
{

}

const char *HumanPlayer::describeSelf() const
{
	return "Player";
}

unsigned HumanPlayer::getNumberMatches([[maybe_unused]] unsigned currentMatches)
{
	while (true)
	{
		unsigned input = getIntegerInput<unsigned>(this->in, this->out);
		if (input >= 1 && input <= 3)
			return input;

		this->out << "Invalid input, expected number of matches between 1 and 3\n";
	}
}
