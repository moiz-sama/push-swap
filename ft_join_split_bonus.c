/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_split_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:03:01 by saderdou          #+#    #+#             */
/*   Updated: 2024/04/27 14:03:03 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*copy;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

static long	*ft_tab(char **args, int *count)
{
	long	*tab;
	int		i;

	i = 0;
	tab = (long *)malloc((*count) * sizeof(long));
	if (!tab)
		return (NULL);
	while (args[i])
	{
		if (ft_valid_args(args[i]) > 10)
		{
			free(tab);
			ft_free(args, *count);
			error ();
		}
		tab[i] = ft_atoi(args[i]);
		i++;
	}
	return (tab);
}

long	*ft_strjoin_and_split(int ac, char **av, int *count)
{
	int		i;
	char	*args;
	char	**av_split;
	long	*tab;
	char	*tmp;

	i = 1;
	args = NULL;
	while (i < ac)
	{
		tmp = args;
		args = ft_strjoin(tmp, av[i]);
		free(tmp);
		tmp = args;
		args = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	av_split = ft_split(args, ' ', count);
	free(args);
	tab = ft_tab(av_split, count);
	ft_free(av_split, *count);
	return (tab);
}
