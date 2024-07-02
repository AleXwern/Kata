/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leapyear.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:54:45 by alexwern          #+#    #+#             */
/*   Updated: 2023/09/14 13:54:51 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leapyear.hpp"

bool    Leapyear::isLeapyear(uint32_t year)
{
    bool isLeap = false;
    
    if (year % 4 == 0)
        isLeap = true;
    if (year % 100 == 0)
        isLeap = false;
    if (year % 400 == 0)
        isLeap = true;
    return isLeap;
}

bool    Leapyear::isLeapyear2(uint32_t year)
{
    uint16_t num[] = {4, 100, 400};
    bool    ret = false;

    for (int i = 0; i < 3; i++)
    {
        if (year % num[i] == 0)
            ret = (i % 2 == 0);
    }
    return ret;
}
