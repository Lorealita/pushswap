/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:36:32 by azahajur          #+#    #+#             */
/*   Updated: 2023/04/26 16:26:03 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*str;
	char		*str2;

	i = 0;
	str = src;
	str2 = dest;
	if (!str && !str2)
		return (0);
	while (i < n)
	{
		str2[i] = str[i];
		i++;
	}
	return (dest);
}
