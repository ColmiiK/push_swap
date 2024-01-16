/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:29:44 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/16 12:51:11 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack *ft_find_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void ft_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		ft_rr(stack_a, stack_b);
	ft_index(*stack_a);
	ft_index(*stack_b);
}

void ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		ft_rrr(stack_a, stack_b);
	ft_index(*stack_a);
	ft_index(*stack_b);
}

void ft_prepare_push(t_stack **stack, t_stack *top, char c)
{
	while (*stack != top)
	{
		if (c == 'a')
		{
			if (top->above_median)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (c == 'b')
		{
			if (top->above_median)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
}

void ft_move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest_node;

	cheapest_node = ft_find_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		ft_rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		ft_reverse_rotate_both(stack_a, stack_b, cheapest_node);
	ft_prepare_push(stack_a, cheapest_node, 'a');
	ft_prepare_push(stack_b, cheapest_node->target_node, 'b');
	ft_pb(stack_b, stack_a);
}