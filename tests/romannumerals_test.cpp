/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   romannumerals_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:09:42 by alexwern          #+#    #+#             */
/*   Updated: 2022/04/22 13:32:26 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
#include "romannumerals.h"
}
#include "catch_amalgamated.hpp"
#include <stdio.h>

TEST_CASE("Zero", "[require]")
{
	REQUIRE(ft_strequ("", itor(0)));
}