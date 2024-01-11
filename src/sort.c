/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:25:03 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/11 19:47:02 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack *ft_find_small(t_stack *stack)
{
	t_stack *small;
	t_stack *current;

	current = stack->next;
	small = stack;
	while (current != NULL)
	{
		if (current->n > small->n)
			small = current;
		current = current->next;
	}

	return (small);
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

void ft_set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current;
	t_stack *target;
	long best;

	while (stack_a)
	{
		best = LONG_MIN;
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
		if (best == LONG_MIN)
			stack_a->target_node = ft_find_big(stack_b);
		else
			stack_a->target_node = target;
		stack_a = stack_a->next;
	}
}

void ft_set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current;
	t_stack *target;
	long best;

	while (stack_b)
	{
		best = LONG_MAX;
		current = stack_a;
		while (current)
		{
			if (current->n < stack_b->n && current->n > best)
			{
				best = current->n;
				target = current;
			}
			current = current->next;
		}
		if (best == LONG_MAX)
			stack_b->target_node = ft_find_small(stack_b);
		else
			stack_b->target_node = target;
		stack_b = stack_b->next;
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
		stack_a->cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->cost = len_a - stack_a->index;
		if (!(stack_a->target_node->above_median))
			stack_a->push_cost += len_a - stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - stack_a->target_node->index;
		stack_a = stack_a->next;
	}
}

void ft_set_cheapest(t_stack *stack)
{
	long cheapest_value;
	t_stack *temp;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			temp = stack;
		}
		stack = stack->next;
	}
	temp->cheapest = true;
}

void ft_prepare_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_index(stack_a);
	ft_index(stack_b);
	ft_set_target_a(stack_a, stack_b);
	ft_cost(stack_a, stack_b);
	ft_set_cheapest(stack_a);
}

void ft_prepare_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	ft_index(stack_a);
	ft_index(stack_b);
	ft_set_target_b(stack_a, stack_b);
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

t_stack *ft_get_cheapest(t_stack *stack)
{
	if (!stack)
		return NULL;
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void ft_move_from_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheap;
	
	cheap = ft_get_cheapest(*stack_a);
	if (cheap->above_median && cheap->target_node->above_median)
		ft_rr(stack_a, stack_b);
	else if (!(cheap->above_median) && !(cheap->target_node->above_median))
		ft_rrr(stack_a, stack_b);
	ft_prepare_push(stack_a, cheap, 'a');
	ft_prepare_push(stack_b, cheap, 'b');
	ft_pb(stack_b, stack_a);
	
}

void ft_move_from_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_prepare_push(stack_a, (*stack_b)->target_node, 'a');
	ft_pa(stack_a, stack_b);
}

void ft_smallest_on_top(t_stack **stack_a)
{
	while ((*stack_a)->n != ft_find_small(*stack_a)->n)
	{
		if (ft_find_small(*stack_a)->above_median)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}

void ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int len;

	len = ft_stack_len(*stack_a);
	if (len-- > 3 && ft_is_stack_sorted(*stack_a) == false)
		ft_pb(stack_b, stack_a);
	if (len-- > 3 && ft_is_stack_sorted(*stack_a) == false)
		ft_pb(stack_b, stack_a);
	while (len-- > 3 && ft_is_stack_sorted(*stack_a) == false)
	{
		ft_prepare_stack_a(*stack_a, *stack_b);
		ft_move_from_a(stack_a, stack_b); // <- TODO
	}
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_prepare_stack_b(*stack_b, *stack_a); // <- does this work??
		ft_move_from_b(stack_a, stack_b);
	}
	ft_index(*stack_a);
	ft_smallest_on_top(stack_a);
	
}
