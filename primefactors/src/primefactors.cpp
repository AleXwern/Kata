/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primefactors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 08:30:57 by alexwern          #+#    #+#             */
/*   Updated: 2022/06/06 10:22:40 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "primefactors.hpp"

std::vector<t_pfint>     	PrimeFactors::generate(t_pfint num)
{
    std::vector<t_pfint>    primes;
	for (t_pfint n = 2; n <= num; n++)
	{
		while (num % n == 0)
		{
			primes.push_back(n);
			num /= n;
		}
	}
	return (primes);
}