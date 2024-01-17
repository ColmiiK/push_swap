/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:59:47 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/17 11:36:10 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// void print_stacks(t_stack *stack_a, t_stack *stack_b)
// {
//     t_stack *current_a = stack_a;
//     t_stack *current_b = stack_b;

//     ft_printf("Stack A | Stack B\n");
//     ft_printf("--------|--------\n");

//     while (current_a != NULL || current_b != NULL) {
//         if (current_a != NULL) {
//             ft_printf("%d \t| ", current_a->n);
//             current_a = current_a->next;
//         } else {
//             ft_printf("\t| ");
//         }
//         if (current_b != NULL) {
//             ft_printf("%d\n", current_b->n);
//             current_b = current_b->next;
//         } else {
//             ft_printf("\n");
//         }
//     }
// 	ft_printf("\n");
// }

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (1);
	if (ac == 2 && !av[1][0])
		ft_perror("Error");
	ft_parse_av(av, &stack_a);
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
