/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perms_a_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:47:23 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/18 17:23:21 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
}

void	ft_rra(t_stack **stack_a)
{
	ft_rrotate(stack_a);
}
