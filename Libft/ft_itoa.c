/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:04:25 by azahajur          #+#    #+#             */
/*   Updated: 2023/06/28 22:35:22 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rec(int cnt, unsigned int n, char *res)
{
	res[cnt] = (n % 10) + '0';
	if (n > 9)
		ft_rec(cnt - 1, n / 10, res);
}

int	ft_nlen(int n)
{
	int	cnt;

	cnt = 0;
	if (n <= 0)
		cnt++;
	while (n != 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				cnt;
	unsigned int	nb;

	cnt = ft_nlen(n);
	res = (char *)malloc(cnt * sizeof(char) + 1);
	if (!res)
		return (0);
	res[cnt] = '\0';
	cnt--;
	if (n < 0)
	{
		res[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	ft_rec(cnt, nb, res);
	return (res);
}

// int	main(void)
// {
// 	char	*c;
// 	int		n;

// 	n = -0;
// 	c = ft_itoa(n);
// 	printf("%s", c);
// 	return (0);
// }
