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

#include "romannumerals2.hpp"
#include <string.h>
#include "catch_amalgamated.hpp"

bool isSame(const char* str1, const int str2)
{
	return strcmp(str1, itor(str2)) == 0;
}

TEST_CASE("Zero", "[require]")
{
	REQUIRE(isSame("", 0));
}

TEST_CASE("Single digit", "[require]")
{
	REQUIRE(isSame("I", 1));
	REQUIRE(isSame("V", 5));
	REQUIRE(isSame("X", 10));
	REQUIRE(isSame("L", 50));
	REQUIRE(isSame("C", 100));
	REQUIRE(isSame("D", 500));
	REQUIRE(isSame("M", 1000));
}

TEST_CASE("Multiple numbers", "[require]")
{
	REQUIRE(isSame("II", 2));
	REQUIRE(isSame("III", 3));
}

TEST_CASE("Complex numbers", "[require]")
{
	REQUIRE(isSame("IV", 4));
}

TEST_CASE("ComplexPlusValue", "[require]")
{
	REQUIRE(isSame("XCV", 95));
}