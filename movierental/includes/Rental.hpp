// Copyright (c) 2021 Antero Nousiainen

#ifndef RENTAL_HPP_
#define RENTAL_HPP_

#include "Movie.hpp"

namespace kata
{

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

}

#endif
