/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions_a.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchahmi <kchahmi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/17 18:11:39 by kchahmi       #+#    #+#                 */
/*   Updated: 2024/03/17 18:54:29 by kchahmi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_node **stack_a)
{
	if (stack_a == NULL)
		return ;
	swap(*stack_a);
	ft_printf("sa\n");
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}
