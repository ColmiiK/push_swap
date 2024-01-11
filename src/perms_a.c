/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perms_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:47:23 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/11 10:37:54 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rra(t_stack **stack_a)
{
	ft_rrotate(stack_a);
	ft_printf("rra\n");
}
