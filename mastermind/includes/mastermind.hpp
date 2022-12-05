/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mastermind.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:45:20 by AleXwern          #+#    #+#             */
/*   Updated: 2022/12/05 09:02:28 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTERMIND_HPP
#define MASTERMIND_HPP

#include <iostream>
#include <string>
#include "libft.h"

const int COLOUR_AMOUNT = 4;

class	Mastermind
{
private:
	uint8_t	colours[COLOUR_AMOUNT];
public:
	Mastermind(char c1, char c2, char c3, char c4);
	~Mastermind(void);

	enum
	{
		empty,
		red,
		green,
		blue,
		yellow,
		purple,
		magenta,
		orange,
		black,
		white
	};
};

#endif