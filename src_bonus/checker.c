/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:10:16 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/02/08 19:08:04 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_func(t_list **last_a, t_list **last_b, char **str)
{
	if (!ft_strcmp(*str, "sa\n"))
		ft_sa(last_a);
	else if (!ft_strcmp(*str, "sb\n"))
		ft_sb(last_b);
	else if (!ft_strcmp(*str, "ss\n"))
		ft_ss(last_a, last_b);
	else if (!ft_strcmp(*str, "ra\n"))
		*last_a = ft_ra(*last_a);
	else if (!ft_strcmp(*str, "rb\n"))
		*last_b = ft_rb(*last_b);
	else if (!ft_strcmp(*str, "rr\n"))
		ft_rr(last_a, last_b);
	else if (!ft_strcmp(*str, "rra\n"))
		*last_a = ft_rra(*last_a);
	else if (!ft_strcmp(*str, "rrb\n"))
		*last_b = ft_rrb(*last_b);
	else if (!ft_strcmp(*str, "rrr\n"))
		ft_rrr(last_a, last_b);
	else if (!ft_strcmp(*str, "pa\n"))
		ft_pa(last_b, last_a);
	else if (!ft_strcmp(*str, "pb\n"))
		ft_pb(last_a, last_b);
	else
		ft_error(last_a, last_b, str);
}

void	checker_sort_stacks(t_list **last_a, t_list **last_b)
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
			break ;
		}
		if (*(int *)tmp->content > *(int *)tmp->next->content)
		{
			ft_printf("KO\n");
			break ;
		}
		tmp = tmp->next;
	}
}

void	read_commands(t_list **stack_a, t_list **stack_b, int fd, char **str)
{
	while (1)
	{
		*str = get_next_line(fd);
		if (*str == NULL)
			break ;
		apply_func(stack_a, stack_b, str);
		free(*str);
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;
	char	**list;
	t_list	*stack_a;
	t_list	*stack_b;

	fd = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (argc == 2)
			insert_with_split(&stack_a, &list, argv);
		else if (argc > 2)
			insert_with_multiarg(&stack_a, argc, argv);
		read_commands(&stack_a, &stack_b, fd, &str);
		checker_sort_stacks(&stack_a, &stack_b);
		ft_free(&stack_a, &stack_b, str);
	}
	return (1);
}
