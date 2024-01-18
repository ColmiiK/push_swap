/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:33:46 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/18 17:36:05 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*ft_find_cheapest(t_stack *stack)
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

void	ft_prepare_push(t_stack **stack, t_stack *top, char c)
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

bool	ft_check_big_ordered(t_stack *stack)
{
	if (stack == ft_find_big(stack))
	{
		stack = stack->next;
		if (ft_is_stack_sorted(stack) == true)
			return (true);
	}
	return (false);
}
