#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
	virtual ~Player()
	{}

	virtual const char *describeSelf() const = 0;
	virtual unsigned getNumberMatches(unsigned currentMatches) = 0;
};

#endif // PLAYER_H
