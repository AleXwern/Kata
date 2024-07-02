/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:26:34 by AleXwern          #+#    #+#             */
/*   Updated: 2023/02/13 10:37:44 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.hpp"

static void	sortSublist(std::vector<int> array, int sublist, int size)
{
	for (int i = sublist+size; i < array.size(); i += size)
	{
		
	}
}

void		Sort::sort(std::vector<int> array)
{
	int sublists = array.size() >> 1;
	
	while (sublists)
	{
		for (int i = 0; i < sublists; i++)
		{
			sortSublist(array, i, sublists);
		}
		sublists >>= 1;
	}
}
