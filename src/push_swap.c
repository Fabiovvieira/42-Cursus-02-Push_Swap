/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:34:53 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/02/07 17:57:26 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **list)
{
	int		i;

	i = 0;
	if (list == NULL)
		return ;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void ft_printlst(t_list **stack)
{
	t_list *tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_printf("%d ", *(tmp->index));
		tmp = tmp->next;
	}
}

void	select_sort(t_list **stack_a, t_list **stack_b, int size)
{
	sort_indexation(stack_a);
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size > 3 && size < 100)
		ft_sort_less_100(stack_a, stack_b);
	else if (size >= 100 && size < 300)
	{
		ft_sort_plus_100(stack_a, stack_b, 5);
		// ft_printlst(stack_b);
		// ft_sort_plus_100_1(stack_a, stack_b, 10);
		// ft_sort_lastpart(stack_b, stack_a, &max_index);
		// last_move(stack_a, stack_b);
	}
	else if (size >= 300 && size < 1000)
	{
		ft_sort_plus_100(stack_a, stack_b, 8);
		ft_printlst(stack_b);
		// ft_sort_lastpart(stack_b, stack_a, &max_index);
		// last_move(stack_a, stack_b);
	}
	else
	{
		ft_sort_plus_100(stack_a, stack_b, 10);
		ft_sort_lastpart(stack_b, stack_a, &max_index);
		last_move(stack_a, stack_b);
	}
}

int	insert_with_split(t_list **stack_a, char ***list, char **argv)
{
	int	i;
	int	size;

	i = 0;
	*list = ft_split(argv[1], ' ');
	while ((*list)[i])
	{
		if (!insert_node(stack_a, (*list)[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	size = i;
	return (size);
}

int	insert_with_multiarg(t_list **stack_a, int argc, char **argv)
{
	int	i;
	int	size;

	i = 1;
	while (i <= argc - 1)
	{
		if (!insert_node(stack_a, argv[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	size = i - 1;
	return (size);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**list;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	list = NULL;
	size = 0;
	if (argc >= 2)
	{
		if (argc == 2)
		{
			size = insert_with_split(&stack_a, &list, argv);
		}
		else if (argc > 2)
		{
			size = insert_with_multiarg(&stack_a, argc, argv);
		}
		if (size > 1 && check_sort(stack_a) == 0)
			select_sort(&stack_a, &stack_b, size);
		free_stacks(&stack_a);
		free_split(list);
	}
	return (1);
}
