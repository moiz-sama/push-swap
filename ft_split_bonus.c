/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:03:27 by saderdou          #+#    #+#             */
/*   Updated: 2024/04/27 14:03:29 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

static int	count_words(char const	*s, char c, int *count)
{
	int		i;
	char	flag;

	i = 0;
	flag = c;
	*count = 0;
	while (s && s[i])
	{
		if (flag == c && s[i] != c)
			(*count)++;
		flag = s[i];
		i++;
	}
	return (*count);
}

static int	c_char(char const	*s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*word(char const	*s, char **strings, int index, char c)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(sizeof(char) * (c_char(s, c) + 1));
	if (!p)
	{
		if (index)
		{
			while (index--)
				free(strings[index]);
		}
		free(strings);
		return (NULL);
	}
	while (s[i] != c && s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char const	*s, char c, int *count)
{
	char	**strings;
	int		string_index;

	if (!s || !(*s))
		return (NULL);
	strings = malloc(sizeof(char *) * (count_words(s, c, count) + 1));
	if (!strings)
		return (NULL);
	string_index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			strings[string_index] = word(s, strings, string_index, c);
			if (!strings[string_index])
				return (NULL);
			string_index++;
		}
		while (*s && *s != c)
			s++;
	}
	strings[string_index] = NULL;
	return (strings);
}
