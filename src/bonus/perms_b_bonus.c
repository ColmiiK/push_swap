/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perms_b_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:55:57 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/18 17:23:08 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_rrotate(stack_b);
}
