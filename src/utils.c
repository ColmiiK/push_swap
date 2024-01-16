/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:25:28 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/16 14:05:59 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_perror(char *s)
{
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

bool	ft_is_stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (false);
	while (stack->next)
	{
		if (stack->n > stack->next->n)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	ft_sort_three(t_stack **stack)
{
	t_stack *big;

	big = ft_find_big(*stack);
	if (big == *stack)
		ft_ra(stack);
	else if ((*stack)->next == big)
		ft_rra(stack);
	if ((*stack)->n > (*stack)->next->n)
		ft_sa(stack);
}

t_stack	*ft_find_big(t_stack *stack)
{
	t_stack *big;
	t_stack *current;

	current = stack->next;
	big = stack;
	while (current != NULL)
	{
		if (current->n > big->n)
			big = current;
		current = current->next;
	}

	return (big);
}

int	ft_stack_len(t_stack *stack)
{
	int len;
	t_stack *current;

	len = 0;
	current = stack;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}
