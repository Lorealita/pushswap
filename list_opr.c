/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_opr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:42:06 by azahajur          #+#    #+#             */
/*   Updated: 2024/03/07 23:56:41 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// operaciones con listas. Me está costando entender las listas XD

# include "push_swap.h"

//Crear un nodo y convertirlo en el primer nodo de una lista.
t_nod *ft_first_nod(void)
{
    t_nod *aux;
    t_nod *list;

    list->cont = 5;
    aux = (t_nod *)malloc(sizeof(t_nod));
    aux = list;
    list = list->next;
    return(aux);
}
//función que crea un nodo
t_nod *ft_create_nod()
{
    
}

//función que inserta un nodo al final de la lista
t_nod *ft_insert_final(t_nod *list, "los datos que hay que meter")
{
    t_nod *nod;
    t_nod *aux;
    
    nod = ft_create_nod();
    if (list->head == NULL)
    {
        nod = head;
    }
    else
    {
        aux = list->head;
        while (aux->next)
        {
            aux = aux->next;
        }
        aux->next = nod;
    }
}

//borrar un nodo
ft_free (t_nod *nod)
{
    free(nod);
}

 //ft_sa(list->stack_a);
    //list->stack_a = ft_ra(list->stack_a);
    //list->stack_a = ft_rra(list->stack_a);
    //ft_order_mx3(list->stack_a);
    