/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:32:06 by alexwern          #+#    #+#             */
/*   Updated: 2024/02/15 14:17:55 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordwrap2.hpp"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 1;
    Wordwrap wrap(72);
    printf("%s\n", wrap.wrap(argv[1]));
    return 0;
}