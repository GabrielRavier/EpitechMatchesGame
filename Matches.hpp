#ifndef MATCHES_H
#define MATCHES_H

#include <istream>
#include <ostream>
#include <vector>
#include <string>
#include <memory>
#include <cstddef>
#include "Player/Player.hpp"

class Matches
{
	struct Result
	{
		bool isFinished;
		std::size_t winnerIndex;
	};

	unsigned currentMatches;
	unsigned maxMatchesPerTurn;
	std::ostream& out;
	Result result;
	std::vector<std::unique_ptr<Player>> players;

	void printStartMessage();
	void mainLoop();
	void printEndMessage();
	void doTurn();
	void printGameInfo();
	void processPlayerMatches(unsigned numMatches, std::size_t playerIndex);
	std::string describePlayer(size_t playerIndex);

public:
	Matches(unsigned paramMatches, unsigned paramMaxMatchesPerTurn, std::ostream& paramOut);

	void play();
	void addPlayer(std::unique_ptr<Player>&& player);
};

#endif // MATCHES_H
