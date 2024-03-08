/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:51:48 by azahajur          #+#    #+#             */
/*   Updated: 2023/06/28 20:39:14 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	const char		*str;
	size_t			cnt;

	str = s;
	cnt = 0;
	while (cnt < len)
	{
		if ((unsigned char)str[cnt] == (unsigned char)c)
		{
			str = &s[cnt];
			return ((void *)str);
		}
		cnt++;
	}
	return (0);
}
