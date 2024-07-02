/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordwrap_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:59:22 by alexwern          #+#    #+#             */
/*   Updated: 2023/02/16 13:59:10 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch_amalgamated.hpp"
#include "wordwrap2.hpp"
#include <stdio.h>

Wordwrap wrap(72);

TEST_CASE("Check if newline exist", "[require]")
{
    char* str = wrap.wrap("-String1 is very long and that stufff yepyep text doop-", 20);
    REQUIRE(std::strchr(str, '\n'));
}

TEST_CASE("Very long string which should not be cut", "[require]")
{
    char* str = wrap.wrap("-String1hishveryhlonghandhthathstuffhyepyephtexthdoop-hhhhhhhhhh", 20);
    REQUIRE_FALSE(std::strchr(str, '\n'));
}

TEST_CASE("5 and some characters long words", "[require]")
{
    char* str = wrap.wrap("hello h hello h hello h hello h hello h h h hello hello hello hello hello hello hello", 5);
    REQUIRE(std::strchr(str, '\n'));
}

TEST_CASE("4 and some characters long words", "[require]")
{
    char* str = wrap.wrap("helo h helo h hello h hello h helo h h h hello hell hell hello hello hell hello", 5);
    REQUIRE(std::strchr(str, '\n'));
}

TEST_CASE("Just spaces", "[require]")
{
    char* str = wrap.wrap("                                                                                   ", 5);
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            str[i] = '*';
    }
    REQUIRE(std::strchr(str, '\n'));
}

// NEW TESTS

TEST_CASE("Empty string", "[require]")
{
    char* str = wrap.wrap("", 72);
    REQUIRE_FALSE(std::strcmp(str, ""));
}

TEST_CASE("Zero length", "[require]")
{
    char* str = wrap.wrap("     ", 0);
    REQUIRE(std::strchr(str, '\n'));
}

TEST_CASE("Longer word", "[require]")
{
    char* str = wrap.wrap("hello this is world agdsfgsfgdsahkdsajhkfg yep", 5);
    REQUIRE(std::strchr(str, '\n'));
}

TEST_CASE("Only longer word", "[require]")
{
    char* str = wrap.wrap("hello0 thisss issssss worldd agdsfgsfgdsahkdsajhkfg yeppppers", 3);
    REQUIRE(std::strchr(str, '\n'));
}