/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:19:59 by azahajur          #+#    #+#             */
/*   Updated: 2023/06/28 19:30:37 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **str, int nw)
{
	while (nw--)
		free(str[nw]);
	free(str);
}

int	ft_nword(char const *s, char c)
{
	int	cnt;
	int	wd;

	wd = 0;
	cnt = 0;
	while (*s)
	{
		if (*s != c && cnt == 0)
		{
			wd++;
			cnt = 1;
		}
		else if (*s == c)
			cnt = 0;
		s++;
	}
	return (wd);
}

int	ft_wlen(const char *s, char c)
{
	int	wnum;

	wnum = 0;
	while (*s != c && *s)
	{
		wnum++;
		s++;
	}
	return (wnum);
}

char	*ft_chsplit(char const *s, char c)
{
	int		wnum;
	int		i;
	char	*str;

	wnum = ft_wlen(s, c);
	i = 0;
	str = (char *)malloc((wnum + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < wnum)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		nw;
	int		cnt;
	char	**str;

	nw = ft_nword(s, c);
	str = (char **)malloc((nw + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	nw = 0;
	cnt = 0;
	while (*s)
	{
		if (*s != c && cnt++ == 0)
		{
			str[nw] = ft_chsplit(s, c);
			if (!str[nw])
				return (ft_free(str, nw), NULL);
			nw++;
		}
		else if (*s == c)
			cnt = 0;
		s++;
	}
	str[nw] = NULL;
	return (str);
}

// int	main(void)
// {
// 	char **word;
// 	char c;
// 	int i;

// 	i = 0;
// 	c = ' ';
// 	word = ft_split("hello!", c);
// 	while (word[i] != NULL)
// 	{
// 		printf("%i %s\n", i, word[i]);
// 		i++;
// 	}
// }