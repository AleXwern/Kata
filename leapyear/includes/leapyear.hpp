/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leapyear.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:57:16 by alexwern          #+#    #+#             */
/*   Updated: 2023/09/14 13:38:35 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEAPYEAR_HPP
#define LEAPYEAR_HPP

#include "stdint.h"

namespace   Leapyear
{
    bool    isLeapyear(uint32_t year);
    bool    isLeapyear2(uint32_t year);
}

#endif