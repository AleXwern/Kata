#include "codecracker.hpp"

char *Codecracker::decryptMessage(const char *message)
{
    if (message == NULL)
        return NULL;

    size_t  i = 0;
    char    *decryptedMsg = (char*)calloc(strlen(message)+1, sizeof(char));
    
    for (; i < strlen(message); i++)
    {
        for (size_t c = 0; c < strlen(key); c++)
        {
            if (key[c] == message[i])
            {
                decryptedMsg[i] = alpha[c];
                break;;
            }
        }
    }
    decryptedMsg[i] = '\0';
    return (decryptedMsg);
}
