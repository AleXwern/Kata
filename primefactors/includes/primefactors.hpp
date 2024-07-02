/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primefactors.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:39:51 by alexwern          #+#    #+#             */
/*   Updated: 2022/06/13 12:03:43 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMEFACTORS_HPP
#define PRIMEFACTORS_HPP

extern "C" {
#include "libft.h"
}
#include <vector>

/*
**  This is ugly I know
*/
#define DEBUG   0
#define DEBUGOUT(X, ...) if (DEBUG){printf(X, __VA_ARGS__);}

#ifdef PF_LARGE
typedef t_uint64	t_pfint;
#else
typedef t_uint32	t_pfint;
#endif

class PrimeFactors
{
public:
    static std::vector<t_pfint>     generate(t_pfint);
};


#endif //PRIMEFACTORS_HPP