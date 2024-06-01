/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:02:22 by saderdou          #+#    #+#             */
/*   Updated: 2024/04/27 14:02:24 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	ft_check_args2(char **args, int i, int j)
{
	int	flag;

	flag = 0;
	while (args[i][j])
	{
		if (ft_isdigit(args[i][j]) == 1 || args[i][j] == ' '
		|| args[i][j] == '+' || args[i][j] == '-')
		{
			if (args[i][j] == '+' || args[i][j] == '-')
			{
				if ((j != 0 && args[i][j - 1] != ' ')
				|| ft_isdigit(args[i][j + 1]) == 0)
				{
					error();
				}
			}
			else if (ft_isdigit(args[i][j]) == 1)
				flag++;
		}
		else
			error();
		j++;
	}
	if (flag == 0)
		error();
}

void	ft_check_args(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		if (args[i][0] == '\0')
			error();
		j = 0;
		ft_check_args2(args, i, j);
		i++;
	}
}

int	ft_valid_args(char *args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (args[i] && (args[i] == '-' || args[i] == '+'))
		i++;
	while (args[i] && args[i] == '0')
		i++;
	while (args[i] && args[i] >= '0' && args[i] <= '9')
	{
		i++;
		count++;
	}
	return (count);
}

void	ft_check_double(long *tab, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
		{
			free(tab);
			error();
		}
		j = i + 1;
		while (j < count)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				error();
			}
			j++;
		}
		i++;
	}
}
