/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorea <lorea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:20:25 by lorea             #+#    #+#             */
/*   Updated: 2024/05/15 09:36:55 by lorea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_dupl_n(int argc, char *argv[])
{
    int   i;
    int   j;
    int   r;
    int   r2;
    
    i = 1;
    while (argc != i)
    {
        j = i + 1;
        while (j != argc)
        {
            r = ft_atol(argv[i]);
            r2 = ft_atol(argv[j]);
            if (r == r2)
            {
                ft_putstr_fd("[Error]: Duplicity\n",2);
                exit(1);
            }
            j++;
        }
        i++;
    }
    return;
}

void ft_char_ent(char *argv[])
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]))
            {
                if (argv[i][j] != '-' && argv[i][j] != '+')
                {
                    if (argv[i][j] != ' ')
                    {
                        ft_putstr_fd("[Error]: Only_Natural_Num_Allowed\n",2);
                        exit(1);
                    }
                }
            }
            j++;
        }
        i++;
    }
    return;
}
