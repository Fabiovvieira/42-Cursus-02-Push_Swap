/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:18:36 by fvalli-v          #+#    #+#             */
/*   Updated: 2023/01/19 18:45:31 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

void	ft_lstprint(t_list **lst);
void	ft_sa(t_list **lst);
void	ft_sb(t_list **lst);
void	ft_ss(t_list **last_a, t_list **last_b);
t_list	*ft_ra(t_list *lst);
t_list	*ft_rb(t_list *lst);
void	ft_rr(t_list **last_a, t_list **last_b);
t_list	*ft_rra(t_list *lst);
t_list	*ft_rrb(t_list *lst);
void	ft_rrr(t_list **last_a, t_list **last_b);
void	ft_pb(t_list **last_a, t_list **last_b);
void	ft_pa(t_list **last_b, t_list **last_a);
void	insert_node(t_list **lst, char *str);

#endif
