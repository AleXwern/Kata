/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordwrap2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:11:45 by alexwern          #+#    #+#             */
/*   Updated: 2024/02/15 14:13:08 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordwrap2.hpp"

Wordwrap::Wordwrap(int len)
    : length(len < 1 ? 1 : len)
{
}

Wordwrap::~Wordwrap()
{
}

char *Wordwrap::wrap(const char* str)
{
    char *newstr = strdup(str);
    int len = strlen(str);
    
    strcpy(newstr, str);
    for (int i = length; i < len;)
    {
        while (newstr[i] != ' ' && i > 0)
            i--;
        if (newstr[i] != ' ')
        {
            i += length;
            while (newstr[i] != ' ' && i < len)
                i++;
        }
        if (newstr[i] == '\0')
            break;
        newstr[i] = '\n';
        i += length;
    }
    return (newstr);
}

char *Wordwrap::wrap(const char* str, int len)
{
    length = len < 1 ? 1 : len;
    return wrap(str);
}