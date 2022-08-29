/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:32:59 by marvin            #+#    #+#             */
/*   Updated: 2022/08/29 09:32:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "libft.h"
#include <stdio.h>

template <class T>
class Queue
{
private:
	size_t	length;
	T		*items;
public:
	Queue(void)
	{
		length = 0;
		items = (T*)malloc(sizeof(T) * 0xf);
	}

	~Queue(void)
	{
		free(items);
	}

	bool	empty(void)
	{
		return (length == 0);
	}

	T       front(void)
	{
		return (length == 0 ? 0 : items[0]);
	}

	T       back(void)
	{
		return (length == 0 ? 0 : items[length - 1]);
	}

	void    push(T item)
	{
		items[length] = item;
		length++;
		if ((length & 0xf) == 0xf)
			items = (T*)realloc(items, sizeof(T) * (length + 0x10));
	}

	void    pop(void)
	{
		if (length)
		{
			length--;
			items = ft_memcpy(items, items+1, length);
		}
	}

	size_t	size(void)
	{
		return (length);
	}
};

#endif