/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:11:15 by azahajur          #+#    #+#             */
/*   Updated: 2023/04/27 18:07:24 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;

	i = 0;
	str = (char *)src;
	str2 = (char *)dest;
	if (!str && !str2)
		return (dest);
	if (dest < src)
	{
		while (i < n)
		{
			str2[i] = str[i];
			i++;
		}
	}
	else
	{
		while (n--)
		{
			str2[n] = str[n];
		}
	}
	return (str2);
}

// int	main(void)
// {
// 	char dest[15] = "Nop";
// 	char src[10] = "Holol";
// 	int n = 5;
// 	printf("%s", ft_memmove(dest, src, n));
// }