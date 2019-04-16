/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:40:52 by zamazzal          #+#    #+#             */
/*   Updated: 2018/10/09 20:29:19 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_strclen(char const *s, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

static int			*ft_strstrlen(char const *s, int len, char c)
{
	int	*ptr;
	int	i;
	int	contor;
	int	j;

	i = 0;
	j = 0;
	if (!(ptr = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	contor = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			ptr[j] = contor;
			j++;
			contor = 1;
		}
		else if (s[i] != c)
			contor++;
		i++;
	}
	return (ptr);
}

char				**ft_strsplit(char const *s, char c)
{
	int		l;
	int		*ptr;
	int		i;
	char	**str;
	int		y;

	if (!s)
		return (NULL);
	l = ft_strclen(s, c);
	ptr = ft_strstrlen(s, l, c);
	if (!(str = (char**)malloc(sizeof(char*) * (l + 1))))
		return (NULL);
	i = 0;
	y = 0;
	while (i < l)
	{
		str[i] = (char*)malloc(sizeof(char) * ptr[i]);
		while (s[y] == c)
			y++;
		ft_strncpy(str[i], &s[y], ptr[i]);
		y += ptr[i];
		i++;
	}
	str[i] = NULL;
	return (str);
}
