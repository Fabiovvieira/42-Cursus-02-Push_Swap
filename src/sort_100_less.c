/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_less.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:46:30 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/26 11:36:51 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_and_push_b(t_list **lst_a, t_list **lst_b, int *m_i, int *size)
{
	*m_i = min_index(lst_a);
	if (*m_i <= *size / 2)
	{
		while (*m_i)
		{
			*lst_a = ft_ra(*lst_a);
			ft_printf("ra\n");
			(*m_i)--;
		}
		ft_pb(lst_a, lst_b);
		ft_printf("pb\n");
	}
	else
	{
		while (*m_i < *size)
		{
			*lst_a = ft_rra(*lst_a);
			ft_printf("rra\n");
			(*m_i)++;
		}
		ft_pb(lst_a, lst_b);
		ft_printf("pb\n");
	}
	*size = ft_lstsize(*lst_a);
}

void	ft_sort_less_100(t_list **lst_a, t_list **lst_b)
{
	int	minindex;
	int	size;

	size = ft_lstsize(*lst_a);
	while (size > 2)
	{
		move_and_push_b(lst_a, lst_b, &minindex, &size);
	}
	if (*(long *)((*lst_a)->content) > *(long *)((*lst_a)->next->content))
	{
		ft_sa(lst_a);
		ft_printf("sa\n");
	}
	size = ft_lstsize(*lst_b);
	while (size)
	{
		ft_pa(lst_b, lst_a);
		ft_printf("pa\n");
		size--;
	}
}
