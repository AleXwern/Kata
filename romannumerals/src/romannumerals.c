/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   romannumerals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:06:15 by alexwern          #+#    #+#             */
/*   Updated: 2022/06/03 11:43:49 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "romannumerals.h"

const t_romans regex[] = {{"CM","DCCCC"}, {"CD","CCCC"}, {"XC","LXXXX"}, {"XL","XXXX"}, {"IX","VIIII"}, {"IV","IIII"}};
const char romans[] = {'I','V','X','L','C','D','M'};
const t_uint16 ints[] = {1, 5, 10, 50, 100, 500, 1000, 4, 9, 40, 90, 400, 900};

static void     text_replace(char *roman, const char *str, int i)
{
    t_uint8     length = ((i % 2 == 0) ? 5 : 4);

    memcpy(roman + (str - roman), regex[i].insert, 2);
    memcpy(roman + (str - roman) + 2, str + length, ft_strlen(str + length) + 1);
}

char            *itor(t_uint16 num)
{
    char        *roman = (char*)malloc(16);
    char        *str;
    t_uint16    curlength = 0;
	t_uint16	maxlength = 16;

    while (num)
    {
        t_uint8 bits = (num >= 1000) + (num >= 500) + (num >= 100) + (num >= 50) + (num >= 10) + (num >= 5) + (num >= 1) - 1;

        roman[curlength] = romans[bits];
        curlength++;
        num -= ints[bits];
        if (curlength >= maxlength)
        {
            maxlength += 16;
            roman = realloc(roman, maxlength);
        }
    }
    roman[curlength] = '\0';
    for (size_t i = 0; i < sizeof(regex) / sizeof(t_romans); i++)
    {
        while ((str = ft_strstr(roman, regex[i].needle))) //Unsure if this can ever run >1 times
            text_replace(roman, str, i);
    }
    return (realloc(roman, ft_strlen(roman) + 1));
}
