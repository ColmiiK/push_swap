/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:25:03 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/16 18:57:47 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_stack_len(*stack_a);
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
