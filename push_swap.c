/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorea <lorea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:23:24 by azahajur          #+#    #+#             */
/*   Updated: 2024/05/15 13:19:46 by lorea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void ft_print_list(t_list *stack)
{
    t_list  *node;
    
    node = stack;
    while(node != NULL)
    {
        printf("Contenido de la lista: %i pos_o:%i cost_a:%i cost_b:%i\n", node->cont, node->pos_o, node->cost_a, node->cost_b);
        node = node->next;
    }
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
}

void ft_init_b(t_stack *d_st)
{   
    d_st->size_a = ft_cont(d_st->stack_a);
    while(d_st->size_a > 3)
    {
        ft_pb(d_st);
        d_st->size_a--;
    }
}

int	main(int argc, char *argv[])
{
    t_stack *d_st;
    
    if(argc > 1) 
    {
        ft_dupl_n(argc, argv);
        ft_char_ent(argv);
        d_st = (t_stack *)malloc(sizeof(t_stack));
        ft_init_a(d_st, argv, argc); 
        d_st->size_a = ft_cont(d_st->stack_a);
        d_st->stack_a = ft_check_order(d_st->stack_a, d_st->size_a);
        //ft_init_b(d_st);
        //d_st->stack_a = ft_order_3(d_st->stack_a);
        //ft_order_cost(d_st);
        //ft_putstr_fd("=====================\n",1);
        //ft_print_list(d_st->stack_b); 
    }
    return(0);
}
