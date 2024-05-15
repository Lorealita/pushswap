/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 04:05:47 by azahajur          #+#    #+#             */
/*   Updated: 2024/03/08 03:12:19 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sb(t_list *stack_b)
{
    int tmp;
    
    if(!stack_b || !stack_b->next)
        return;
    tmp = stack_b->cont;
    stack_b->cont = stack_b->next->cont;
    stack_b->next->cont = tmp;
    ft_pos_check(stack_b);
}

t_list    *ft_rb(t_list *stack_b)
{
    t_list  *aux;
    t_list  *aux2;
    
    if(!stack_b->next)
        return(stack_b);
    aux = stack_b;
    aux2 = stack_b->next;
    while (stack_b->next != NULL)
    {
        stack_b = stack_b->next;
    }
    stack_b->next = aux;
    aux->next = NULL;
    ft_pos_check(aux2);
    return(aux2);
}

t_list  *ft_rrb(t_list *stack_b)
{
    t_list  *aux;
    t_list  *aux2;
    
    if(!stack_b->next)
        return(stack_b);
    aux = stack_b;
    while (aux->next->next != NULL)
    {
        aux = aux->next;
    }
    aux->next->next = stack_b;
    aux2 = aux->next;
    aux->next = NULL;
    ft_pos_check(aux2);
    return(aux2);
}

void    ft_pb(t_stack *d_st)
{
    t_list *aux;
    
    if(!d_st->stack_b)
    {
        d_st->stack_b = d_st->stack_a;
        d_st->stack_a = d_st->stack_a->next;
        d_st->stack_b->next = NULL;
    }
    else
    {
        aux = d_st->stack_b;
        d_st->stack_b = d_st->stack_a;
        d_st->stack_a = d_st->stack_a->next;
        d_st->stack_b->next = aux;   
    }
    ft_pos_check(d_st->stack_b);
    ft_pos_check(d_st->stack_a);
    ft_putstr_fd("pb\n", 1);
}
