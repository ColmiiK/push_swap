/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:59:47 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/19 18:27:36 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (1);
	if (ac == 2 && !av[1][0])
		ft_perror("Error", stack_a, stack_b);
	ft_parse_av(av, &stack_a, &stack_b);
	if (ft_is_stack_sorted(stack_a) == false)
	{
		if (ft_stack_len(stack_a) == 2)
			ft_sa(&stack_a);
		else if (ft_stack_len(stack_a) == 3)
			ft_sort_three(&stack_a);
		else
			ft_sort_stacks(&stack_a, &stack_b);
	}
	ft_annihilation(stack_a);
	ft_annihilation(stack_b);
}
