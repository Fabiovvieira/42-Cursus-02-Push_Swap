/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:27:44 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/02/08 00:14:06 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_list **lst)
{
	int		i;
	int		indexmin;
	long	contentmin;
	t_list	*tmp;

	i = 0;
	indexmin = 0;
	tmp = *lst;
	contentmin = *(long *)(tmp->content);
	while (i < ft_lstsize(*lst))
	{
		if (*(long *)(tmp->content) <= contentmin)
		{
			indexmin = i;
			contentmin = *(long *)(tmp->content);
		}
		tmp = tmp->next;
		i++;
	}
	return (indexmin);
}

int	max_index(t_list **lst)
{
	int		i;
	int		indexmax;
	long	contentmax;
	t_list	*tmp;

	i = 0;
	indexmax = 0;
	tmp = *lst;
	contentmax = *(long *)(tmp->content);
	while (i < ft_lstsize(*lst))
	{
		if (*(long *)(tmp->content) >= contentmax)
		{
			indexmax = i;
			contentmax = *(long *)(tmp->content);
		}
		tmp = tmp->next;
		i++;
	}
	return (indexmax);
}

int	ft_abs(int x, int y)
{
	if (y > x)
		return (y - x);
	return (x - y);
}

void	check_indexmin_partition(int i, int *imin, int size, int *absstart)
{
	int	abs;

	abs = ft_abs(i, size / 2);
	if (abs > *absstart)
	{
		*imin = i;
		*absstart = abs;
	}
}

int	get_index_partition(t_list **lst, int partition)
{
	int		i;
	int		indexmin;
	t_list	*tmp;
	int		size;
	int		absstart;

	i = 0;
	size = ft_lstsize(*lst);
	indexmin = size;
	absstart = 0;
	tmp = *lst;
	while (i < ft_lstsize(*lst))
	{
		if (*(tmp->index) <= partition)
		{
			check_indexmin_partition(i, &indexmin, size, &absstart);
		}
		tmp = tmp->next;
		i++;
	}
	return (indexmin);
}
