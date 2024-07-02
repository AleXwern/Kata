#include "catch_amalgamated.hpp"
#include "codecracker.hpp"

static char isEqual(const char* str1, const char *str2)
{
    return strcmp(str1, str2) == 0;
}

TEST_CASE("NULL", "[require]")
{
    REQUIRE(Codecracker::decryptMessage(NULL) == NULL);
}

TEST_CASE("Empty", "[require]")
{
    REQUIRE(isEqual(Codecracker::decryptMessage(""), ""));
}

TEST_CASE("Single char", "[require]")
{
    REQUIRE(isEqual(Codecracker::decryptMessage("o"), "z"));
}

TEST_CASE("Invalid char", "[require]")
{
    REQUIRE(isEqual(Codecracker::decryptMessage("z"), "\0"));
}

TEST_CASE("Char array", "[require]")
{
    REQUIRE(isEqual(Codecracker::decryptMessage("!)#(=*%&><@abcdefghijklmno"), "abcdefghijklmnopqrstuvwxyz"));
}
