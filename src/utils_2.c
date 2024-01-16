/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:33:28 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/16 12:33:55 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
