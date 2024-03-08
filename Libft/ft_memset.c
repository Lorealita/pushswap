/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:52:00 by azahajur          #+#    #+#             */
/*   Updated: 2023/04/22 22:19:47 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	cnt;
	char	*str;

	str = s;
	cnt = 0;
	while (cnt != n)
	{
		str[cnt] = c;
		cnt++;
	}
	return (str);
}
