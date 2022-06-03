/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   romannumerals.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:50:09 by alexwern          #+#    #+#             */
/*   Updated: 2022/06/03 09:49:02 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROMANNUMERALS_H
#define ROMANNUMERALS_H

#include "libft_asm.h"

typedef struct  s_romans
{
    char        *insert;
    char        *needle;
}               t_romans;

extern const t_romans regex[6];
extern const char romans[7];
extern const t_uint16 ints[13];

char	*itor(t_uint16 num);

#endif