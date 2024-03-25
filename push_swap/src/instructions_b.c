/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions_b.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchahmi <kchahmi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/17 18:12:10 by kchahmi       #+#    #+#                 */
/*   Updated: 2024/03/20 18:46:39 by kchahmi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_node **stack_b)
{
	if (stack_b == NULL)
		return ;
	swap(*stack_b);
	ft_printf("sb\n");
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

long	ft_atol(const char *str)
{
	long	i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
