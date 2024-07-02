/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bowling.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:21:10 by AleXwern          #+#    #+#             */
/*   Updated: 2023/01/30 10:33:09 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bowling.hpp"

Bowling::Bowling(void)
{
	score = 0;
	round = 0;
	set = 0;
	ft_bzero(pins, sizeof(pins));
}

Bowling::~Bowling()
{
}

void	Bowling::doRound(u_int8_t knocked)
{
	switch ((round % 2 == 0) + (round < 11)) 
	{
	case 2:
	case 0:
		break;
	case 1:
		set++;
		break;
	}
	if (knocked == 10 && round % 2 == 0)
		round++;
	round++;
}