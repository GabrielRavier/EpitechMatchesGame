#include <iostream>
#include <exception>
#include <memory>
#include <cstdlib>
#include <cxxopts.hpp>
#include <fmt/format.h>
#include "Matches.hpp"
#include "Player/HumanPlayer.hpp"
#include "Player/RandomAIPlayer.hpp"
#include "Player/PerfectAIPlayer.hpp"

static void program(cxxopts::ParseResult options)
{
	Matches game{options["total"].as<unsigned>(), options["max-per-turn"].as<unsigned>(), std::cout};
	game.addPlayer(std::make_unique<HumanPlayer>(std::cin, std::cout));
	game.addPlayer(std::make_unique<PerfectAIPlayer>());
	game.play();
}

static auto parseArguments(int argc, char *argv[])
{
	cxxopts::Options options("MatchesGame", "- A simple game of matches");

	options.add_options()
		("t,total", "Total number of matches", cxxopts::value<unsigned>()->default_value("13"))
		("m,max-per-turn", "Maximum amount of matches that can be taken per turn", cxxopts::value<unsigned>()->default_value("3"))
		("h,help", "Print usage");

	options.parse_positional({"total", "max-matches-per-turn", "discard"});
	options.show_positional_help();
	options.positional_help("TOTAL-MATCHES MAX-PER-TURN [ignored positional arguments]");

	auto parsedOptions = options.parse(argc, argv);

	if (parsedOptions.count("help"))
	{
		std::cout << fmt::format("{}\n", options.help());
		exit(EXIT_SUCCESS);
	}

	return parsedOptions;
}

int main(int argc, char *argv[])
{
	try
	{
		program(parseArguments(argc, argv));
		return EXIT_SUCCESS;
	}
	catch (const cxxopts::OptionParseException& optionParseException)
	{
		std::cerr << fmt::format("Failed to parse options: {}\n", optionParseException.what());
	}
	catch (const std::exception& exception)
	{
		std::cerr << fmt::format("Exception thrown: {}\n", exception.what());
	}
	catch (...)
	{
		std::cerr << "Exception thrown: Something not inherited from std::exception\n";
	}

	return EXIT_FAILURE;
}
