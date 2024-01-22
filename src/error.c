/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:14:11 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/22 13:15:26 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_perror(char *s, t_stack *stack_a, t_stack *stack_b)
{
	ft_putendl_fd(s, STDERR_FILENO);
	ft_annihilation(stack_a);
	ft_annihilation(stack_b);
	exit(EXIT_FAILURE);
}

void	ft_perror_joined(char *s, t_stack *stack_a,
	t_stack *stack_b, char *joined)
{
	ft_putendl_fd(s, STDERR_FILENO);
	free(joined);
	ft_annihilation(stack_a);
	ft_annihilation(stack_b);
	exit(EXIT_FAILURE);
}

void	ft_perror_node(t_stack *node, char *s)
{
	free(node);
	free(s);
	exit(EXIT_FAILURE);
}

void	ft_annihilation(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
