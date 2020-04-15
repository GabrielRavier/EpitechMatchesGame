#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "Player.hpp"
#include <istream>

class HumanPlayer : public Player
{
	std::istream& in;
	std::ostream& out;

public:
	HumanPlayer(std::istream& inParam, std::ostream& out);

	virtual const char *describeSelf() const override;
	virtual unsigned getNumberMatches(unsigned currentMatches) override;
};

#endif // HUMANPLAYER_HPP
