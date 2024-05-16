/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorea <lorea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:02:44 by azahajur          #+#    #+#             */
/*   Updated: 2024/05/16 12:20:37 by lorea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sa(t_list *stack_a)
{
    int tmp;
    
    if(!stack_a || !stack_a->next)
        return;
    tmp = stack_a->cont;
    stack_a->cont = stack_a->next->cont;
    stack_a->next->cont = tmp;
    ft_putstr_fd("sa\n", 1);
    ft_pos_check(stack_a);
}

t_list    *ft_ra(t_list *stack_a)
{
    t_list  *node;
    t_list  *aux2;
    
    if(!stack_a->next || !stack_a)
        return(stack_a);
    node = stack_a;
    aux2 = stack_a->next;
    while (stack_a->next != NULL)
    {
        stack_a = stack_a->next;
    }
    stack_a->next = node;
    node->next = NULL;
    ft_pos_check(aux2);
    ft_putstr_fd("ra\n", 1);
    return(aux2);
}

t_list  *ft_rra(t_list *stack_a)
{
    t_list  *aux;
    t_list  *aux2;
    
    if(!stack_a->next)
        return(stack_a);
    aux = stack_a;
    while (aux->next->next != NULL)
        aux = aux->next;
    aux->next->next = stack_a;
    aux2 = aux->next;
    aux->next = NULL;
    ft_pos_check(aux2);
    ft_putstr_fd("rra\n", 1);
    return(aux2);
}

void    ft_pa(t_stack *d_st)
{
    t_list	*node;

	if (d_st->stack_b)
	{
		if (!d_st->stack_a)
		{
			d_st->stack_a = d_st->stack_b;
            d_st->stack_b = d_st->stack_b->next;
			d_st->stack_a->next = NULL;
		}
		else
		{
            node = d_st->stack_a;
            d_st->stack_a = d_st->stack_b;
            d_st->stack_b = d_st->stack_b->next;
            d_st->stack_a->next = node;
		}
	}
	ft_cont(d_st->stack_a);
	ft_cont(d_st->stack_b);
	printf("pa\n");
	return;
}
