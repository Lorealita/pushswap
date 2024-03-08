/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:07:02 by azahajur          #+#    #+#             */
/*   Updated: 2024/03/08 05:34:30 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_dupl_n(argc, argv)//funcion que comprueba si hay número duplicados
// ft_int_n(arc, argv)) // función que comprueba que todos los números son enteros

void    ft_pos_check(t_list *stack)
{
    t_list *aux;
    int cnt;

    cnt = 1;
    aux = stack;
    while (aux != NULL)
    {
        aux->pos_n = cnt; 
        aux = aux->next;   
        cnt++;
    }
}

t_list *ft_order_2(t_list *stack)
{
    ft_putstr_fd("sa\n", 1);
    if(stack->cont > stack->next->cont)
    {
        ft_sa(stack);
        ft_print_list(stack);
        return(stack);
    }
    return(stack);
}

t_list *ft_order_mx3(t_list *stack, int size_a) //ordena un stack de cómo máximo 3 números
{
    int a;
    int b;
    int c;
    
    a = stack->cont;
    b = stack->next->cont;
    c = stack->next->next->cont;
    if(size_a == 2)
        return(ft_order_2(stack));
    if (size_a == 3)
    {    
        if(a > b && b < c && a < c)
            ft_sa(stack);
        else if(a < b && b > c && a > c)
            stack = ft_rra(stack);
        else if(a > b && b > c)
        {
            ft_sa(stack);
            stack = ft_rra(stack);
        }
        else if(a > b && b < c && a > c)
            stack = ft_ra(stack);
        else if(a < b && b > c && a < c)
        {
            stack = ft_rra(stack);
            ft_sa(stack);
        }
        return(stack);
    }
    return(stack);
}

void    ft_sales(t_stack *d_st, t_list *sales)
{
    if sales->cost_a == 1 && sales->cost_b ==1
        pa(d_st);
    else if sales->cost_a < 0 && sales->cost_b < 0
        d_st = rrr(d_st);
    else if sales->cost_a > 0 && sales->cost_b > 0
        d_st = rr(d_st);
    else if sales->cost_a < 0
        d_st->stack_a = rra(d_st->stack_a);
    else if sales->cost_a > 0
        d_st->stack_a = ra(d_st->stack_a);
    else if sales->cost_b < 0
        d_st->stack_b = rrb(d_st->stack_b);
    else if sales->cost_b > 0
        d_st->stackb = rb(d_st->stack_b);
    
}