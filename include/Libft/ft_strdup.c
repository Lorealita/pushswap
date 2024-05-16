/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:37:58 by azahajur          #+#    #+#             */
/*   Updated: 2023/06/27 18:53:35 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	nmemb;
	char	*str;

	nmemb = ft_strlen(s);
	str = (char *)ft_calloc(nmemb + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = (char *)ft_memmove(str, s, nmemb);
	return (str);
}
