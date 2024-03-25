/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kchahmi <kchahmi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 13:20:31 by kchahmi       #+#    #+#                 */
/*   Updated: 2024/03/20 18:46:26 by kchahmi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct node
{
	int			value;
	int			index;
	struct node	*next;
}	t_node;

void	sort_stack(t_node **stack_a, t_node **stack_b);
void	radix_sort(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack_a);

void	ft_free(t_node **stack);
void	error_handler(int num);
int		duplicate_checker(t_node **stack_a);
int		valid_arg(char *argv);
int		valid(int argc, char **argv);
void	print_list(t_node **stack);
long	ft_atol(const char *str);
int		check_if_sorted(t_node **stack);

void	create_stack(t_node **stack, int argc, char **argv);

void	swap(t_node *stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	push(t_node **src, t_node **dest);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	reverse_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

t_node	*get_stack_bottom(t_node *stack);
t_node	*get_stack_before_bottom(t_node *stack);
t_node	*create_node(int value);
int		get_stack_size(t_node *stack);
t_node	*find_lowest(t_node **stack);
void	set_index(t_node **stack);

#endif