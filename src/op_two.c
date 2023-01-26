/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:50:36 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/25 19:00:13 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_ra(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	tmp = lst->next;
	lst->next = NULL;
	ft_lstadd_back(&tmp, lst);
	return (tmp);
}

t_list	*ft_rb(t_list *lst)
{
	return (ft_ra(lst));
}

void	ft_rr(t_list **lst_a, t_list **lst_b)
{
	*lst_a = ft_ra(*lst_a);
	*lst_b = ft_rb(*lst_b);
}

t_list	*ft_rra(t_list *lst)
{
	t_list	*last;
	t_list	*tmp;

	tmp = lst;
	last = ft_lstlast(lst);
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	while (lst)
	{
		if (lst->next == last)
		{
			lst->next = NULL;
			break ;
		}
		lst = lst->next;
	}
	ft_lstadd_front(&tmp, last);
	return (tmp);
}

t_list	*ft_rrb(t_list *lst)
{
	return (ft_rra(lst));
}
