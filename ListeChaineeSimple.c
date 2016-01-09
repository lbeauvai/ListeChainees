/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeauvai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 14:34:30 by lbeauvai          #+#    #+#             */
/*   Updated: 2016/01/09 18:30:51 by lbeauvai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(void)
{
	t_list	*begin_list;
	t_list	*tmp;
	t_list	*tmp2;

	if (!(begin_list = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	tmp = begin_list;
	tmp2 = begin_list;
	tmp->c = 'a';
	while (tmp->c <= 'z')
	{
		tmp->next = (t_list *)malloc(sizeof(t_list));
		tmp->next->c = tmp->c + 1;
		tmp = tmp->next;
		tmp->next = NULL;
	}
	tmp2->next->next->c = 'C';
	while (begin_list->next != NULL)
	{
		ft_putchar(begin_list->c);
		begin_list = begin_list->next;
	}
	return (0);
}
