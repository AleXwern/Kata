/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:56:01 by marvin            #+#    #+#             */
/*   Updated: 2022/08/29 09:56:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch_amalgamated.hpp"
#include "queue.hpp"

TEST_CASE("Empty", "[require]")
{
	Queue<int>	queue;
	REQUIRE(queue.empty() == true);
}

TEST_CASE("One item", "[require]")
{
	Queue<int>	queue;
	queue.push(100);
	REQUIRE(queue.size() == 1);
	REQUIRE(queue.empty() == false);
}

TEST_CASE("Backmost item", "[require]")
{
	Queue<int>	queue;
	queue.push(100);
	queue.push(1000);
	REQUIRE(queue.back() == 1000);
	REQUIRE(queue.front() == 100);
}

TEST_CASE("Many items", "[require]")
{
	Queue<int>	queue;
	for (int i = 200; i > 0; i--)
		queue.push(i);
	REQUIRE(queue.size() == 200);
}
