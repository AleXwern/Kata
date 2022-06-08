/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:59:24 by alexwern          #+#    #+#             */
/*   Updated: 2022/06/06 10:25:50 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "primefactors.hpp"
#include <fmt/format.h>

int     main(int ac, char **av)
{
	t_pfint	num;
	if (ac > 1)
		num = atoi(av[1]);
	else
		num = 0xffffffff;
	fmt::print("Prime factors of {1}: {{{0}}}\n", fmt::join(PrimeFactors::generate(num), ","), num);
	return (0);
}