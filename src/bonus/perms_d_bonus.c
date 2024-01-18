/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perms_d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:57:32 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/18 17:23:11 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
}
