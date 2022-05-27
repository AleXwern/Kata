/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:54:38 by alexwern          #+#    #+#             */
/*   Updated: 2022/05/27 13:44:40 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "romannumerals.h"

const char complex[][3] = {"CM", "CD", "XC", "XL", "IX", "IV"};
const char romans[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
const t_uint16 ints[] = {900, 400, 90, 40, 9, 4, 1000, 500, 100, 50, 10, 5, 1};

t_uint16		rtoi(const char *roman)
{
	t_uint16	num = 0;
	char		*str;
	char		*temp;
	size_t		len;

	str = ft_strdup(roman);
	len = ft_strlen(roman);
	for (t_uint8 i = 0; i < 6 / 2; i++)
	{
		if (temp = ft_strstr(str, regex[i].insert))
		{
			((t_uint16*)temp)[0] = 0x0101;
			num += ints[i];
		}
	}
	for (t_uint8 i = 0; i < sizeof(romans); i++)
	{
		for (size_t r = 0; r < len; r++)
		{
			if (str[r] == romans[i])
			{
				str[r] = 0;
				num += ints[i + 6];
			}
		}
	}
	free(str);
	return (num);
}