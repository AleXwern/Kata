/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mastermind.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:45:20 by AleXwern          #+#    #+#             */
/*   Updated: 2022/12/20 12:01:00 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTERMIND_HPP
#define MASTERMIND_HPP

#include <iostream>
#include <string>
#include "libft.h"

const int COLOUR_AMOUNT = 4;

enum
{
	empty	= 0,
	red		= 1,
	green	= 2,
	blue	= 4,
	yellow	= 8,
	purple	= 16,
	magenta	= 32,
	black	= 64,
	white	= 128
};

class	Mastermind
{
private:
	union
	{
		uint8_t		colours[COLOUR_AMOUNT];
		uint32_t	bits;
	};
	int8_t	correctColors;
	int8_t	correctPlaces;
public:
	Mastermind(char c1 = empty, char c2 = empty, char c3 = empty, char c4 = empty);
	~Mastermind(void);
	void    generateAttempt(char c1, char c2, char c3, char c4);
	void	evaluate(Mastermind attempt);
	int8_t	getColors(void) const;
	int8_t	getPlaces(void) const;
};

#endif