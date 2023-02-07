/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_plus_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:22:31 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/02/07 14:53:09 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aux_laspart(t_list **lst_a, t_list **lst_b, int *index, int size)
{
	if (*index <= size / 2)
	{
		while (*index > 0)
		{
			*lst_a = ft_ra(*lst_a);
			ft_printf("rb\n");
			(*index)--;
		}
		ft_pb(lst_a, lst_b);
		ft_printf("pa\n");
	}
	else
	{
		while (*index < size)
		{
			*lst_a = ft_rra(*lst_a);
			ft_printf("rrb\n");
			(*index)++;
		}
		ft_pb(lst_a, lst_b);
		ft_printf("pa\n");
	}
}

void	ft_sort_lastpart(t_list **lst_a, t_list **lst_b, int (*fun)(t_list **))
{
	int	index;
	int	size;

	size = ft_lstsize(*lst_a);
	while (size > 2)
	{
		index = (*fun)(lst_a);
		aux_laspart(lst_a, lst_b, &index, size);
		size = ft_lstsize(*lst_a);
	}
	if ((*(long *)((*lst_a)->content) < *(long *)((*lst_a)->next->content)))
	{
		ft_sa(lst_a);
		ft_printf("sb\n");
	}
}

void	check_num_part(t_list **lst_a, t_list **lst_b, int multpart, int part)
{
	(void)lst_a;
	if (*((*lst_b)->index) < (multpart + (multpart - part)) / 2)
	{
		*lst_b = ft_rb(*lst_b);
		ft_printf("rb\n");
	}
}
