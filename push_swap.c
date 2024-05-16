/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorea <lorea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:23:24 by azahajur          #+#    #+#             */
/*   Updated: 2024/05/16 15:11:11 by lorea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_mid_value(t_list *stack, int size)
{
    t_list  *node;
    int     sum;
    int     mid;
    
    sum = 0;
    node = stack;
    while (node->next != NULL)
    {
        sum += node->cont;
        node = node->next;
    }
    sum += node->cont;
    mid = sum / size;
    return(mid);
}

int ft_cont(t_list *stack)
{
   int  i;

   i = 0;
   while(stack != NULL)
   {
        i++;
        stack = stack->next;
   } 
   return(i);
}

void ft_init_a(t_stack *d_st, char *argv[], int argc)
{
    int i;
    t_list  *node;
    
    d_st->stack_a = (t_list *)malloc(sizeof(t_list));
    if (argc == 2)
    {
        d_st->stack_a->cont = ft_atol(argv[1]);
        return;
    }
    d_st->stack_a->cont = ft_atol(argv[1]);
    d_st->stack_a->next = (t_list *)malloc(sizeof(t_list));
    node = d_st->stack_a->next;
    i = 2;
    while (i < (argc - 1) && argv[i])
    {
        node->cont = ft_atol(argv[i]);
        node->next = (t_list *)malloc(sizeof(t_list));
        node = node->next;
        i++;
    }
    node->cont = ft_atol(argv[i]);
    node->next = NULL;
    d_st->size_a = ft_cont(d_st->stack_a);
}

void ft_init_b(t_stack *d_st)
{   
    int     mid;
    
    mid = ft_mid_value(d_st->stack_a, d_st->size_a);
    while(d_st->size_a > 3 && d_st->stack_a->next != NULL)
    {
        if (d_st->stack_a->cont > mid)
        {
            ft_pb(d_st);
        }
        d_st->stack_a = ft_ra(d_st->stack_a);
        d_st->stack_a = d_st->stack_a->next;
    } 
    if (d_st->size_a > 3)
    {
        ft_pb(d_st);
    }
    d_st->size_b = ft_cont(d_st->stack_b);
    return;
}

int	main(int argc, char *argv[])
{
    t_stack *d_st;
    t_list *node;
    
    if(argc > 1) 
    {
        ft_dupl_n(argc, argv);
        ft_char_ent(argv);
        d_st = (t_stack *)malloc(sizeof(t_stack));
        ft_init_a(d_st, argv, argc); 
        ft_choose_sort(d_st->stack_a, d_st->size_a);
        ft_init_b(d_st); //Hace bucle!! ò_ó
        ft_print_list(d_st->stack_a);
        d_st->stack_a = ft_sort_3(d_st->stack_a);
        while (d_st->stack_b)
        {
            ft_pos_stack(d_st);
            ft_sort_cost(d_st);
            node = ft_mov_cost(d_st);
            ft_sales(d_st, node);
        }
        ft_sort_boss(d_st);
        ft_free_stack(d_st);
        return(0);
    }
    return(0);
}
