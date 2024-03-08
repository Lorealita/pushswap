/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ft_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:47:39 by azahajur          #+#    #+#             */
/*   Updated: 2024/03/08 05:17:23 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_target(t_list *stack_a, t_list *stack_b, int min)
{
	t_list	*aux;

	aux = stack_a;
	while (aux != NULL)
	{
		if (stack_b->cont < aux->cont && aux->cont < min)
		{
			min = aux->cont;
			stack_b->pos_o = aux->pos_n;
		}
		aux = aux->next;
	}
	if (min != INT_MAX)
		return ;
	aux = stack_a;
	while (aux != NULL)
	{
		if (aux->cont < min)
		{
			min = aux->cont;
			stack_b->pos_o = aux->pos_n;
		}
		aux = aux->next;
	}
}

void	ft_pos_o(t_stack *d_st)
{
	t_list	*aux2;
	int		min;

	aux2 = d_st->stack_b;
	min = INT_MAX;
	while (aux2 != NULL)
	{
		ft_target(d_st->stack_a, aux2, min);
		aux2 = aux2->next;
	}
}

void	ft_order_cost(t_stack *d_st)
{
	t_list	*aux;

	aux = d_st->stack_b;
	while (aux != NULL)
	{
		ft_pos_o(d_st);
		d_st->size_a = ft_cont(d_st->stack_a);
		d_st->size_b = ft_cont(d_st->stack_b);
		if (d_st->size_a / 2 < aux->pos_o)
			aux->cost_a = aux->pos_o * (-1);
		else
			aux->cost_a = aux->pos_o;
		if (d_st->size_b / 2 < aux->pos_n)
			aux->cost_b = aux->pos_n * (-1);
		else
			aux->cost_b = aux->pos_n;
		aux = aux->next;
	}
}

int	ft_sign(int cost)
{
	if (cost < 0)
		cost = cost * (-1);
	return (cost);
}

t_list  *ft_mov_cost(t_stack *d_st)
{
	t_list	*aux;
	t_list	*aux2;
	int		min;

	min = 1;
	aux = d_st->stack_b;
	while (aux != NULL)
	{
		if (ft_sign(aux->cost_a) + ft_sign(aux->cost_b) < min)
		{
			min = ft_sign(aux->cost_a) + ft_sign(aux->cost_b);
			aux2 = aux;
		}
	}
    return(aux2);
}
