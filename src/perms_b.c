/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perms_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:55:57 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/10 19:06:04 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("pb\n");
}

void ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void ft_rrb(t_stack **stack_b)
{
	ft_rrotate(stack_b);
	ft_printf("rrb\n");
}
