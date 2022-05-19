/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordwrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:45:01 by alexwern          #+#    #+#             */
/*   Updated: 2022/04/05 11:37:53 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordwrap.hpp"
#include <stdio.h>

std::string     Wrapper::wrapword(const std::string str, size_t cutoff)
{
    std::string clean;
    size_t      last = cutoff;
    size_t      first = 0;

    clean.assign(str);
    while (1)
    {
        first = last - cutoff;
        for (; last > first; last--)
        {
            if (clean[last] == ' ')
            {
                clean[last] = '\n';
                break;
            }
            else if (clean[last] == '\0')
                return (clean);
        }
        last += cutoff + 1;//(last == first);
    }
}