#include "RandomAIPlayer.hpp"

RandomAIPlayer::RandomAIPlayer()
{
	std::random_device rd;
	this->randomEngine = std::default_random_engine(rd());
}

const char *RandomAIPlayer::describeSelf() const
{
	return "AI";
}

unsigned RandomAIPlayer::getNumberMatches([[maybe_unused]] unsigned currentMatches)
{
	std::uniform_int_distribution<unsigned> dist{1, 3};
	return dist(this->randomEngine);
}
