/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorea <lorea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:47:39 by azahajur          #+#    #+#             */
/*   Updated: 2024/05/16 06:32:16 by lorea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_target(t_list *stack_a, t_list *stack_b, int min)
{
	t_list	*node;

	node = stack_a;
	while (node != NULL)
	{
		if (stack_b->cont < node->cont && node->cont < min)
		{
			min = node->cont;
			stack_b->pos_o = node->pos_n;
		}
		node = node->next;
	}
	if (min != INT_MAX)
		return;
	node = stack_a;
	while (node != NULL)
	{
		if (node->cont < min)
		{
			min = node->cont;
			stack_b->pos_o = node->pos_n;
		}
		node = node->next;
	}
}

void	ft_pos_o(t_stack *d_st)
{
	t_list	*node;
	int		min;

	node = d_st->stack_b;
	min = INT_MAX;
	while (node != NULL)
	{
		ft_target(d_st->stack_a, node, min);
		node = node->next;
	}
}

void	ft_sort_cost(t_stack *d_st)
{
	t_list	*node;

	node = d_st->stack_b;
	while (node != NULL)
	{
		ft_pos_o(d_st);
		d_st->size_a = ft_cont(d_st->stack_a);
		d_st->size_b = ft_cont(d_st->stack_b);
		if (d_st->size_a / 2 < node->pos_o)
			node->cost_a = node->pos_o * (-1);
		else
			node->cost_a = node->pos_o;
		if (d_st->size_b / 2 < node->pos_n)
			node->cost_b = node->pos_n * (-1);
		else
			node->cost_b = node->pos_n;
		node = node->next;
	}
}

int	ft_sign(int cost)
{
	if (cost < 0)
		return(cost * (-1));
	else
		return (cost);
}

t_list  *ft_mov_cost(t_stack *d_st)
{
	t_list	*node;
	t_list	*aux;

	node = d_st->stack_b;
	aux = node;
	while (node != NULL)
	{
		if (ft_sign(node->cost_a) + ft_sign(node->cost_b) < ft_sign(aux->cost_a)
				+ ft_sign(aux->cost_b))
			aux = node;
		node = node->next;
	}
    return(aux);
}
