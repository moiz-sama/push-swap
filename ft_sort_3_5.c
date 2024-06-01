/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:53:33 by saderdou          #+#    #+#             */
/*   Updated: 2024/04/26 20:53:36 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb < 0)
		return (0);
	sqrt = 1;
	while (sqrt * sqrt < nb)
		++sqrt;
	if (sqrt * sqrt == nb)
		return (sqrt);
	if (sqrt * sqrt > nb)
		return (sqrt - 1);
	return (0);
}

void	ft_get_current_pasition(t_list **a)
{
	t_list	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		tmp->curr_pos = i;
		i++;
		tmp = tmp->next;
	}
}

void	sort_3(t_list **head_stack)
{
	if ((*head_stack)->content > (*head_stack)->next->content
		&& (*head_stack)->next->content > (*head_stack)->next->next->content)
	{
		ra(head_stack);
		sa(head_stack);
	}
	else if ((*head_stack)->content < (*head_stack)->next->content
		&& (*head_stack)->next->content > (*head_stack)->next->next->content)
	{
		if ((*head_stack)->content > (*head_stack)->next->next->content)
			rra(head_stack);
		else
		{
			rra(head_stack);
			sa(head_stack);
		}
	}
	else if ((*head_stack)->content > (*head_stack)->next->content
		&& (*head_stack)->next->content < (*head_stack)->next->next->content)
	{
		if ((*head_stack)->content > (*head_stack)->next->next->content)
			ra(head_stack);
		else
			sa(head_stack);
	}
}

void	sort_5(t_list **a, long *tab, int size)
{
	t_list	*b;
	int		i;

	i = 0;
	b = NULL;
	while (size > 3)
	{
		if ((*a)->content == tab[i])
		{
			pb(&b, a);
			i++;
			size--;
		}
		else
		{
			if ((*a)->next->content >= tab[i] && (*a)->next->content <= tab[i])
				ra(a);
			else
				rra(a);
		}
	}
	sort_3(a);
	while (b)
		pa(a, &b);
}
