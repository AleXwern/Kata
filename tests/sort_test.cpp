/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:33:52 by AleXwern          #+#    #+#             */
/*   Updated: 2023/02/16 10:54:03 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch_amalgamated.hpp"
#include "sort.hpp"
#include <stdio.h>

TEST_CASE("Empty", "[require]")
{
	std::vector<int> arr = {};
	Sort::sort(arr);
	REQUIRE_THAT(std::vector<int>{}, Catch::Matchers::Equals(arr));
}

TEST_CASE("OneValue", "[require]")
{
	std::vector<int> arr = {1};
	Sort::sort(arr);
	REQUIRE_THAT(std::vector<int>{1}, Catch::Matchers::Equals(arr));
}

TEST_CASE("ValuesAllRight", "[require]")
{
	std::vector<int> arr = {1, 2};
	REQUIRE(Sort::sort(arr) > 0);
	REQUIRE_THAT(std::vector<int>({1, 2}), Catch::Matchers::Equals(arr));
}

TEST_CASE("TwoValuesWrong", "[require]")
{
	std::vector<int> arr = {2, 1};
	REQUIRE(Sort::sort(arr) > 0);
	REQUIRE_THAT(std::vector<int>({1, 2}), Catch::Matchers::Equals(arr));
}

TEST_CASE("ThreeTwoLastWrong", "[require]")
{
	std::vector<int> arr = {0, 2, 1};
	REQUIRE(Sort::sort(arr) > 0);
	REQUIRE_THAT(std::vector<int>({0, 1, 2}), Catch::Matchers::Equals(arr));
}

TEST_CASE("MoveLastToFirst", "[require]")
{
	std::vector<int> arr = {1, 2, 0};
	REQUIRE(Sort::sort(arr) > 0);
	REQUIRE_THAT(std::vector<int>({0, 1, 2}), Catch::Matchers::Equals(arr));
}

TEST_CASE("TryBlockMove", "[require]")
{
	std::vector<int> arr = {6,8,1,10,9,5,4,2,7,3};
	REQUIRE(Sort::sort(arr) > 0);
	REQUIRE_THAT(std::vector<int>({1,2,3,4,5,6,7,8,9,10}), Catch::Matchers::Equals(arr));
}