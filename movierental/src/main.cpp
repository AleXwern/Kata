/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:36:05 by AleXwern          #+#    #+#             */
/*   Updated: 2022/10/07 10:38:27 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Customer.hpp"
#include <stdio.h>

int     main(void)
{
	kata::Customer asiakas("Janne Jonne");
	printf("%s", asiakas.statement().c_str());
	return(0);
}