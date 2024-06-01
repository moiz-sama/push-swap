/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:42:51 by saderdou          #+#    #+#             */
/*   Updated: 2024/04/16 10:42:58 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_a(long *tab, long *sort_tab, int size)
{
	int		idx;
	int		j;
	t_list	*node;
	t_list	*head_ptr;

	head_ptr = NULL;
	idx = -1;
	while (++idx < size)
	{
		j = -1;
		node = ft_lstnew(tab[idx]);
		while (++j < size)
		{
			if (tab[idx] == sort_tab[j])
			{
				node->rank = j;
				break ;
			}
		}
		ft_lstadd_back(&head_ptr, node);
	}
	ft_sort(&head_ptr, sort_tab, size);
	free_stack(&head_ptr);
}

int	main(int ac, char **av)
{
	long	*tab;
	long	*sort_tab;
	int		count;

	count = 0;
	if (ac >= 2)
	{
		ft_check_args(av);
		tab = ft_strjoin_and_split(ac, av, &count);
		ft_check_double(tab, count);
		is_sorted(tab, count);
		sort_tab = ft_sort_tab(tab, count);
		push_all_to_a(tab, sort_tab, count);
		free(sort_tab);
		free(tab);
	}
}
