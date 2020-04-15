cmake_minimum_required(VERSION 3.5)

project(EpitechMatchesGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(EpitechMatchesGame
    main.cpp
    Matches.cpp
    Matches.hpp
    Player/Player.hpp
    Helpers/Enumerator.hpp
    Player/HumanPlayer.cpp
    Player/HumanPlayer.hpp
    Player/RandomAIPlayer.cpp
    Player/RandomAIPlayer.hpp
    Helpers/GetIntegerInput.hpp)

find_package(fmt)
target_link_libraries(EpitechMatchesGame fmt::fmt)
target_include_directories(EpitechMatchesGame PRIVATE .)
