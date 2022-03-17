/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordwrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:39:51 by alexwern          #+#    #+#             */
/*   Updated: 2022/03/17 13:10:52 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDWRAP_HPP
#define WORDWRAP_HPP

extern "C" {
    #include "libft_asm.h"
}

/*
**  This is ugly I know
*/
#define DEBUG   0
#define DEBUGOUT(X, ...) if (DEBUG){printf(X, __VA_ARGS__);}

class Wrapper
{
public:
    size_t  cutoff;
    char    *clean;

    void    wrapword(const char *str);
};


#endif //WORDWRAP_HPP