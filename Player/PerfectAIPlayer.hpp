#ifndef PERFECTAIPLAYER_H
#define PERFECTAIPLAYER_H

#include "Player.hpp"

class PerfectAIPlayer : public Player
{
public:
	PerfectAIPlayer();

	virtual const char *describeSelf() const override;
	virtual unsigned getNumberMatches(unsigned currentMatches, unsigned maxMatches) override;
};

#endif // PERFECTAIPLAYER_H
