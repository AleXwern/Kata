/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <alex.nystrom5@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:00:23 by AleXwern          #+#    #+#             */
/*   Updated: 2023/02/16 13:16:14 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.hpp"
#include <iostream>

int main(void)
{
	//std::vector<int> arr = {36, 0, 16, 28, 82, 13, 57, 85, 56, 96, 99, 67, 38, 41, 3, 43, 54, 5, 33, 73, 31, 6, 42, 68, 72, 26, 81, 76, 87, 78, 92, 35, 71, 34, 69, 55, 8, 15, 25, 4, 91, 29, 90, 44, 59, 37, 12, 94, 89, 20};
	std::vector<int> arr = {};
	for (int i = 0; i < 100'000; i++)
		arr.push_back(100'000-i);
	//arr.push_back(rand());
	std::cout << "Sorting...\n";
	std::cout << Sort::sort(arr) << " checks performed!\n";
	//for (size_t i = 0; i < arr.size(); i++)
	//	std::cout << arr[i] << " ";
	//std::cout << "\n";
	return 0;
}