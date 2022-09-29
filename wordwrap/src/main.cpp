/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:59:24 by alexwern          #+#    #+#             */
/*   Updated: 2022/09/08 11:19:40 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordwrap.hpp"
#include <stdio.h>

int     main(int ac, char **av)
{
    Wrapper wrap;
    size_t  cutoff;
    char    *str;

    if (ac < 2)
        return (1);
    if (ac == 2)
        cutoff = 80;
    else
    {
        str = argparse(av, ac);
        cutoff = 72;
        //cutoff = atoi(av[2]);
    }
    if (cutoff < 5)
        cutoff = 80;
    printf("\033[0;33mFiletered text with cutoff %lu:\033[0m\n%s\n", cutoff, wrap.wrapword(str, cutoff).c_str());
    return (0);
}