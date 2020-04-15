#include "Matches.hpp"

#include <fmt/format.h>
#include <algorithm>
#include <memory>
#include <utility>
#include "Helpers/Enumerator.hpp"

Matches::Matches(unsigned paramMatches, unsigned paramMaxMatchesPerTurn, std::ostream& paramOut)
	: currentMatches{paramMatches}, maxMatchesPerTurn{paramMaxMatchesPerTurn}, out{paramOut}
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
	this->out << '\n';
	this->printGameInfo();
	for (auto [player, index] : enumerate(this->players))
	{
		if (this->result.isFinished)
			break;

		this->out << fmt::format("It's {}'s turn\n", this->describePlayer(index));
		this->processPlayerMatches(player->getNumberMatches(this->currentMatches, this->maxMatchesPerTurn), index);
		this->out << '\n';
	}
}

void Matches::printGameInfo()
{
	this->out << fmt::format("There are {} matches left\n", this->currentMatches);
}

void Matches::processPlayerMatches(unsigned numMatches, std::size_t playerIndex)
{
	auto removedMatches = std::min(numMatches, this->currentMatches);
	this->currentMatches -= removedMatches;

	this->out << fmt::format("{} removed {} matches, leaving {} matches\n", this->describePlayer(playerIndex), removedMatches, this->currentMatches);

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
