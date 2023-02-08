/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:34:53 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/02/08 15:14:38 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_sort_lastpart(stack_b, stack_a, &max_index);
		last_move(stack_a, stack_b);
	}
	else if (size >= 300 && size < 1000)
	{
		sort_300_plus(stack_a, stack_b);
	}
	else
	{
		sort_300_plus(stack_a, stack_b);
	}
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
	}
	return (1);
}
