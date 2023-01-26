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
	while (size > 3)
	{
		while (size > (length - multpart) - length % partition)
		{
			index = get_index_partition(lst_a, multpart);
			if (index <= size / 2)
			{
				while (index > 0)
				{
					*lst_a = ft_ra(*lst_a);
					ft_printf("ra\n");
					index--;
				}
				ft_pb(lst_a, lst_b);
				ft_printf("pb\n");
			}
			else {
				while (index < size)
				{
					*lst_a = ft_rra(*lst_a);
					ft_printf("rra\n");
					index++;
				}
				ft_pb(lst_a, lst_b);
				ft_printf("pb\n");
			}
			size--;
		}
		multpart += part;
	}
}

// ft_sorting2(&stack_a, &stack_b, 4);
// ft_sort_lastpart(&stack_a, &stack_b, &min_index);
// ft_sort_lastpart(&stack_b, &stack_a, &max_index);
// last_move(&stack_a, &stack_b);
