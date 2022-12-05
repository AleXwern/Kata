/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mastermind.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:11:29 by AleXwern          #+#    #+#             */
/*   Updated: 2022/12/05 09:03:57 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mastermind.hpp"

Mastermind::Mastermind(char c1 = empty,
                        char c2 = empty,
                        char c3 = empty,
                        char c4 = empty)
{
    colours[0] = c1;
    colours[1] = c2;
    colours[2] = c3;
    colours[3] = c4;
}

Mastermind::~Mastermind(void)
{
}
