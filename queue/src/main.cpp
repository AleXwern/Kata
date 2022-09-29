/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:09:07 by marvin            #+#    #+#             */
/*   Updated: 2022/08/29 10:09:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue2.hpp"

int     main(void)
{
	Queue<double> jono;

	for (int i; i < 0x1fff; i++)
		jono.push(i);
	printf("Things %f and %f\n", jono.front(), jono.back());
	return (0);
}