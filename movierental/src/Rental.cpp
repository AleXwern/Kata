// Copyright (c) 2021 Antero Nousiainen

#include "movierental.hpp"

namespace kata
{

    Rental::Rental(Movie * movie, int daysRented)
    {
        this->movie = movie;
        this->daysRented = daysRented;
    }

    int Rental::getDaysRented()
    {
        return daysRented;
    }

    kata::Movie* Rental::getMovie()
    {
        return movie;
    }

}
