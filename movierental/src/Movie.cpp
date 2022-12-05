// Copyright (c) 2021 Antero Nousiainen

#include "movierental.hpp"

namespace kata
{

    Movie::Movie(std::string title, int priceCode)
    {
        this->title = title;
        this->priceCode = priceCode;
    }

    int Movie::getPriceCode()
    {
        return priceCode;
    }

    void Movie::setPriceCode(int code)
    {
        priceCode = code;
    }

    std::string Movie::getTitle()
    {
        return title;
    }

}
