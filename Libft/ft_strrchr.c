/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:37:45 by azahajur          #+#    #+#             */
/*   Updated: 2023/05/03 14:48:21 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		cnt;
	const char	*ch;

	cnt = ft_strlen(s) + 1;
	ch = s;
	while (cnt--)
	{
		if (s[cnt] == (char)c)
		{
			ch = &s[cnt];
			return ((char *)ch);
		}
		if ((char)c == '\0')
			return ((char *)ch + cnt);
	}
	return (NULL);
}
