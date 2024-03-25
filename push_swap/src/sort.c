/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchahmi <kchahmi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 12:59:18 by kchahmi       #+#    #+#                 */
/*   Updated: 2024/03/20 14:46:08 by kchahmi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_node **stack)
{
	t_node	*utilpointer;
	int		max;
	int		max_bits;

	utilpointer = *stack;
	max = 0;
	max_bits = 0;
	while (utilpointer)
	{
		if (utilpointer->index > max)
			max = utilpointer->index;
		utilpointer = utilpointer->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*utilpointer;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	utilpointer = *stack_a;
	size = get_stack_size(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			utilpointer = *stack_a;
			if (((utilpointer->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (get_stack_size(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	t_node	*utilpointer;
	int		run;
	int		index;

	index = 0;
	run = 2;
	utilpointer = *stack_a;
	while (run--)
	{
		while (utilpointer->index != index)
		{
			ra(stack_a);
			utilpointer = *stack_a;
		}
		pb(stack_a, stack_b);
		index++;
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	t_node	*utilpointer;

	utilpointer = *stack_a;
	while (utilpointer->index != 0)
	{
		ra(stack_a);
		utilpointer = *stack_a;
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_three(t_node **stack_a)
{
	int		one;
	int		two;
	int		three;
	t_node	*utilpointer;

	one = 0;
	two = 0;
	three = 0;
	utilpointer = *stack_a;
	while (!(one < two && two < three && three > one))
	{
		utilpointer = *stack_a;
		one = utilpointer->index;
		two = utilpointer->next->index;
		three = utilpointer->next->next->index;
		if ((one > two && two < three && three > one)
			|| (one > two && two > three && three < one)
			|| (one < two && two > three && three > one))
			sa(stack_a);
		if (one > two && two < three && three < one)
			ra(stack_a);
		if (one < two && two > three && three < one)
			rra(stack_a);
	}
}
