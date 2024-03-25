/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchahmi <kchahmi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 17:38:29 by kchahmi       #+#    #+#                 */
/*   Updated: 2024/03/20 15:19:39 by kchahmi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*temp;
	t_node	*last_node;

	if (!*stack || *stack == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last_node = get_stack_bottom(*stack);
	temp->next = NULL;
	last_node->next = temp;
}

void	reverse_rotate(t_node **stack)
{
	t_node	*temp;
	t_node	*util;

	if (!*stack || *stack == NULL)
		return ;
	util = get_stack_bottom(*stack);
	temp = get_stack_before_bottom(*stack);
	temp->next = NULL;
	util->next = *stack;
	*stack = util;
}

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;
	t_node	*srctemp;
	t_node	*desttemp;

	if (*src == NULL)
		return ;
	srctemp = *src;
	desttemp = *dest;
	temp = srctemp;
	srctemp = srctemp->next;
	*src = srctemp;
	if (!dest)
	{
		desttemp = temp;
		desttemp->next = NULL;
		*dest = desttemp;
	}
	else
	{
		temp->next = desttemp;
		*dest = temp;
	}
}

void	swap(t_node *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}
