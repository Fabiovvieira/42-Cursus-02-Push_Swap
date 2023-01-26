/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:52:10 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/25 18:59:58 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_list **lst_a, t_list **lst_b)
{
	*lst_a = ft_rra(*lst_a);
	*lst_b = ft_rrb(*lst_b);
}

void	ft_pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*aux;

	aux = *lst_a;
	if (*lst_a == NULL)
		return ;
	if (*lst_b == NULL)
	{
		*lst_a = (*lst_a)->next;
		*lst_b = aux;
		(*lst_b)->next = NULL;
	}
	else
	{
		*lst_a = (*lst_a)->next;
		ft_lstadd_front(lst_b, aux);
	}
}

void	ft_pa(t_list **lst_b, t_list **lst_a)
{
	ft_pb(lst_b, lst_a);
}

void	apply_func(t_list **lst_a, t_list **lst_b, char *str)
{
	if (!ft_strcmp(str, "sa"))
		ft_sa(lst_a);
	else if (!ft_strcmp(str, "sb"))
		ft_sb(lst_b);
	else if (!ft_strcmp(str, "ss"))
		ft_ss(lst_a, lst_b);
	else if (!ft_strcmp(str, "ra"))
		*lst_a = ft_ra(*lst_a);
	else if (!ft_strcmp(str, "rb"))
		*lst_b = ft_rb(*lst_b);
	else if (!ft_strcmp(str, "rr"))
		ft_rr(lst_a, lst_b);
	else if (!ft_strcmp(str, "rra"))
		*lst_a = ft_rra(*lst_a);
	else if (!ft_strcmp(str, "rrb"))
		*lst_b = ft_rrb(*lst_b);
	else if (!ft_strcmp(str, "rrr"))
		ft_rrr(lst_a, lst_b);
	else if (!ft_strcmp(str, "pa"))
		ft_pa(lst_b, lst_a);
	else if (!ft_strcmp(str, "pb"))
		ft_pb(lst_a, lst_b);
	else
		ft_printf("There is no such commmand. Try Again\n");
}
