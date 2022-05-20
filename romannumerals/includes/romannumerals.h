/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   romannumerals.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:50:09 by alexwern          #+#    #+#             */
/*   Updated: 2022/05/19 11:17:04 by alexwern         ###   ########.fr       */
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

char	*itor(t_uint16 num);

#endif