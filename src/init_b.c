/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:56:26 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/17 11:23:54 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_set_b_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*target;
	long	best;

	while (stack_b)
	{
		best = LONG_MAX;
		current = stack_a;
		while (current)
		{
			if (current->n > stack_b->n && current->n < best)
			{
				best = current->n;
				target = current;
			}
			current = current->next;
		}
		if (best == LONG_MAX)
			stack_b->target_node = ft_find_min(stack_a);
		else
			stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}

void	ft_init_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	ft_index(stack_a);
	ft_index(stack_b);
	ft_set_b_target(stack_a, stack_b);
}
