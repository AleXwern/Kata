#ifndef CODECRACKER_HPP
#define CODECRACKER_HPP

#include <stdlib.h>
#include <string.h>

namespace Codecracker
{

const char  alpha[27] =    "abcdefghijklmnopqrstuvwxyz";
const char  key[27] =      "!)#(=*%&><@abcdefghijklmno";

char *decryptMessage(const char *message);

}

#endif