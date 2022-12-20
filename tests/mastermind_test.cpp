/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mastermind_test.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:26:50 by AleXwern          #+#    #+#             */
/*   Updated: 2022/12/13 10:16:26 by AleXwern         ###   ########.fr       */
/*                                              -+                              */
/* ************************************************************************** */

#include "catch_amalgamated.hpp"
#include "mastermind.hpp"

TEST_CASE("noneMatch", "[require]")
{
    Mastermind game(red, red, red, red);
    Mastermind attempt(blue, blue, blue, blue);
    game.evaluate(attempt);
    REQUIRE(game.getPlaces() == 0);
    REQUIRE(game.getColors() == 0);
}

TEST_CASE("allMatch", "[require]")
{
    Mastermind game(red, red, red, red);
    Mastermind attempt(red, red, red, red);
    game.evaluate(attempt);
    REQUIRE(game.getPlaces() == 4);
    REQUIRE(game.getColors() == 0);
}

TEST_CASE("noHitOneMiss", "[require]")
{
    Mastermind game(red, blue, red, red);
    Mastermind attempt(green, green, blue, green);
    game.evaluate(attempt);
    REQUIRE(game.getPlaces() == 0);
    REQUIRE(game.getColors() == 1);
}

TEST_CASE("inverseComparisons", "[require]")
{
    Mastermind game(red, blue, red, red);
    Mastermind attempt(blue, red, blue, blue);
    game.evaluate(attempt);
    REQUIRE(game.getPlaces() == 0);
    REQUIRE(game.getColors() == 2);
}

TEST_CASE("twoAndTwo", "[require]")
{
    Mastermind game(red, blue, green, red);
    Mastermind attempt(red, green, blue, red);
    game.evaluate(attempt);
    REQUIRE(game.getPlaces() == 2);
    REQUIRE(game.getColors() == 2);
}

TEST_CASE("noClip", "[require]")
{
    Mastermind game(red, red, green, green);
    Mastermind attempt(red, red, red, green);
    game.evaluate(attempt);
    REQUIRE(game.getPlaces() == 3);
    REQUIRE(game.getColors() == 0);
}

TEST_CASE("twoTwoColours", "[require]")
{
    Mastermind game(red, blue, red, blue);
    Mastermind attempt(blue, red, blue, red);
    game.evaluate(attempt);
    REQUIRE(game.getPlaces() == 0);
    REQUIRE(game.getColors() == 4);
}
