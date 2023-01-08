/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:34:53 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/08 11:21:20 by fvalli-v         ###   ########.fr       */
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

	fir = lst->next;
	sec = lst->next->next;
	lst->next = sec;
	fir->next = sec->next;
	sec->next = fir;
}

void	ft_sb(t_list *lst)
{
	ft_sa(lst);
}

t_list	*ft_ra(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	return (lst->next);
}

t_list	*ft_rb(t_list *lst)
{
	return (ft_ra(lst));
}

t_list	*ft_rra(t_list *lst)
{
	t_list	*tmp;
	if (lst == NULL)
		return (NULL);
	tmp = lst->next;
	while (tmp->next != lst){
		tmp = tmp->next;
	}
	return (tmp);
}

t_list	*ft_rrb(t_list *lst)
{
	return (ft_rra(lst));
}

void	ft_pb(t_list **last_a, t_list **last_b)
{
	t_list	*aux;

	aux = NULL;
	if (*last_a == NULL)
		return ;
	if (*last_b == NULL)
	{
		*last_b = (*last_a)->next;
		(*last_a)->next = (*last_a)->next->next;
		(*last_b)->next = *last_b;
	}
	else {
		aux = (*last_b)->next;
		(*last_b)->next = (*last_a)->next;
		(*last_a)->next = (*last_a)->next->next;
		(*last_b)->next->next = aux;
	}
}

void	ft_pa(t_list **last_b, t_list **last_a)
{
	ft_pb(last_b, last_a);
}

void	apply_func(t_list **last_a, t_list **last_b, char *str)
{
	if (!ft_strncmp(str, "sa", 3))
		ft_sa(*last_a);
	else if (!ft_strncmp(str, "sb", 3))
		ft_sb(*last_b);
	else if (!ft_strncmp(str, "ra", 3))
		*last_a = ft_ra(*last_a);
	else if (!ft_strncmp(str, "rb", 3))
		*last_b = ft_rb(*last_b);
	else if (!ft_strncmp(str, "rra", 3))
		*last_a = ft_rra(*last_a);
	else if (!ft_strncmp(str, "rrb", 3))
		*last_b = ft_rrb(*last_b);
	else if (!ft_strncmp(str, "pa", 3))
		ft_pa(last_b, last_a);
	else if (!ft_strncmp(str, "pb", 3))
		ft_pb(last_a, last_b);
	else
		ft_printf("There is no such commmand. Try Again\n");
}

int	main(int argc, char **argv)
{
	int	i;
	t_list	*last_a;
	t_list	*last_b;
	t_list	*stack_a;
	char	str[10];
	// t_list	*stack_b;

	i = 1;
	stack_a = NULL;
	last_a = NULL;
	last_b = NULL;
	// stack_b = NULL;
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
	ft_printf("Stack A: ");
	ft_lstprint(&last_a);
	ft_printf("\nStack B: ");
	ft_lstprint(&last_b);

	while (1)
	{
		scanf("%s", str);
		apply_func(&last_a, &last_b, str);
		ft_printf("Stack A: ");
		ft_lstprint(&last_a);
		ft_printf("\nStack B: ");
		ft_lstprint(&last_b);
		ft_printf("\n");
	}

	//There is error on pa and pb when pushing the last node. Correct this later.


	// ft_sa(last_a);
	// ft_printf("\n");
	// ft_printf("sa: \n");
	// ft_printf("Stack A: ");
	// ft_lstprint(&last_a);
	// ft_printf("\nStack B: ");
	// ft_lstprint(&last_b);

	// ft_sa(last_a);
	// ft_printf("\n");
	// ft_printf("sa: \n");
	// ft_printf("Stack A: ");
	// ft_lstprint(&last_a);
	// ft_printf("\nStack B: ");
	// ft_lstprint(&last_b);

	// last_a = ft_ra(last_a);
	// ft_printf("\n");
	// ft_printf("ra: \n");
	// ft_printf("Stack A: ");
	// ft_lstprint(&last_a);
	// ft_printf("\nStack B: ");
	// ft_lstprint(&last_b);

	// last_a = ft_ra(last_a);
	// ft_printf("\n");
	// ft_printf("ra: \n");
	// ft_printf("Stack A: ");
	// ft_lstprint(&last_a);
	// ft_printf("\nStack B: ");
	// ft_lstprint(&last_b);

	// last_a = ft_rra(last_a);
	// ft_printf("\n");
	// ft_printf("rra: \n");
	// ft_printf("Stack A: ");
	// ft_lstprint(&last_a);
	// ft_printf("\nStack B: ");
	// ft_lstprint(&last_b);

	// last_a = ft_rra(last_a);
	// ft_printf("\n");
	// ft_printf("rra: \n");
	// ft_printf("Stack A: ");
	// ft_lstprint(&last_a);
	// ft_printf("\nStack B: ");
	// ft_lstprint(&last_b);


	// ft_pb(&last_a, &last_b);
	// ft_printf("\n");
	// ft_printf("pb: \n");
	// ft_printf("Stack A: ");
	// ft_lstprint(&last_a);
	// ft_printf("\nStack B: ");
	// ft_lstprint(&last_b);

	// ft_pb(&last_a, &last_b);
	// ft_printf("\n");
	// ft_printf("pb: \n");
	// ft_printf("Stack A: ");
	// ft_lstprint(&last_a);
	// ft_printf("\nStack B: ");
	// ft_lstprint(&last_b);
	return (1);
}
