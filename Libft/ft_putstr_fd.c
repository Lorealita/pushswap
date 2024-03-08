/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:30:07 by azahajur          #+#    #+#             */
/*   Updated: 2023/06/28 19:13:34 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		write(fd, &s[cnt], 1);
		cnt++;
	}
}
