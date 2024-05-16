/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorea <lorea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:53:07 by lorea             #+#    #+#             */
/*   Updated: 2024/05/16 14:46:47 by lorea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calcula la media del stack_a para dejar en stack_a 3 valores menores que la media

void ft_print_list(t_list *stack)
{
    t_list  *node;
    
    node = stack;
    while(node != NULL)
    {
        printf("Contenido de la lista: %i pos_n:%i pos_o:%i cost_a:%i cost_b:%i\n", node->cont, node->pos_n, node->pos_o, node->cost_a, node->cost_b);
        node = node->next;
    }
}

void ft_free_stack(t_stack *d_st)
{
    t_list  *node;
    
    while (d_st->stack_a != NULL && d_st-> stack_a-> next != NULL)
    {
        node = d_st-> stack_a;
        d_st-> stack_a = d_st-> stack_a -> next;
        free(node);
    }
    free (d_st->stack_a);
    while (d_st->stack_b != NULL && d_st-> stack_b-> next != NULL)
    {
        node = d_st-> stack_b;
        d_st-> stack_b = d_st-> stack_b -> next;
        free(node);
    }
    free (d_st->stack_b);
    free (d_st);
    return;
}

void    ft_pos_stack(t_stack *d_st)
{
    ft_pos_check(d_st->stack_b);
    ft_pos_check(d_st->stack_a); 
}

t_list  *ft_lowest(t_list *stack_a)
{
    t_list  *node;
    t_list  *lowest;

    node = stack_a;
    lowest = node;
    while (node)
    {
        if (node->cont < lowest->cont)
            lowest = node;
        node = node->next;       
    }
    return(lowest);
}

void    ft_sort_boss(t_stack *d_st)
{
    ft_pos_stack(d_st);
    d_st->size_a = ft_cont(d_st->stack_a);
    d_st->lowest = ft_lowest(d_st->stack_a);
    if (d_st->lowest->pos_n > d_st->size_a / 2)
    {
        while (!ft_check_pos(d_st->stack_a))
            d_st->stack_a = ft_rra(d_st->stack_a);
    }
    else
    {
        while (!ft_check_pos(d_st->stack_a))
            d_st->stack_a = ft_ra(d_st->stack_a);
    }
    return;
}