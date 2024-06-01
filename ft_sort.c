/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:02:21 by saderdou          #+#    #+#             */
/*   Updated: 2024/04/24 21:02:30 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb_rb(t_list **a, t_list **b, t_list **tmp, int *size)
{
	if ((*tmp)->curr_pos <= *size / 2)
	{
		while (*a != *tmp)
			ra(a);
		pb(b, a);
		rb(b);
		*tmp = *a;
	}
	else
	{
		while (*a != *tmp)
			rra(a);
		pb(b, a);
		rb(b);
		*tmp = *a;
	}
	ft_get_current_pasition(a);
}

void	ft_pb(t_list **a, t_list **b, t_list **tmp, int *size)
{
	if ((*tmp)->curr_pos <= *size / 2)
	{
		while (*a != *tmp)
			ra(a);
		pb(b, a);
		*tmp = *a;
	}
	else
	{
		while (*a != *tmp)
			rra(a);
		pb(b, a);
		*tmp = *a;
	}
	ft_get_current_pasition(a);
}

void	ft_reset(int *min, int *max, int *size)
{
	(*min)++;
	(*max)++;
	(*size)--;
}

void	sort_else(t_list **a, t_list **b, int size)
{
	int		min;
	int		max;
	t_list	*tmp;

	min = 0;
	max = ft_sqrt(size) + (size / 500) + 5;
	ft_get_current_pasition(a);
	tmp = *a;
	while (tmp)
	{
		if (tmp->rank < min)
		{
			ft_pb_rb(a, b, &tmp, &size);
			ft_reset(&min, &max, &size);
			continue ;
		}
		if (tmp->rank >= min && tmp->rank <= max)
		{
			ft_pb(a, b, &tmp, &size);
			ft_reset(&min, &max, &size);
			continue ;
		}
		tmp = tmp->next;
	}
}

void	ft_sort(t_list **head_stack_a, long *sort_tab, int size)
{
	int		count;
	t_list	*b;

	count = size;
	b = NULL;
	if (size == 2)
		sa(head_stack_a);
	else if (size == 3)
		sort_3(head_stack_a);
	else if (size == 5)
		sort_5(head_stack_a, sort_tab, size);
	else
	{
		sort_else(head_stack_a, &b, size);
		push_to_a_from_b(&b, head_stack_a, count);
	}
}
