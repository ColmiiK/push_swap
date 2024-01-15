/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:07:45 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/15 17:40:41 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void print_targets_and_costs(t_stack *stack_a)
{
	t_stack *current = stack_a;
	while (current != NULL)
	{	
		if (current->target_node != NULL)
			printf("Node %d target is %d, push cost is %d\n", current->n, current->target_node->n, current->push_cost);
		else
			printf("Node %d has no target, push cost is %d\n", current->n, current->push_cost);
		if (current->cheapest == true)
			printf("\t*NODE %d IS THE CHEAPEST NODE AVALIABLE*\n", current->n);
		current = current->next;
	}
}

void ft_set_a_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current;
	t_stack *target;
	int best;

	while (stack_a)
	{
		best = INT_MIN;
		current = stack_b;
		while (current)
		{
			if (current->n < stack_a->n && current->n > best)
			{
				best = current->n;
				target = current;
			}
			current = current->next;
		}
		if (best == INT_MIN)
			stack_a->target_node = ft_find_big(stack_b);
		else
			stack_a->target_node = target;
		stack_a = stack_a->next;
	}
}

void ft_cost(t_stack *stack_a, t_stack *stack_b)
{
	int len_a;
	int len_b;

	len_a = ft_stack_len(stack_a);
	len_b = ft_stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void ft_find_cheapest(t_stack *stack)
{
	int cheap_value;
	t_stack *cheap_node;

	if (!stack)
		return ;
	cheap_value = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheap_value)
		{
			cheap_value = stack->push_cost;
			cheap_node = stack;
		}
		stack = stack->next;
	}
	cheap_node->cheapest = true;
}

void ft_init_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_index(stack_a);
	ft_index(stack_b);
	ft_set_a_target(stack_a, stack_b);
	ft_cost(stack_a, stack_b);
	ft_find_cheapest(stack_a);
	// print_targets_and_costs(stack_a);
	
}