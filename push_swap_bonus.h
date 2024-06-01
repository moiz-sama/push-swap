/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:54:31 by saderdou          #+#    #+#             */
/*   Updated: 2024/04/27 14:54:33 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 37
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

/*get_next_line*/
char	*get_next_line(int fd, int flag);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
int		ft_check(char *s);

/*parsin*/
void	ft_check_args(char **args);
long	*ft_strjoin_and_split(int ac, char **av, int *count);
char	**ft_split(char const	*s, char c, int *count);
void	ft_free(char **str, int i);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_check_double(long *tab, int count);
void	is_sorted(long *arr, int size);
int		ft_strncmp(char *s1, char *s2, size_t n);

/******t_list fonctions******/
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_stack(t_list **a);

/*rules*/
void	sa(t_list **a);
void	ra(t_list **a);
void	rra(t_list **a);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	sb(t_list **b);
void	rb(t_list **a);
void	rrb(t_list **a);
void	ss(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
#endif
