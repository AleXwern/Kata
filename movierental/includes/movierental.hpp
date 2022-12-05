/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movierental.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:42:09 by AleXwern          #+#    #+#             */
/*   Updated: 2022/10/13 09:22:21 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIERENTAL_HPP
#define MOVIERENTAL_HPP

#include <vector>
#include <string>
#include "libft.h"

namespace kata
{

    class Movie
    {
    public:
        enum    e_pricecode {
            REGULAR,
            NEW_RELEASE,
            CHILDRENS
        };

    private:
        std::string title;
        int priceCode;

    public:
        Movie(std::string title, int priceCode);

        int getPriceCode();

        void setPriceCode(int code);

        std::string getTitle();
    };

    class Rental
    {
    public:
        Rental(Movie * movie, int daysRented);

        int getDaysRented();

        Movie* getMovie();

    private:
        Movie * movie;
        int daysRented;
    };

    class Customer
    {
    public:
        Customer(std::string name);

        void addRental(Rental * rental);

        std::string getName();

        std::string statement();

    private:
        std::string name;
        std::vector<Rental*> rentals;
    };

}

#endif