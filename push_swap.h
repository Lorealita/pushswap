/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:24:28 by azahajur          #+#    #+#             */
/*   Updated: 2024/03/08 05:16:56 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
//librería de malloc y free
# include <string.h>

typedef struct s_list_nodes
{
	int cont;  //contenido
	int pos_n; //posición actual
	int pos_o; // posicion objetivo
	int		cost_a;
	int		cost_b;
	struct s_list_nodes *next; // puntero al siguiente nodo
}			t_list;

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;
	int		size_b;
}			t_stack;

void		ft_init_a(t_stack *list, char *argv[], int argc);
void		ft_init_b(t_stack *d_st);
void		ft_print_list(t_list *head);
void		ft_check_char(char **argv);
int			ft_cont(t_list *stack);

void		ft_sa(t_list *list);
t_list		*ft_ra(t_list *stack_a);
t_list		*ft_rra(t_list *stack_a);
void		ft_pa(t_stack *d_st);

void		ft_sb(t_list *stack_b);
t_list		*ft_rb(t_list *stack_b);
t_list		*ft_rrb(t_list *stack_b);
void		ft_pb(t_stack *d_st);

void		ft_ss(t_stack *d_st);
t_stack		*ft_rr(t_stack *d_st);
t_stack		*ft_rrr(t_stack *d_st);

t_list		*ft_order_mx3(t_list *stack, int size);
void		ft_pos_check(t_list *stack);

void		ft_pos_o(t_stack *d_st);
void		ft_target(t_list *stack_a, t_list *stack_b, int min);
void		ft_order_cost(t_stack *d_st);
t_list		ft_mov_cost(t_stack *d_st);
int			ft_sign(int cost);

#endif