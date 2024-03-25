/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchahmi <kchahmi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/17 18:03:24 by kchahmi       #+#    #+#                 */
/*   Updated: 2024/03/20 18:47:48 by kchahmi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	if (get_stack_size(*stack_a) == 2)
	{
		if ((*stack_a)->index != 0)
			ra(stack_a);
	}
	if (get_stack_size(*stack_a) == 3)
		sort_three(stack_a);
	if (get_stack_size(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	if (get_stack_size(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	if (get_stack_size(*stack_a) > 5)
		radix_sort(stack_a, stack_b);
}

t_node	*find_lowest(t_node **stack)
{
	t_node	*utilpointer;
	t_node	*lowest;
	int		setlowest;

	lowest = NULL;
	setlowest = 0;
	utilpointer = *stack;
	while (utilpointer)
	{
		if (utilpointer->index == -1
			&& (!setlowest || utilpointer->value < lowest->value))
		{
			lowest = utilpointer;
			setlowest = 1;
		}
		utilpointer = utilpointer->next;
	}
	return (lowest);
}

void	print_list(t_node **stack)
{
	t_node	*utilpointer;

	utilpointer = *stack;
	while (utilpointer)
	{
		printf("VALUE:%d\n", utilpointer->value);
		printf("INDEX:%d\n\n", utilpointer->index);
		utilpointer = utilpointer->next;
	}
}

void	error_handler(int num)
{
	if (num == 1)
		printf("Duplicate found\n");
	if (num == 2)
		printf("Non numeric input\n");
	if (num == 3)
		printf("Not enough arguments\n");
	if (num == 4)
		printf("Number is out of range\n");
	if (num == 5)
		printf("Please remove unnecessary 0's\n");
	if (num == 6)
		printf("Please remove unnecessary minus signs\n");
	if (num == 7)
		printf("Did you really just try -0?\n");
}

void	ft_free(t_node **stack)
{
	t_node	*utilpointer;
	t_node	*tmp;

	utilpointer = *stack;
	while (utilpointer)
	{
		tmp = utilpointer;
		utilpointer = utilpointer->next;
		free(tmp);
	}
	free(stack);
}
