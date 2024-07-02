// Copyright (c) 2021 Antero Nousiainen

#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_

#include <vector>
#include "Rental.hpp"

namespace kata
{

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
