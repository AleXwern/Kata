/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mastermind.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:35:52 by AleXwern          #+#    #+#             */
/*   Updated: 2022/12/20 13:57:17 by AleXwern         ###   ########.fr       */
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
	uint32_t places = (this->bits & attempt.bits);
	uint32_t colors = 0;
	this->correctPlaces = ft_popcnt(places);
	for (int i = 8; i < 32; i += 8)
		colors |= places ^ (this->bits & ft_rotate_right(attempt.bits ^ places, i));
	this->correctColors = ft_popcnt((colors | places) ^ places);
}

int8_t	Mastermind::getColors(void) const
{
	return (correctColors);
}

int8_t	Mastermind::getPlaces(void) const
{
	return (correctPlaces);
}
