/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbeauvai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:48:37 by lbeauvai          #+#    #+#             */
/*   Updated: 2016/01/11 15:06:03 by lbeauvai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "list.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(void)
{
	t_list	*begin_list;
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if(!(begin_list = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	tmp1 = begin_list;
	tmp1->c = 'a';
	tmp1->prev = NULL;
	while(tmp1->c < 'z')
	{
		tmp1->next = (t_list *)malloc(sizeof(t_list));
		tmp1->next->c = tmp1->c + 1;
		tmp3 = tmp1;
		tmp1 = tmp1->next;
		tmp1->prev = tmp3;
		tmp1->next = NULL;
	}
	tmp2 = tmp1;
	while(begin_list)
	{
		ft_putchar(begin_list->c);
		begin_list = begin_list->next;
	}
	while(tmp2)
	{
		ft_putchar(tmp2->c);
		tmp2 = tmp2->prev;
	}
	return (0);
}
