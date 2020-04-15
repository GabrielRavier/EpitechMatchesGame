#include "PerfectAIPlayer.hpp"

PerfectAIPlayer::PerfectAIPlayer()
{

}

const char *PerfectAIPlayer::describeSelf() const
{
	return "Perfect AI";
}

unsigned PerfectAIPlayer::getNumberMatches(unsigned currentMatches, unsigned maxMatches)
{
	currentMatches %= (maxMatches + 1);
	if (currentMatches == 0)
		return 1;

	return currentMatches;
}
