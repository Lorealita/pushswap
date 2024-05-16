/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:25:24 by azahajur          #+#    #+#             */
/*   Updated: 2023/07/02 20:30:39 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	cnt1;
	size_t	dst_len;
	size_t	src_len;

	cnt1 = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	while (cnt1 < (size - dst_len - 1) && src[cnt1] != '\0')
	{
		dst[dst_len + cnt1] = src[cnt1];
		cnt1++;
	}
	dst[dst_len + cnt1] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char c[] = "The cake";
// 	char f[] = "is a lie";
// 	int	n = 8;
// 	printf("%zu", ft_strlcat(c, f, n));
// 	printf("%s", c); 
// }