/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:33:28 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/18 13:02:54 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*ft_find_min(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->n < smallest)
		{
			smallest = stack->n;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	ft_min_on_top(t_stack **stack_a)
{
	while ((*stack_a) != ft_find_min(*stack_a))
	{
		if (ft_find_min(*stack_a)->above_median)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while (*stack_b != cheap->target_node && *stack_a != cheap)
		ft_rr(stack_a, stack_b);
	ft_index(*stack_a);
	ft_index(*stack_b);
}

void	ft_rrotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while (*stack_b != cheap->target_node && *stack_a != cheap)
		ft_rrr(stack_a, stack_b);
	ft_index(*stack_a);
	ft_index(*stack_b);
}

void	ft_index(t_stack *stack)
{
	int	i;
	int	median;

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
