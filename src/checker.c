/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:10:16 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/22 11:41:22 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sb(t_list **lst)
{
	ft_sa(lst);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

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

void	ft_rr(t_list **last_a, t_list **last_b)
{
	*last_a = ft_ra(*last_a);
	*last_b = ft_rb(*last_b);
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
			break;
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

void	ft_rrr(t_list **last_a, t_list **last_b)
{
	*last_a = ft_rra(*last_a);
	*last_b = ft_rrb(*last_b);
}

void	ft_pb(t_list **last_a, t_list **last_b)
{
	t_list	*aux;

	aux = *last_a;;
	if (*last_a == NULL)
		return ;
	if (*last_b == NULL)
	{
		*last_a = (*last_a)->next;
		*last_b = aux;
		(*last_b)->next = NULL;
	}
	else {
		*last_a = (*last_a)->next;
		ft_lstadd_front(last_b, aux);
	}
}

void	ft_pa(t_list **last_b, t_list **last_a)
{
	ft_pb(last_b, last_a);
}

void	apply_func(t_list **last_a, t_list **last_b, char *str)
{
	if (!ft_strcmp(str, "sa"))
		ft_sa(last_a);
	else if (!ft_strcmp(str, "sb"))
		ft_sb(last_b);
	else if (!ft_strcmp(str, "ss"))
		ft_ss(last_a, last_b);
	else if (!ft_strcmp(str, "ra"))
		*last_a = ft_ra(*last_a);
	else if (!ft_strcmp(str, "rb"))
		*last_b = ft_rb(*last_b);
	else if (!ft_strcmp(str, "rr"))
		ft_rr(last_a, last_b);
	else if (!ft_strcmp(str, "rra"))
		*last_a = ft_rra(*last_a);
	else if (!ft_strcmp(str, "rrb"))
		*last_b = ft_rrb(*last_b);
	else if (!ft_strcmp(str, "rrr"))
		ft_rrr(last_a, last_b);
	else if (!ft_strcmp(str, "pa"))
		ft_pa(last_b, last_a);
	else if (!ft_strcmp(str, "pb"))
		ft_pb(last_a, last_b);
	else
		ft_printf("There is no such commmand. Try Again\n");
}

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		i;

	(void)argc;
	(void)argv;
	fd = 0;
	i = 0;
	while ((str = get_next_line(fd)))
	{
		ft_printf("fd - %3d || LINE - %3d || lengh - %3d: %s",fd, i++, (int)ft_strlen(str), str);
	}
}
