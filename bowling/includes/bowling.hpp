/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bowling.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:15:51 by AleXwern          #+#    #+#             */
/*   Updated: 2023/01/30 10:23:38 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOWLING_HPP
#define BOWLING_HPP

#include "libft.h"

class Bowling
{
private:
	u_int8_t	round;
	u_int8_t	set;
	int16_t		score;
	u_int8_t	pins[10];
public:
	Bowling(void);
	~Bowling();
	void	doRound(u_int8_t knocked);
};


#endif