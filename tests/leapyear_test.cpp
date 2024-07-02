/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leapyear_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:07:40 by alexwern          #+#    #+#             */
/*   Updated: 2023/09/14 13:38:32 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch_amalgamated.hpp"
#include "leapyear.hpp"

TEST_CASE("basic0", "[require]")
{
    REQUIRE(Leapyear::isLeapyear2(0));
}

TEST_CASE("This is basic non valid", "[require]")
{
    REQUIRE(Leapyear::isLeapyear2(1) == false);
}

TEST_CASE("Valid basic 4", "[require]")
{
    REQUIRE(Leapyear::isLeapyear2(4));
}

TEST_CASE("Nonvalid 100", "[require]")
{
    REQUIRE(Leapyear::isLeapyear2(100) == false);
}

TEST_CASE("Valid 400", "[require]")
{
    REQUIRE(Leapyear::isLeapyear2(400));
}
