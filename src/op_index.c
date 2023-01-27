/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:27:44 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/27 17:29:23 by fvalli-v         ###   ########.fr       */
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

void	check_indexmin_partition(int *flag, int i, int *imin, int size)
{
	if (*flag == 0)
	{
		*imin = i;
		*flag = 1;
	}
	else
	{
		if (i <= size / 2)
		{
			if (i <= *imin)
				*imin = i;
		}
		else
		{
			if (*imin <= size / 2)
			{
				if ((size - 1 - i) < *imin)
					*imin = i;
			}
			else if (i > *imin)
				*imin = i;
		}
	}
}

int	get_index_partition(t_list **lst, int partition)
{
	int		i;
	int		indexmin;
	t_list	*tmp;
	int		size;
	int		flag;

	i = 0;
	size = ft_lstsize(*lst);
	indexmin = size;
	flag = 0;
	tmp = *lst;
	while (i < ft_lstsize(*lst))
	{
		if (*(tmp->index) < partition)
		{
			check_indexmin_partition(&flag, i, &indexmin, size);
		}
		tmp = tmp->next;
		i++;
	}
	return (indexmin);
}
