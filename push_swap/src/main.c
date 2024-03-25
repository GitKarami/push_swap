/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchahmi <kchahmi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 12:37:11 by kchahmi       #+#    #+#                 */
/*   Updated: 2024/03/25 14:52:41 by kchahmi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	argv++;
	if (valid(argc, argv))
		return (0);
	stack_a = malloc(sizeof(t_node *));
	stack_b = malloc(sizeof(t_node *));
	create_stack(stack_a, argc, argv);
	if (duplicate_checker(stack_a))
		return (ft_free(stack_a), ft_free(stack_b), 0);
	if (check_if_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	//print_list(stack_a);
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}
