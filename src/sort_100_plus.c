/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:21:07 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/27 11:58:29 by fvalli-v         ###   ########.fr       */
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
		while (size > (length - multpart) && size > 0)
		{
			index = get_index_partition(lst_a, multpart);
			if (index <= size / 2)
				move_up_push(lst_a, lst_b, &index, &size);
			else
				move_down_push(lst_a, lst_b, &index, &size);
			check_num_part(lst_a, lst_b, multpart, part);
		}
		multpart += part;
		if (multpart >= length - 1)
			multpart = length;
	}
}
