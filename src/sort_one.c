/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:04:12 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/26 09:38:46 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	look_for_contentmin(t_list *tmp, long *contentmin, t_list **aux)
{
	while (tmp)
	{
		if (*(long *)(tmp->content) <= *contentmin && !*(tmp->index))
		{
			*aux = tmp;
			*contentmin = *(long *)((tmp)->content);
		}
		tmp = (tmp)->next;
	}
}

void	sort_indexation(t_list **lst)
{
	int		indexmin;
	long	contentmin;
	int		size;
	t_list	*tmp;
	t_list	*aux;

	indexmin = 1;
	tmp = *lst;
	size = ft_lstsize(*lst);
	contentmin = *(long *)(tmp->content);
	while (size--)
	{
		while (*(tmp->index))
		{
			tmp = tmp->next;
			contentmin = *(long *)(tmp->content);
		}
		look_for_contentmin(tmp, &contentmin, &aux);
		*(aux->index) = indexmin;
		tmp = *lst;
		contentmin = *(long *)(tmp->content);
		indexmin++;
	}
}

void	last_move(t_list **lst_a, t_list **lst_b)
{
	ft_pa(lst_b, lst_a);
	ft_printf("pa\n");
	ft_pa(lst_b, lst_a);
	ft_printf("pa\n");
}

void	sort_3(t_list **lst)
{
	int	maxindex;

	maxindex = max_index(lst);
	if (maxindex == 1)
	{
		*lst = ft_rra(*lst);
		ft_printf("rra\n");
	}
	else if (maxindex == 0)
	{
		*lst = ft_ra(*lst);
		ft_printf("ra\n");
	}
	if (*((*lst)->index) > *((*lst)->next->index))
	{
		ft_sa(lst);
		ft_printf("sa\n");
	}
}

void	sort_2(t_list **lst)
{
	if (*((*lst)->index) > *((*lst)->next->index))
	{
		ft_sa(lst);
		ft_printf("sa\n");
	}
}
