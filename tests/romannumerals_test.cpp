/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   romannumerals_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:09:42 by alexwern          #+#    #+#             */
/*   Updated: 2022/06/03 13:06:02 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
#include "romannumerals.h"
}
#include "catch_amalgamated.hpp"

TEST_CASE("Zero", "[require]")
{
	REQUIRE(ft_strequ("", itor(0)));
}

TEST_CASE("One two three", "[require]")
{
	REQUIRE(ft_strequ("I", itor(1)));
	REQUIRE(ft_strequ("II", itor(2)));
	REQUIRE(ft_strequ("III", itor(3)));
}

TEST_CASE("Single symbols", "[require]")
{
	REQUIRE(ft_strequ("V", itor(5)));
	REQUIRE(ft_strequ("X", itor(10)));
	REQUIRE(ft_strequ("L", itor(50)));
	REQUIRE(ft_strequ("C", itor(100)));
	REQUIRE(ft_strequ("D", itor(500)));
	REQUIRE(ft_strequ("M", itor(1000)));
}