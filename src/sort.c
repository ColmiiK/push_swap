/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:25:03 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/15 17:19:01 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
	Push twice to stack b
	If stack a is still greater than 3, calculate cheapest number to move and move it closest to its target pushing to stack b
	Repeat until stack a has 3 numbers remaining, and then sort those 3 numbers
	Calculate cheapest number to move from b to a and push it to a
	Repeat until stack b is empty
	Rotate or reverse rotate stack a until the smallest number is on top
	
*/

t_stack *ft_find_min(t_stack *stack)
{
	t_stack *small;
	t_stack *current;

	current = stack->next;
	small = stack;
	while (current != NULL)
	{
		if (current->n < small->n)
			small = current;
		current = current->next;
	}
	return (small);
}

void ft_min_on_top(t_stack **stack_a)
{
	while ((*stack_a)!= ft_find_min(*stack_a))
	{
		if (ft_find_min(*stack_a)->above_median)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}

void ft_index(t_stack *stack)
{
	int i;
	int median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int len;

	len = ft_stack_len(*stack_a);
	if (len-- > 3 && !ft_is_stack_sorted(*stack_a))
		ft_pb(stack_b, stack_a);
	if (len-- > 3 && !ft_is_stack_sorted(*stack_a))
		ft_pb(stack_b, stack_a);
	while (len-- > 3 && !ft_is_stack_sorted(*stack_a))
	{
			ft_init_stack_a(*stack_a, *stack_b);
			// ft_move_a_to_b(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	// while (*stack_b)
	// {
	// 	ft_init_stack_b(*stack_a, *stack_b);
	// 	ft_move_b_to_a(stack_a, stack_b);
	// }
	ft_index(*stack_a);
	ft_min_on_top(stack_a);
}
