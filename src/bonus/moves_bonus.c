/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:08:44 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/18 17:23:01 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

void	ft_swap(t_stack **stack)
{
	int	temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	first->next = NULL;
}

void	ft_rrotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = *stack;
	*stack = last;
}
