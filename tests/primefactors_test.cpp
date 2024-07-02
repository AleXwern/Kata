/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primefactors_test.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:44:16 by alexwern          #+#    #+#             */
/*   Updated: 2022/06/09 12:50:13 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch_amalgamated.hpp"
#include "primefactors.hpp"

TEST_CASE("4 and some characters long words", "[require]")
{
    std::vector<t_pfint> vec = PrimeFactors::generate(0);
    //REQUIRE_THAT(vec, Catch::Matchers::Equals());
}
