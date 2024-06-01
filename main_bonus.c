/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:04:49 by saderdou          #+#    #+#             */
/*   Updated: 2024/04/27 14:04:52 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_sort_by_rules(char *line, t_list **a, t_list **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(b, a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	is_list_sorted(t_list **head)
{
	t_list	*current;

	if (*head == NULL || (*head)->next == NULL)
		return (1);
	current = *head;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	print_ok_or_ko(t_list **a, t_list **b, int size)
{
	if (is_list_sorted(a) == 1 && ft_lstsize(*a) == size && *b == NULL)
	{
		write(1, "OK\n", 3);
	}
	else
		write(1, "KO\n", 3);
}

int	push_all_to_a(long *tab, int size)
{
	int		idx;
	t_list	*b;
	t_list	*node;
	t_list	*a;
	char	*line;

	a = NULL;
	b = NULL;
	idx = -1;
	while (++idx < size)
	{
		node = ft_lstnew(tab[idx]);
		ft_lstadd_back(&a, node);
	}
	line = get_next_line(0, 0);
	while (line)
	{
		if (ft_sort_by_rules(line, &a, &b) == 0)
			return (free(tab), free_stack(&a), free_stack(&b),
				get_next_line(0, 1), free(line), 0);
		free(line);
		line = get_next_line(0, 0);
	}
	print_ok_or_ko(&a, &b, size);
	return (free(tab), free_stack(&a), free_stack(&b), free(line), 0);
}

int	main(int ac, char **av)
{
	long	*tab;
	int		count;

	count = 0;
	if (ac >= 2)
	{
		ft_check_args(av);
		tab = ft_strjoin_and_split(ac, av, &count);
		ft_check_double(tab, count);
		push_all_to_a(tab, count);
	}
}
