/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:59:24 by alexwern          #+#    #+#             */
/*   Updated: 2022/03/17 13:12:56 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordwrap.hpp"
#include <stdio.h>

int     main(int ac, char **av)
{
    Wrapper wrap;

    if (ac < 2)
        return (1);
    if (ac < 3)
        wrap.cutoff = 80;
    else
        wrap.cutoff = atoi(av[2]);
    if (wrap.cutoff < 5)
        wrap.cutoff = 80;
    wrap.wrapword(av[1]);
    printf("\033[0;33mFiletered text with cutoff %lu:\033[0m\n%s\n", wrap.cutoff, wrap.clean);
    return (0);
}