/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:36:24 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/02/08 19:01:12 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_with_split(t_list **stack_a, char ***list, char **argv)
{
	int	i;

	i = 0;
	*list = ft_split(argv[1], ' ');
	while ((*list)[i])
	{
		if (!insert_node(stack_a, (*list)[i]))
		{
			write(2, "Error\n", 6);
			free_split(*list);
			free_stacks(stack_a);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	if (i == 0)
	{
		write(2, "Error\n", 6);
		free_split(*list);
		free_stacks(stack_a);
		exit (EXIT_FAILURE);
	}
	free_split(*list);
	return (i);
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
			free_stacks(stack_a);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	size = i - 1;
	return (size);
}

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

void	ft_free(t_list **stack_a, t_list **stack_b, char *str)
{
	free_stacks(stack_a);
	free_stacks(stack_b);
	free(str);
}

void	ft_error(t_list **last_a, t_list **last_b, char **str)
{
	write(2, "Error\n", 6);
	ft_free(last_a, last_b, *str);
	exit (EXIT_FAILURE);
}
