/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchahmi <kchahmi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 12:43:28 by kchahmi       #+#    #+#                 */
/*   Updated: 2024/03/20 20:06:10 by kchahmi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	duplicate_checker(t_node **stack_a)
{
	t_node	*utilpointer;
	t_node	*looper;

	utilpointer = *stack_a;
	looper = (*stack_a)->next;
	while (utilpointer)
	{
		while (looper)
		{
			if (utilpointer->value == looper->value)
				return (error_handler(1), 1);
			looper = looper->next;
		}
		utilpointer = utilpointer->next;
		if (utilpointer)
			looper = utilpointer->next;
	}
	return (0);
}

int	valid_arg(char *argv)
{
	if (argv[0] == '-' && argv[1] == '0')
		return (error_handler(7), 1);
	if (argv[0] == '0' && argv[1])
		return (error_handler(5), 1);
	while (*argv)
	{
		if (argv[0] == '-' && ((argv[1] >= '0' && argv[1] <= '9')))
			argv++;
		if (argv[0] == '-' && (!(argv[1] >= '0' && argv[1] <= '9')))
			return (error_handler(6), 1);
		if (!(*argv >= '0' && *argv <= '9'))
			return (error_handler(2), 1);
		argv++;
	}
	return (0);
}

int	valid(int argc, char **argv)
{
	if (argc < 2)
		return (error_handler(3), 1);
	while (*argv)
	{
		if (valid_arg(*argv) == 1)
			return (1);
		if (ft_strlen(*argv) > 10)
		{
			if (ft_strlen(*argv) == 11)
			{
				if (*argv[0] != '-')
					return (error_handler(4), 1);
				if (ft_atol(*argv) < INT_MIN)
					return (error_handler(4), 1);
			}
			if (ft_strlen(*argv) > 11)
				return (error_handler(4), 1);
		}
		if (ft_strlen(*argv) == 10)
			if (ft_atol(*argv) > INT_MAX)
				return (error_handler(4), 1);
		argv++;
	}
	return (0);
}

void	set_index(t_node **stack)
{
	t_node	*utilpointer;
	int		index;
	int		test;

	test = get_stack_size(*stack);
	index = 0;
	utilpointer = *stack;
	while (test--)
	{
		utilpointer = find_lowest(stack);
		if (utilpointer != NULL)
			utilpointer->index = index;
		index++;
	}
}

int	check_if_sorted(t_node **stack)
{
	t_node	*utilpointer;

	utilpointer = *stack;
	while (utilpointer)
	{
		if (utilpointer->next)
			if (utilpointer->index > utilpointer->next->index)
				return (1);
		utilpointer = utilpointer->next;
	}
	return (0);
}
