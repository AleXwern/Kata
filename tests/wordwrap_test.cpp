/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordwrap_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:59:22 by alexwern          #+#    #+#             */
/*   Updated: 2022/04/06 07:58:29 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch_amalgamated.hpp"
#include "wordwrap.hpp"
#include <stdio.h>

Wrapper wrap;

TEST_CASE("Check if newline exist", "[require]")
{
    std::string str = wrap.wrapword("-String1 is very long and that stufff yepyep text doop-", 20);
    printf("String: %s\n", str.c_str());
    REQUIRE(std::strchr(str.c_str(), '\n'));
}

TEST_CASE("Very long string which should not be cut", "[require]")
{
    std::string str = wrap.wrapword("-String1hishveryhlonghandhthathstuffhyepyephtexthdoop-hhhhhhhhhh", 20);
    printf("String: %s\n", str.c_str());
    REQUIRE_FALSE(std::strchr(str.c_str(), '\n'));
}

TEST_CASE("5 and some characters long words", "[require]")
{
    std::string str = wrap.wrapword("hello h hello h hello h hello h hello h h h hello hello hello hello hello hello hello", 5);
    printf("String: %s\n", str.c_str());
    REQUIRE(std::strchr(str.c_str(), '\n'));
}

TEST_CASE("4 and some characters long words", "[require]")
{
    std::string str = wrap.wrapword("helo h helo h hello h hello h helo h h h hello hell hell hello hello hell hello", 5);
    printf("String: %s\n", str.c_str());
    REQUIRE(std::strchr(str.c_str(), '\n'));
}

TEST_CASE("Just spaces", "[require]")
{
    std::string str = wrap.wrapword("                                                                                   ", 5);
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            str[i] = '*';
    }
    printf("String: %s\n", str.c_str());
    REQUIRE(std::strchr(str.c_str(), '\n'));
}
