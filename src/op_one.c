/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_one.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:50:40 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/25 22:47:56 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint(t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (*lst == NULL)
	{
		ft_printf("Empty list\n");
		return ;
	}
	tmp = (*lst);
	while (tmp)
	{
		ft_printf("%d ", *(long *)(tmp->content));
		tmp = tmp->next;
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_sa(t_list **lst)
{
	t_list	*sec;
	t_list	*fir;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	fir = *lst;
	sec = (*lst)->next;
	*lst = sec;
	fir->next = sec->next;
	sec->next = fir;
}

void	ft_sb(t_list **lst)
{
	ft_sa(lst);
}

void	ft_ss(t_list **lst_a, t_list **lst_b)
{
	ft_sa(lst_a);
	ft_sb(lst_b);
}
