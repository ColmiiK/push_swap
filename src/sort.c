/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:25:03 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/18 17:35:54 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	ft_prepare_push(stack_a, (*stack_b)->target_node, 'a');
	ft_pa(stack_a, stack_b);
}

static void	ft_move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_find_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		ft_rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		ft_rrotate_both(stack_a, stack_b, cheapest_node);
	ft_prepare_push(stack_a, cheapest_node, 'a');
	ft_prepare_push(stack_b, cheapest_node->target_node, 'b');
	ft_pb(stack_b, stack_a);
}

void	ft_sort_three(t_stack **stack)
{
	t_stack	*big;

	big = ft_find_big(*stack);
	if (big == *stack)
		ft_ra(stack);
	else if ((*stack)->next == big)
		ft_rra(stack);
	if ((*stack)->n > (*stack)->next->n)
		ft_sa(stack);
}

void	ft_set_all_nodes(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		stack->cheapest = false;
		stack = stack->next;
	}
}

void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	ft_set_all_nodes(*stack_a);
	len = ft_stack_len(*stack_a);
	if (ft_check_big_ordered(*stack_a) == true)
		ft_ra(stack_a);
	if (len-- > 3 && !ft_is_stack_sorted(*stack_a))
		ft_pb(stack_b, stack_a);
	if (len-- > 3 && !ft_is_stack_sorted(*stack_a))
		ft_pb(stack_b, stack_a);
	while (len-- > 3 && !ft_is_stack_sorted(*stack_a))
	{
		ft_init_stack_a(*stack_a, *stack_b);
		ft_move_a_to_b(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_init_stack_b(*stack_a, *stack_b);
		ft_move_b_to_a(stack_a, stack_b);
	}
	ft_index(*stack_a);
	ft_min_on_top(stack_a);
}
