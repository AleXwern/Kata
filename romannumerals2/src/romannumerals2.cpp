#include "romannumerals2.hpp"

const map pairs[] = {
    {"I", 1},
    {"IV", 4},
    {"V", 5},
    {"IX", 9},
    {"X", 10},
    {"XL", 40},
    {"L", 50},
    {"XC", 90},
    {"C", 100},
    {"CD", 400},
    {"D", 500},
    {"CM", 900},
    {"M", 1000}};

int addNumber(char *roman, const char* symbol, int rnum)
{
    strcat(roman, symbol);
    return rnum;
}

char *itor(int num)
{
    char *roman = (char*)malloc(32);

    roman[0] = 0;
    while (num)
    {
        if (num > 999)
            num -= addNumber(roman, "M", 1000);
        else if (num == 900)
            num -= addNumber(roman, "CM", 900);
        else if (num > 499)
            num -= addNumber(roman, "D", 500);
        else if (num == 400)
            num -= addNumber(roman, "CD", 400);
        else if (num > 99)
            num -= addNumber(roman, "C", 100);
        else if (num == 90)
            num -= addNumber(roman, "XC", 90);
        else if (num > 49)
            num -= addNumber(roman, "L", 50);
        else if (num == 40)
            num -= addNumber(roman, "XL", 40);
        else if (num > 9)
            num -= addNumber(roman, "X", 10);
        else if (num == 9)
            num -= addNumber(roman, "IX", 9);
        else if (num > 4)
            num -= addNumber(roman, "V", 5);
        else if (num == 4)
            num -= addNumber(roman, "IV", 4);
        else
            num -= addNumber(roman, "I", 1);
    }
    return (roman);
}