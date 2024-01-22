/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:25:28 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/22 13:15:06 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

t_stack	*ft_find_big(t_stack *stack)
{
	long	biggest;
	t_stack	*biggest_node;

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (stack->n > biggest)
		{
			biggest = stack->n;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

int	ft_stack_len(t_stack *stack)
{
	int		len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}
