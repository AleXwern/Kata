/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:24:56 by alexwern          #+#    #+#             */
/*   Updated: 2022/09/08 11:23:08 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordwrap.hpp"
#include <fcntl.h>

char	*argparse(char **av, int ac)
{
    //int		index = 2;
	char	*str = ft_strnew(1);
	char	*dummy;
	int		fd;
	char	*c = ft_strdup(" ");

	ac=0;
	if (ft_strequ(av[1], "-f"))
	{
		if ((fd = open(av[2], O_RDONLY)) > 0)
		{
			while (get_next_line(fd, &dummy) > 0)
			{
				ft_putendl(str);
				str = ft_strjoin(str, dummy);
				str = ft_strjoin(str, c);
				free(dummy);
			}
		}
		else
			write(1, "Error opening a file\n", 22);
		close(fd);
	}
	fd = ac;
	return (str);
}