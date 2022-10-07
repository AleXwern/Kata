// Copyright (c) 2021 Antero Nousiainen

#ifndef MOVIE_HPP_
#define MOVIE_HPP_

#include <string>

namespace kata
{

    class Movie
    {
    public:
        static const int CHILDRENS = 2;
        static const int REGULAR = 0;
        static const int NEW_RELEASE = 1;

    private:
        std::string title;
        int priceCode;

    public:
        Movie(std::string title, int priceCode);

        int getPriceCode();

        void setPriceCode(int code);

        std::string getTitle();
    };

}

#endif
