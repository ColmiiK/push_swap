/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:56:11 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/16 18:53:51 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	ft_prepare_push(stack_a, (*stack_b)->target_node, 'a');
	ft_pa(stack_a, stack_b);
}
