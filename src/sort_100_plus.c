/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:21:07 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/02/08 11:20:13 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_up_push(t_list **lst_a, t_list **lst_b, int *i, int *size)
{
	while (*i > 0)
	{
		*lst_a = ft_ra(*lst_a);
		ft_printf("ra\n");
		(*i)--;
	}
	ft_pb(lst_a, lst_b);
	ft_printf("pb\n");
	(*size)--;
}

void	move_down_push(t_list **lst_a, t_list **lst_b, int *i, int *size)
{
	while (*i < *size)
	{
		*lst_a = ft_rra(*lst_a);
		ft_printf("rra\n");
		(*i)++;
	}
	ft_pb(lst_a, lst_b);
	ft_printf("pb\n");
	(*size)--;
}

void	ft_sort_plus_100(t_list **lst_a, t_list **lst_b, int partition)
{
	int	size;
	int	length;
	int	index;
	int	part;
	int	multpart;

	size = ft_lstsize(*lst_a);
	part = size / partition;
	multpart = part;
	length = size;
	while (size > 0)
	{
		while (size >= (length - multpart) && size > 0)
		{
			index = get_index_partition(lst_a, multpart);
			if (index <= size / 2)
				move_up_push(lst_a, lst_b, &index, &size);
			else
				move_down_push(lst_a, lst_b, &index, &size);
			check_num_part(lst_a, lst_b, multpart, part);
			if (size == (length - multpart))
				break ;
		}
		multpart += part;
	}
}

void	sort_300_plus(t_list **stack_a, t_list **stack_b)
{
	ft_sort_plus_100(stack_a, stack_b, 2);
	ft_sort_plus_100_2(stack_b, stack_a, 8);
	ft_sort_plus_100(stack_a, stack_b, 32);
	ft_sort_lastpart(stack_b, stack_a, &max_index);
	last_move(stack_a, stack_b);
}
