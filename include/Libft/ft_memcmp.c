/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:15:52 by azahajur          #+#    #+#             */
/*   Updated: 2023/06/29 13:55:30 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		cnt;
	const char	*str1;
	const char	*str2;

	cnt = 0;
	str1 = s1;
	str2 = s2;
	while ((cnt < n))
	{
		if (str1[cnt] != str2[cnt])
			return ((unsigned char)str1[cnt] - (unsigned char)str2[cnt]);
		cnt++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s[] = "Esto";
// 	char	c[] = "Esto";
// 	int		res;
// 	res = ft_memcmp(s, c, 11);
// 	printf("%d", res);
// }