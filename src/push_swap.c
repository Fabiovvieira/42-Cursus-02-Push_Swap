/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:34:53 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/20 17:07:53 by fvalli-v         ###   ########.fr       */
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
		ft_printf("%d - %d | ", *(int *)(tmp->content), *(tmp->index));
		tmp = tmp->next;
	}
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

int	ft_lstlastsize(t_list **lst)
{
	t_list	*tmp;
	int 	i;

	i = 0;
	if(*lst == NULL) {
		return (i);
	}
	tmp = (*lst)->next;
	while (tmp != (*lst)){
		tmp = tmp->next;
		i++;
	}
	return (i + 1);
}

int	min_index(t_list **lst)
{
	int		i;
	int		indexmin;
	int		contentmin;
	t_list	*tmp;

	i = 0;
	indexmin = 0;
	tmp = *lst;
	contentmin = *(int *)(tmp->content);
	while (i < ft_lstsize(*lst)){
		if (*(int *)(tmp->content) <= contentmin)
		{
			indexmin = i;
			contentmin = *(int *)(tmp->content);
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
	int		contentmax;
	t_list	*tmp;

	i = 0;
	indexmax = 0;
	tmp = *lst;
	contentmax = *(int *)(tmp->content);
	while (i < ft_lstsize(*lst)){
		if (*(int *)(tmp->content) >= contentmax)
		{
			indexmax = i;
			contentmax = *(int *)(tmp->content);
		}
		tmp = tmp->next;
		i++;
	}
	return (indexmax);
}

int	get_index_partition(t_list **lst, int partition)
{
	int		i;
	int		indexmin;
	t_list	*tmp;
	int		size;
	int 	flag;

	i = 0;
	size = ft_lstsize(*lst);
	indexmin = size - 1;
	flag = 0;
	tmp = *lst;
	while (i < ft_lstsize(*lst)){
		if (*(tmp->index) < partition)
		{
			if (flag == 0)
			{
				indexmin = i;
				flag = 1;
			}
			else
			{
				if (i <= size / 2)
				{
					if (i <= indexmin)
						indexmin = i;
				}
				else
				{
					if (indexmin <= size / 2)
					{
						if ((size - 1 - i) <= indexmin)
							indexmin = i;
					}
					else
					{
						if (i >= indexmin)
							indexmin = i;
					}
				}
			}
		}
		tmp = tmp->next;
		i++;
	}
	// ft_printf("get_index |index = %d | multpart = %d\n", indexmin, partition);
	return (indexmin);
}

void	ft_sort_lastpart(t_list **last_a, t_list **last_b, int (*func)(t_list **))
{
	// int	i;
	int	minindex;
	int	size;

	// i = 0;
	size = ft_lstsize(*last_a);
	while (size > 2)
	{
		minindex = (*func)(last_a);
		if (minindex <= size / 2){
			while (minindex){
				*last_a = ft_ra(*last_a);
				ft_printf("ra\n");
				// ft_printf("Stack A: ");
				// ft_lstprint(last_a);
				// ft_printf("\nStack B: ");
				// ft_lstprint(last_b);
				// ft_printf("\n");
				minindex--;
			}
			ft_pb(last_a, last_b);
			ft_printf("pb\n");
			// ft_printf("Stack A: ");
			// ft_lstprint(last_a);
			// ft_printf("\nStack B: ");
			// ft_lstprint(last_b);
			// ft_printf("\n");
		}
		else {
			while (minindex < size){
				*last_a = ft_rra(*last_a);
				ft_printf("rra\n");
				// ft_printf("Stack A: ");
				// ft_lstprint(last_a);
				// ft_printf("\nStack B: ");
				// ft_lstprint(last_b);
				// ft_printf("\n");
				minindex++;
			}
			ft_pb(last_a, last_b);
			ft_printf("pb\n");
			// ft_printf("Stack A: ");
			// ft_lstprint(last_a);
			// ft_printf("\nStack B: ");
			// ft_lstprint(last_b);
			// ft_printf("\n");
		}
		size = ft_lstsize(*last_a);
	}
	if (*(int *)((*last_a)->content) > *(int *)((*last_a)->next->content)){
		ft_sa(last_a);
		ft_printf("sa\n");
		// ft_printf("Stack A: ");
		// ft_lstprint(last_a);
		// ft_printf("\nStack B: ");
		// ft_lstprint(last_b);
		// ft_printf("\n");
	}
}

void	ft_sorting2(t_list **lst_a, t_list **lst_b, int partition)
{
	int	size;
	int	length;
	int	index;
	int	part;
	int	multpart;

	size = ft_lstsize(*lst_a);
	part = size / partition;
	multpart = part;
	length = size;
	while (size > length / partition)
	{
		while (size > (length - multpart))
		{
			index = get_index_partition(lst_a, multpart);
			// ft_printf("index = %d | multpart = %d\n", index, multpart);
			if (index <= size / 2){
				while (index){
					*lst_a = ft_ra(*lst_a);
					ft_printf("ra\n");
					// ft_printf("Stack A: ");
					// ft_lstprint(lst_a);
					// ft_printf("\nStack B: ");
					// ft_lstprint(lst_b);
					// ft_printf("\n");
					index--;
				}
				ft_pb(lst_a, lst_b);
				ft_printf("pb\n");
				// ft_printf("Stack A: ");
				// ft_lstprint(lst_a);
				// ft_printf("\nStack B: ");
				// ft_lstprint(lst_b);
				// ft_printf("\n");
			}
			else {
				while (index < size){
					*lst_a = ft_rra(*lst_a);
					ft_printf("rra\n");
					// ft_printf("Stack A: ");
					// ft_lstprint(lst_a);
					// ft_printf("\nStack B: ");
					// ft_lstprint(lst_b);
					// ft_printf("\n");
					index++;
				}
				ft_pb(lst_a, lst_b);
				ft_printf("pb\n");
				// ft_printf("Stack A: ");
				// ft_lstprint(lst_a);
				// ft_printf("\nStack B: ");
				// ft_lstprint(lst_b);
				// ft_printf("\n");
			}
			size--;
		}
		multpart += part;
	}
}



void	ft_sorting(t_list **last_a, t_list **last_b)
{
	// int	i;
	int	minindex;
	int	size;
	int	count;

	// i = 0;
	count = 0;
	size = ft_lstlastsize(last_a);
	while (size > 2)
	{
		minindex = min_index(last_a);
		if (minindex <= size / 2){
			while (minindex){
				*last_a = ft_ra(*last_a);
				ft_printf("ra\n");
				ft_printf("Stack A: ");
				ft_lstprint(last_a);
				ft_printf("\nStack B: ");
				ft_lstprint(last_b);
				ft_printf("\n");
				minindex--;
				count++;
			}
			ft_pb(last_a, last_b);
			count++;
			ft_printf("pb\n");
			ft_printf("Stack A: ");
			ft_lstprint(last_a);
			ft_printf("\nStack B: ");
			ft_lstprint(last_b);
			ft_printf("\n");
		}
		else {
			while (minindex < size){
				*last_a = ft_rra(*last_a);
				ft_printf("rra\n");
				ft_printf("Stack A: ");
				ft_lstprint(last_a);
				ft_printf("\nStack B: ");
				ft_lstprint(last_b);
				ft_printf("\n");
				minindex++;
				count++;
			}
			ft_pb(last_a, last_b);
			ft_printf("pb\n");
			ft_printf("Stack A: ");
			ft_lstprint(last_a);
			ft_printf("\nStack B: ");
			ft_lstprint(last_b);
			ft_printf("\n");
			count++;
		}
		size = ft_lstlastsize(last_a);
	}
	if (ft_atoi((*last_a)->content) < ft_atoi((*last_a)->next->content)){
		ft_sa(last_a);
		count++;
		ft_printf("sa\n");
		ft_printf("Stack A: ");
		ft_lstprint(last_a);
		ft_printf("\nStack B: ");
		ft_lstprint(last_b);
		ft_printf("\n");
	}
	size = ft_lstlastsize(last_b);
	while (size)
	{
		ft_pa(last_b, last_a);
		count++;
		ft_printf("pa\n");
		ft_printf("Stack A: ");
		ft_lstprint(last_a);
		ft_printf("\nStack B: ");
		ft_lstprint(last_b);
		ft_printf("\n");
		size--;
	}
	ft_printf("Number of operations is: %d\n", count);
}

void	insert_node(t_list **lst, char *str)
{
	int	*num;

	num = malloc(sizeof(int));
	*num = ft_atoi(str);
	ft_lstadd_back(lst, ft_lstnew(num));
	ft_lstlast(*lst)->index = NULL;
}

void	insert_index(t_list **lst, int index)
{
	int	*num;

	num = malloc(sizeof(int));
	*num = index;
	(*lst)->index = num;
}

void	min_num(t_list **lst)
{
	int		j;
	int		indexmin;
	int		contentmin;
	int		size;
	t_list	*tmp;
	t_list	*aux;

	j = 0;
	indexmin = 0;
	tmp = *lst;
	size = ft_lstsize(*lst);
	contentmin = *(int *)(tmp->content);
	while (j < size) {
		while (tmp->index)
		{
			tmp = tmp->next;
			contentmin = *(int *)(tmp->content);
		}
		while (tmp){
			if (*(int *)(tmp->content) <= contentmin && !tmp->index)
			{
				aux = tmp;
				contentmin = *(int *)(tmp->content);
			}
			tmp = tmp->next;
		}
		insert_index(&aux, indexmin);
		tmp = *lst;
		contentmin = *(int *)(tmp->content);
		indexmin++;
		j++;
	}
}



int	main(int argc, char **argv)
{
	int	i;
	// t_list	*last_a;
	// t_list	*last_b;
	t_list	*stack_a;
	// char	str[10];
	t_list	*stack_b;

	i = 1;
	stack_a = NULL;
	// last_a = NULL;
	// last_b = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			// ft_lstadd_back(&stack_a, ft_lstnew(argv[i]));
			insert_node(&stack_a, argv[i]);
			i++;
		}
		// last_a = ft_lstlast(stack_a);
		// last_a->next = stack_a;
	}
	min_num(&stack_a);
	ft_printf("Stack A: ");
	ft_lstprint(&stack_a);
	ft_printf("\nStack B: ");
	ft_lstprint(&stack_b);
	// ft_printf("size of stack A is : %d\n", ft_lstlastsize(&last_a));
	// ft_printf("index of min value of stack A is : %d\n", min_index(&last_a));


	// ft_sorting(&last_a, &last_b);

	ft_sorting2(&stack_a, &stack_b, 12);
	ft_sort_lastpart(&stack_a, &stack_b, &min_index);
	ft_sort_lastpart(&stack_b, &stack_a, &max_index);

	ft_printf("Stack A: ");
	ft_lstprint(&stack_a);
	ft_printf("\nStack B: ");
	ft_lstprint(&stack_b);

	// ft_printf("Stack A: ");
	// ft_lstprint(&last_a);
	// ft_printf("\nStack B: ");
	// ft_lstprint(&last_b);

	// while (1)
	// {
	// 	scanf("%s", str);
	// 	apply_func(&stack_a, &stack_b, str);
	// 	ft_printf("Stack A: ");
	// 	ft_lstprint(&stack_a);
	// 	ft_printf("\nStack B: ");
	// 	ft_lstprint(&stack_b);
	// 	ft_printf("\n");
	// }
	return (1);
}
