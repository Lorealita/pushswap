/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorea <lorea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:53:07 by lorea             #+#    #+#             */
/*   Updated: 2024/05/16 10:41:41 by lorea            ###   ########.fr       */
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
