#include "Matches.hpp"

#include <fmt/format.h>
#include <algorithm>
#include <memory>
#include <utility>
#include "Helpers/Enumerator.hpp"

Matches::Matches(unsigned paramMatches, std::ostream& paramOut)
	: currentMatches{paramMatches}, out{paramOut}
{
	this->result.isFinished = false;
}

void Matches::play()
{
	this->printStartMessage();
	this->mainLoop();
	this->printEndMessage();
}

void Matches::printStartMessage()
{
	this->out << "Welcome to matches!\n";
}

void Matches::mainLoop()
{
	while (!this->result.isFinished)
		this->doTurn();
}

void Matches::doTurn()
{
	this->printGameInfo();
	for (auto [player, index] : enumerate(this->players))
	{
		if (this->result.isFinished)
			break;

		this->out << fmt::format("It's {}'s turn\n", this->describePlayer(index));
		this->processPlayerMatches(player->getNumberMatches(currentMatches), index);
	}
}

void Matches::printGameInfo()
{
	this->out << fmt::format("There are {} matches left\n", this->currentMatches);
}

void Matches::processPlayerMatches(unsigned int numMatches, std::size_t playerIndex)
{
	numMatches = std::min(numMatches, this->currentMatches);
	this->currentMatches -= numMatches;

	if (this->currentMatches == 0)
		this->result = {.isFinished = true, .winnerIndex = playerIndex};
}

void Matches::printEndMessage()
{
	this->out << "Game finished!\n";
	this->out << fmt::format("{} won\n", this->describePlayer(this->result.winnerIndex));
}

void Matches::addPlayer(std::unique_ptr<Player>&& player)
{
	this->players.push_back(std::move(player));
}

std::string Matches::describePlayer(size_t playerIndex)
{
	return fmt::format("{} ({})", this->players[playerIndex]->describeSelf(), playerIndex);
}