#include "RandomAIPlayer.hpp"

RandomAIPlayer::RandomAIPlayer()
{
	std::random_device rd;
	this->randomEngine = std::default_random_engine(rd());
}

const char *RandomAIPlayer::describeSelf() const
{
	return "Random AI";
}

unsigned RandomAIPlayer::getNumberMatches([[maybe_unused]] unsigned currentMatches, unsigned maxMatches)
{
	std::uniform_int_distribution<unsigned> dist{1, maxMatches};
	return dist(this->randomEngine);
}
