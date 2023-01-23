/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:10:16 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/23 16:54:09 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint(t_list **lst)
{
	t_list	*tmp;

	if(*lst == NULL) {
		ft_printf("Empty list\n");
		return ;
	}
	tmp = (*lst);
	while (tmp){
		// ft_printf("%d - %d | ", *(long *)(tmp->content), *(tmp->index));
		ft_printf("%d ", *(long *)(tmp->content));
		tmp = tmp->next;
	}
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
	if (!ft_strcmp(str, "sa\n"))
		ft_sa(last_a);
	else if (!ft_strcmp(str, "sb\n"))
		ft_sb(last_b);
	else if (!ft_strcmp(str, "ss\n"))
		ft_ss(last_a, last_b);
	else if (!ft_strcmp(str, "ra\n"))
		*last_a = ft_ra(*last_a);
	else if (!ft_strcmp(str, "rb\n"))
		*last_b = ft_rb(*last_b);
	else if (!ft_strcmp(str, "rr\n"))
		ft_rr(last_a, last_b);
	else if (!ft_strcmp(str, "rra\n"))
		*last_a = ft_rra(*last_a);
	else if (!ft_strcmp(str, "rrb\n"))
		*last_b = ft_rrb(*last_b);
	else if (!ft_strcmp(str, "rrr\n"))
		ft_rrr(last_a, last_b);
	else if (!ft_strcmp(str, "pa\n"))
		ft_pa(last_b, last_a);
	else if (!ft_strcmp(str, "pb\n"))
		ft_pb(last_a, last_b);
	else
		ft_printf("There is no such commmand. Try Again\n");
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
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
	ft_lstadd_back(lst, ft_lstnew(num));
	ft_lstlast(*lst)->index = NULL;
	return (1);
}

void	check_sort(t_list **last_a, t_list **last_b)
{
	t_list	*tmp;

	tmp = *last_a;
	if (*last_b != NULL)
	{
		ft_printf("KO\n");
		return ;
	}
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			ft_printf("OK\n");
			break;
		}
		if (*(int *)tmp->content > *(int *)tmp->next->content)
		{
			ft_printf("KO\n");
		}
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		i;
	char	**list;
	t_list	*stack_a;
	t_list	*stack_b;

	(void)argc;
	(void)argv;
	fd = 0;
	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (argc == 2)
		{
			list = ft_split(argv[1], ' ');
			while (list[i])
			{
				// ft_lstadd_back(&stack_a, ft_lstnew(argv[i]));
				// ft_printf("%s\n",list[i]);
				if (!insert_node(&stack_a, list[i]))
				{
					ft_printf("Error\n");
					return (1);
				}
				i++;
			}
		}
		else if (argc > 2)
		{
			i = 1;
			while (i <= argc - 1)
			{
				// ft_lstadd_back(&stack_a, ft_lstnew(argv[i]));
				// ft_printf("%s\n",list[i]);
				if (!insert_node(&stack_a, argv[i]))
				{
					ft_printf("Error\n");
					return (1);
				}
				i++;
			}
		}
		while ((str = get_next_line(fd)))
		{
			// ft_printf("%s", str);
			apply_func(&stack_a, &stack_b, str);
		}
		check_sort(&stack_a, &stack_b);
	}
	return (1);
}
