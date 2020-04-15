#ifndef RANDOMAIPLAYER_HPP
#define RANDOMAIPLAYER_HPP

#include "Player.hpp"
#include <random>

class RandomAIPlayer : public Player
{
	std::default_random_engine randomEngine;

public:
	RandomAIPlayer();

	virtual const char *describeSelf() const override;
	virtual unsigned getNumberMatches(unsigned currentMatches, unsigned maxMatches) override;
};

#endif // RANDOMAIPLAYER_HPP
