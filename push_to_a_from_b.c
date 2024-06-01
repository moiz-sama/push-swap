/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a_from_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:52:49 by saderdou          #+#    #+#             */
/*   Updated: 2024/04/26 20:52:52 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb_pa(t_list **a, t_list **b, t_list **tmp)
{
	while (*b != *tmp)
		rb(b);
	pa(a, b);
	*tmp = *b;
}

void	ft_rrb_pa(t_list **a, t_list **b, t_list **tmp)
{
	while (*b != *tmp)
		rrb(b);
	pa(a, b);
	*tmp = *b;
}

void	push_to_a_from_b(t_list **b, t_list **a, int size)
{
	t_list	*tmp;

	tmp = *b;
	ft_get_current_pasition(b);
	while (tmp)
	{
		if (tmp->rank == size - 1)
		{
			if (tmp->curr_pos <= size / 2)
			{
				ft_rb_pa(a, b, &tmp);
				size--;
				ft_get_current_pasition(b);
				continue ;
			}
			else
			{
				ft_rrb_pa(a, b, &tmp);
				size--;
				ft_get_current_pasition(b);
				continue ;
			}
		}
		tmp = tmp->next;
	}
}
