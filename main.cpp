#include <iostream>
#include <exception>
#include <memory>
#include <fmt/format.h>
#include "Matches.hpp"
#include "Player/HumanPlayer.hpp"
#include "Player/RandomAIPlayer.hpp"

int main()
{
	try
	{
		Matches game{13, std::cout};
		game.addPlayer(std::make_unique<HumanPlayer>(std::cin, std::cout));
		game.addPlayer(std::make_unique<RandomAIPlayer>());
		game.play();
	}
	catch (const std::exception& exception)
	{
		std::cout << fmt::format("Exception thrown : {}", exception.what());
	}
}
