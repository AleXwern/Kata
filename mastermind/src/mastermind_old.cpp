/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mastermind.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:11:29 by AleXwern          #+#    #+#             */
/*   Updated: 2022/12/14 10:29:46 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mastermind.hpp"
#include <stdio.h>

Mastermind::Mastermind(char c1, char c2, char c3, char c4)
{
	generateAttempt(c1, c2, c3, c4);
}

Mastermind::~Mastermind(void)
{
}

void    Mastermind::generateAttempt(char c1, char c2, char c3,char c4)
{
	colours[0] = c1;
	colours[1] = c2;
	colours[2] = c3;
	colours[3] = c4;
}

void    Mastermind::evaluate(Mastermind attempt)
{
	bool    searchedSlots[4] = {0, 0, 0, 0};
	
	correctColors = 0;
	correctPlaces = 0;
	for (int i = 0; i < 4; i++)
	{
		if (this->colours[i] == attempt.colours[i])
		{
			correctPlaces++;
			searchedSlots[i] = true;
		}
		else
		{
			for (int c = 0; c < 4; c++)
			{
				bool search = ((this->colours[c] == attempt.colours[i]) && !searchedSlots[c]);
				correctColors += search;
				searchedSlots[c] |= search;
				if (search)
					break;
			}
		}
	}
}

int8_t	Mastermind::getColors(void) const
{
	return (correctColors);
}

int8_t	Mastermind::getPlaces(void) const
{
	return (correctPlaces);
}
