/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordwrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:39:51 by alexwern          #+#    #+#             */
/*   Updated: 2022/04/04 08:58:06 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDWRAP_HPP
#define WORDWRAP_HPP

extern "C" {
#include "libft_asm.h"
}
#include <string>

/*
**  This is ugly I know
*/
#define DEBUG   0
#define DEBUGOUT(X, ...) if (DEBUG){printf(X, __VA_ARGS__);}

class Wrapper
{
public:
    std::string     wrapword(const std::string str, size_t cutoff);
};


#endif //WORDWRAP_HPP