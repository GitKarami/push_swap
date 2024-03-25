/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchahmi <kchahmi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 15:22:10 by kchahmi       #+#    #+#                 */
/*   Updated: 2024/03/20 19:00:17 by kchahmi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_stack_bottom(t_node *stack)
{
	t_node	*utilpointer;

	utilpointer = stack;
	while (utilpointer && utilpointer->next != NULL)
		utilpointer = utilpointer->next;
	return (utilpointer);
}

t_node	*get_stack_before_bottom(t_node *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof * new_node);
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	create_stack(t_node **stack, int argc, char **argv)
{
	int		i;
	t_node	*utilpointer;

	i = argc - 2;
	*stack = create_node(ft_atoi(*argv));
	argv++;
	while (i--)
	{
		utilpointer = get_stack_bottom(*stack);
		utilpointer->next = create_node(ft_atoi(*argv));
		argv++;
	}
	set_index(stack);
}
