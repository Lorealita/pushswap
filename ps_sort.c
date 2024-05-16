/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorea <lorea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:07:02 by azahajur          #+#    #+#             */
/*   Updated: 2024/05/15 17:56:40 by lorea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_pos_check(t_list *stack)
{
    t_list *node;
    int cnt;

    cnt = 1;
    node = stack;
    while (node != NULL)
    {
        node->pos_n = cnt; 
        node = node->next;   
        cnt++;
    }
}

void    ft_check_sort(t_list *stack, int size)
{
    if(size == 3) 
    {
        stack = ft_sort_3(stack);
        ft_print_list(stack); 
        return;
    }
    else if (size == 2) 
    {
        stack = ft_sort_2(stack);
        ft_print_list(stack); 
        return;
    }
}

t_list *ft_sort_2(t_list *stack)
{
    if(stack->cont > stack->next->cont)
    {
        ft_sa(stack);
    }
    return(stack);
}

t_list *ft_sort_3(t_list *stack)
{
    int a;
    int b;
    int c;
    
    a = stack->cont;
    b = stack->next->cont;
    c = stack->next->next->cont;
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

void    ft_sales(t_stack *d_st, t_list *sales)
{
    if (sales->cost_a == 1 && sales->cost_b ==1)
        ft_pa(d_st);
    else if (sales->cost_a < 0 && sales->cost_b < 0)
        d_st = ft_rrr(d_st);
    else if (sales->cost_a > 0 && sales->cost_b > 0)
        d_st = ft_rr(d_st);
    else if (sales->cost_a < 0)
        d_st->stack_a = ft_rra(d_st->stack_a);
    else if (sales->cost_a > 0)
        d_st->stack_a = ft_ra(d_st->stack_a);
    else if (sales->cost_b < 0)
        d_st->stack_b = ft_rrb(d_st->stack_b);
    else if (sales->cost_b > 0)
        d_st->stack_b = ft_rb(d_st->stack_b);
    
}

