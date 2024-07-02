/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:27:47 by alexwern          #+#    #+#             */
/*   Updated: 2023/11/02 14:27:54 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <codecracker.hpp>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char alpha[] = "!)#(=*%&><@abcdefghijklmno";
    printf("TEST: -%s-\n", Codecracker::decryptMessage("a"));
    printf("-%s-\n", "abcdefghijklmnopqrstuvwxyz");
    printf("-%s-\n", "!)#(£*%&><@abcdefghijklmno");
    for (size_t i = 0; i < strlen(alpha); i++)
    {
        char c = alpha[i];
        printf("Char %c -> -%s-\n", alpha[i], Codecracker::decryptMessage((char*)(&c)));
    }
    return 0;
}