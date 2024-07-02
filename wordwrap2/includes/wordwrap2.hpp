/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordwrap2.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:09:53 by alexwern          #+#    #+#             */
/*   Updated: 2024/02/15 13:35:39 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDWRAP_HPP
#define WORDWRAP_HPP

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

class Wordwrap
{
private:
    int length;
public:
    Wordwrap(int len);
    ~Wordwrap();
    char *wrap(const char *str);
    char *wrap(const char* str, int len);
};

#endif