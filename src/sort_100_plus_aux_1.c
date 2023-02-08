/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_plus_aux_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:10:02 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/02/08 13:47:11 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_up_push_2(t_list **lst_a, t_list **lst_b, int *i, int *size)
{
	while (*i > 0)
	{
		*lst_a = ft_ra(*lst_a);
		ft_printf("rb\n");
		(*i)--;
	}
	ft_pb(lst_a, lst_b);
	ft_printf("pa\n");
	(*size)--;
}

void	move_down_push_2(t_list **lst_a, t_list **lst_b, int *i, int *size)
{
	while (*i < *size)
	{
		*lst_a = ft_rra(*lst_a);
		ft_printf("rrb\n");
		(*i)++;
	}
	ft_pb(lst_a, lst_b);
	ft_printf("pa\n");
	(*size)--;
}

void	ft_sort_plus_100_2(t_list **lst_a, t_list **lst_b, int partition)
{
	int	size;
	int	index;
	int	part;
	int	multpart;

	size = ft_lstsize(*lst_a);
	part = size / partition;
	multpart = size - part;
	while (size > 0)
	{
		while (size >= (multpart) && size > 0)
		{
			index = get_index_partition_2(lst_a, multpart);
			if (index <= size / 2)
				move_up_push_2(lst_a, lst_b, &index, &size);
			else
				move_down_push_2(lst_a, lst_b, &index, &size);
			check_num_part2(lst_a, lst_b, multpart, part);
			if (size == (multpart))
				break ;
		}
		multpart -= part;
	}
}

int	get_index_partition_2(t_list **lst, int partition)
{
	int		i;
	int		indexmin;
	t_list	*tmp;
	int		size;
	int		absstart;

	i = 0;
	size = ft_lstsize(*lst);
	indexmin = 0;
	absstart = 0;
	tmp = *lst;
	while (i < ft_lstsize(*lst))
	{
		if (*(tmp->index) > partition)
		{
			check_indexmin_partition(i, &indexmin, size, &absstart);
		}
		tmp = tmp->next;
		i++;
	}
	return (indexmin);
}

void	check_num_part2(t_list **lst_a, t_list **lst_b, int multpart, int part)
{
	(void)lst_a;
	if (*((*lst_b)->index) < (multpart + (multpart + part)) / 2)
	{
		*lst_b = ft_rb(*lst_b);
		ft_printf("ra\n");
	}
}
