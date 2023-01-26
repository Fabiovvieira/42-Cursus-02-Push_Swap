/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:41:06 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/26 11:36:32 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(t_list **lst, long num)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (num == *(long *)tmp->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_list	*ft_nodenew(void *content)
{
	t_list	*new;
	int		*num;

	num = (int *)malloc(sizeof(int));
	*num = 0;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->index = num;
	new->content = content;
	new->next = NULL;
	return (new);
}

int	insert_node(t_list **lst, char *str)
{
	long	*num;

	num = malloc(sizeof(long));
	if (!ft_strisdigit(str))
		return (0);
	*num = ft_atoi(str);
	if (*num > 2147483647 || *num < -2147483648)
		return (0);
	if (check_dup(lst, *num))
		return (0);
	ft_lstadd_back(lst, ft_nodenew(num));
	return (1);
}

void	free_stacks(t_list **lst)
{
	t_list	*next;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->content);
		free((*lst)->index);
		free(*lst);
		*lst = next;
	}
}
