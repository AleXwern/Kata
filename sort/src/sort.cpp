/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:39:49 by AleXwern          #+#    #+#             */
/*   Updated: 2023/02/16 13:36:48 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.hpp"
#include <iostream>

static void	trySwap(std::vector<int> &array, size_t pos, size_t &checks)
{
	checks++;
	if (array[pos-1] > array[pos])
	{
		std::swap(array[pos-1], array[pos]);
		trySwap(array, pos-1, checks);
	}
}

size_t	Sort::sort(std::vector<int> &array)
{
	size_t	checks = 0;
	
	for (size_t i = 1; i < array.size(); i++)
		trySwap(array, i, checks);
	return (checks);
}