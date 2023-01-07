/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:34:53 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/07 23:17:03 by fvalli-v         ###   ########.fr       */
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
	tmp = (*lst)->next;
	while (tmp != (*lst)){
		ft_printf("%s ",tmp->content);
		tmp = tmp->next;
	}
	ft_printf("%s ",tmp->content);
}

void	ft_sa(t_list *lst)
{
	t_list	*sec;
	t_list	*fir;
	t_list	*aux;

	fir = lst->next;
	sec = fir->next;
	lst->next = sec;
	fir->next = sec->next;
	sec->next = fir;
}

int	main(int argc, char **argv)
{
	int	i;
	t_list	*last_a;
	// t_list	*last_b;
	t_list	*stack_a;
	// t_list	*stack_b;

	i = 1;
	stack_a = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			ft_lstadd_back(&stack_a, ft_lstnew(argv[i]));
			i++;
		}
		last_a = ft_lstlast(stack_a);
		last_a->next = stack_a;
	}
	ft_lstprint(&last_a);
	ft_sa(last_a);
	ft_printf("\n");
	ft_lstprint(&last_a);
	ft_sa(last_a);
	ft_printf("\n");
	ft_lstprint(&last_a);
	return (1);
}
