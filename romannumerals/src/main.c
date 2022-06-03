/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:48:12 by alexwern          #+#    #+#             */
/*   Updated: 2022/06/03 10:41:01 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "romannumerals.h"
#include <stdio.h>

int     main(void)
{
    ft_putendl(itor(3999));
    ft_putendl(itor(4444));
    ft_putendl(itor(2888));
    ft_putendl(itor(1234));
    ft_putendl(itor(0xffff));
    printf("%d\n", ft_strequ("X", itor(10)));
    printf("%d\n", ft_strequ("II", itor(2)));
    
    return (0);
}