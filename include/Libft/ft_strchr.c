/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:57:51 by azahajur          #+#    #+#             */
/*   Updated: 2023/06/28 22:00:17 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			cnt;
	const char	*ch;

	cnt = 0;
	ch = s;
	while (s[cnt] != '\0')
	{
		if (s[cnt] == (char)c)
		{
			ch = &s[cnt];
			return ((char *)ch);
		}
		cnt++;
	}
	if ((char)c == '\0')
		return ((char *)ch + cnt);
	return (NULL);
}

// int	main(void)
// {
// 	char c[] = "Costas\0dfteo";
// 	printf("%s", ft_strchr(c, 't' + 256));
// }