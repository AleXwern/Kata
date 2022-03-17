/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordwrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:45:01 by alexwern          #+#    #+#             */
/*   Updated: 2022/03/17 13:11:51 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordwrap.hpp"
#include <stdio.h>

void        Wrapper::wrapword(const char *str)
{
    size_t  pos = 0;
    size_t  prevpos = 0;
    size_t  space = 0;

    this->clean = ft_strdup(str);
    while (this->clean[pos])
    {
        if (this->clean[pos] != ' ')
        {
            pos++;
            continue;
        }
        if (pos - prevpos >= this->cutoff)
        {
            DEBUGOUT("Cutoff at: %lu - %lu = %lu with %lu\n", pos, prevpos, pos-prevpos, space-prevpos);
            this->clean[space] = '\n';
            prevpos = space;
        }
        space = pos;
        DEBUGOUT("Space set off: %lu\n", space-prevpos);
        pos++;
    }
}