/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 04:29:26 by azahajur          #+#    #+#             */
/*   Updated: 2024/03/07 04:44:32 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack *d_st)
{
	ft_sa(d_st->stack_a);
	ft_sb(d_st->stack_b);
}

t_stack	*ft_rr(t_stack *d_st)
{
	d_st->stack_a = ft_ra(d_st->stack_a);
	d_st->stack_b = ft_rb(d_st->stack_b);
	return (d_st);
}

t_stack	*ft_rrr(t_stack *d_st)
{
	d_st->stack_a = ft_rra(d_st->stack_a);
	d_st->stack_b = ft_rrb(d_st->stack_b);
	return (d_st);
}