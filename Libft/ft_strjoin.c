/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:40:34 by azahajur          #+#    #+#             */
/*   Updated: 2023/06/01 13:36:31 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	tlen;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tlen = len1 + len2;
	i = 0;
	str = (char *)malloc(tlen * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	ft_memmove(str, s1, len1);
	while (len1 < tlen)
	{
		str[len1] = s2[i];
		i++;
		len1++;
	}
	str[len1] = '\0';
	return (str);
}
