/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue2.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:57:25 by marvin            #+#    #+#             */
/*   Updated: 2022/09/06 10:36:58 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "libft.h"
#include <stdio.h>

template <class T>
struct      t_item
{
    t_item  *previous;
    t_item  *next;
    T       item;
};

template <class T>
class Queue
{
private:
	size_t	    length;
	t_item<T>	*items;
public:
	Queue(void)
	{
        items = (t_item<T>*)malloc(sizeof(t_item<T>) * 0xf);
        *items = (t_item<T>){items, items, 0};
        length = 0;
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
		return (items->item);
	}

	T       back(void)
	{
		return (items->previous->item);
	}

	void    push(T item)
	{
		if (!length)
			items->item = item;
		else
		{
			items->previous->next = items->previous->next + 1;
			items->previous = items->previous->next;
			*items->previous = (t_item<T>){items->previous->previous, items, item};
		}
		length++;
		if ((length & 0xf) == 0xf)
			items = (t_item<T>*)realloc(items, sizeof(t_item<T>) * (length + 0x10));
	}

	void    pop(void)
	{
		while (0) {}
	}

	size_t	size(void)
	{
		return (length);
	}
};

#endif