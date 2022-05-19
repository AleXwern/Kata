/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   romannumerals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:06:15 by alexwern          #+#    #+#             */
/*   Updated: 2022/05/19 09:33:13 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "romannumerals.h"

const char romans[][3] = {"CM","D","CD","XC","L","XL","IX","V","IV"};

char            *itor(t_uint16 num)
{
    char        *roman = malloc(16);
    t_uint16    curlength = 0;
	t_uint16	maxlength = 16;

    while (num)
    {
		if (num >= 1)
        {
            strcat(roman + curlength, "I");
            curlength++;
        }
        if (curlength > maxlength - 2)
        {
            maxlength += 16;
            roman = realloc(roman, maxlength);
        }
    }
	return (roman);
}