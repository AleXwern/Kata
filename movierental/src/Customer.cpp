// Copyright (c) 2021 Antero Nousiainen

#include "movierental.hpp"

namespace kata
{

    Customer::Customer(std::string name)
    {
        this->name = name;
    }

    void Customer::addRental(Rental * rental)
    {
        rentals.push_back(rental);
    }

    std::string Customer::getName()
    {
        return name;
    }

    std::string Customer::statement()
    {
        double totalAmount = 0;
        int frequentRenterPoints = 0;
        std::string result = "Rental Record for " + getName() + "\n";
        for (std::vector<Rental*>::iterator rentals = this->rentals.begin();
            rentals != this->rentals.end();
            rentals++)
        {
            double thisAmount = 0;
            Rental * each = *rentals;
            // determines the amount for each line
            switch (each->getMovie()->getPriceCode())
            {
            case Movie::REGULAR:
                thisAmount += 2;
                if (each->getDaysRented() > 2)
                    thisAmount += (each->getDaysRented() - 2) * 1.5;
                break;
            case Movie::NEW_RELEASE:
                thisAmount += each->getDaysRented() * 3;
                break;
            case Movie::CHILDRENS:
                thisAmount += 1.5;
                if (each->getDaysRented() > 3)
                    thisAmount += (each->getDaysRented() - 3) * 1.5;
                break;
            }
            frequentRenterPoints++;
            if (each->getMovie()->getPriceCode() == Movie::NEW_RELEASE && each->getDaysRented() > 1)
                frequentRenterPoints++;

            result += "\t" + each->getMovie()->getTitle() + "\t" + std::to_string(thisAmount).substr(0, 3) + "\n";
            totalAmount += thisAmount;
        }
        result += "You owed " + std::to_string(totalAmount).substr(0, totalAmount > 9 ? 4 : 3) + "\n";
        result += "You earned " + std::to_string(frequentRenterPoints) + " frequent renter points\n";
        return result;
    }

}
