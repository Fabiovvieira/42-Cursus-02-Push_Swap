/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:42:58 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/27 11:25:00 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->next)
		{
			if (*(long *)(tmp->content) > *(long *)(tmp->next->content))
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
