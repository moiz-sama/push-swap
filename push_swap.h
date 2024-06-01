/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:43:40 by saderdou          #+#    #+#             */
/*   Updated: 2024/04/16 10:43:43 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				rank;
	int				curr_pos;
	struct s_list	*next;
}	t_list;

/*******parsin********/
void	ft_check_args(char **args);
long	*ft_strjoin_and_split(int ac, char **av, int *count);
char	**ft_split(char const *s, char c, int *count);
void	ft_free(char **str, int i);
long	ft_atoi(const char *str);
int		ft_valid_args(char *args);
int		ft_isdigit(int c);
void	error(void);
void	ft_check_double(long *tab, int count);
long	*ft_sort_tab(long *arr, int size);
void	is_sorted(long *arr, int size);
int		ft_sqrt(int nb);

/******t_list fonctions******/
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_stack(t_list **a);

/*****rules*******/
void	sa(t_list **a);
void	ra(t_list **a);
void	rra(t_list **a);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	rb(t_list **a);
void	rrb(t_list **a);

/*******sort********/
void	ft_sort(t_list **head_stack_a, long *sort_tab, int size);
void	push_to_a_from_b(t_list **b, t_list **a, int size);
void	ft_get_current_pasition(t_list **a);
void	sort_5(t_list **a, long *tab, int size);
void	sort_3(t_list **head_stack);

#endif
