/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movierental_test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:25:09 by AleXwern          #+#    #+#             */
/*   Updated: 2022/10/13 09:22:28 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch_amalgamated.hpp"
#include "movierental.hpp"

namespace kata
{
    class MovierentalTest
    {
    protected:
        MovierentalTest()
        {
            customer = new Customer("Guy");
        }

        Customer *customer;
    };
    
    TEST_CASE_METHOD(MovierentalTest, "testSingleNewReleaseStatement", "[require]")
    {
        customer->addRental(new Rental(new Movie("The Cell", Movie::NEW_RELEASE), 3));
        REQUIRE(ft_strequ("Rental Record for Fred\n\tThe Cell\t9.0\nYou owed 9.0\nYou earned 2 frequent renter points\n", customer->statement().c_str()));
    }
}