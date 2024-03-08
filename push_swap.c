/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:23:24 by azahajur          #+#    #+#             */
/*   Updated: 2024/03/08 04:46:15 by azahajur         ###   ########.fr       */
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

void ft_check_char(char **argv)
{
    int i;
    int j;
    
    i = 0;
    while (argv[i] != NULL)
    {
        j = 0;
        while(argv[i][j])
        {
            if(!ft_isdigit(argv[i][j]))
            {
                ft_putstr_fd("[Error]: No_Num_Arg", 2);
                exit(1);
            } 
            j++;
        }
        i++;
    }
    
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
    d_st->stack_a->cont = ft_atoi(argv[1]);
    d_st->stack_a->next = (t_list *)malloc(sizeof(t_list));
    node = d_st->stack_a->next;
    i = 2;
    while (i < argc - 1 && argv[i])
    {
        node->cont = ft_atoi(argv[i]);
        node->next = (t_list *)malloc(sizeof(t_list));
        node = node->next;
        i++;
    }
    node->cont = ft_atoi(argv[i]);
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
    
    if(argc < 1)
        return(0);
    //ft_dupl_n(argc, argv)//funcion que comprueba si hay número duplicados || ft_int_n(arc, argv)) // función que comprueba que todos los números son enteros
    //     ft_putstr_fd("Error", 2);
    // ft_check_char(char **argv); // Comprueba todo argv por si hay un char
    d_st = (t_stack *)malloc(sizeof(t_stack));
    ft_init_a(d_st, argv, argc); 
    d_st->size_a = ft_cont(d_st->stack_a);
    if(d_st->size_a == 1)
        return(0);
    if(d_st->size_a == 3 || d_st->size_a == 2)
    {
        d_st->stack_a = ft_order_mx3(d_st->stack_a, d_st->size_a);
        return(0);
    }
    ft_init_b(d_st);
    d_st->stack_a = ft_order_mx3(d_st->stack_a, d_st->size_a);
    ft_order_cost(d_st);
    // //Se viene algoritmo de ordenamiento.
    ft_print_list(d_st->stack_a); 
    ft_putstr_fd("JUAJAJAJAJA\n",1);
    ft_print_list(d_st->stack_b); 
    return(0);
}
