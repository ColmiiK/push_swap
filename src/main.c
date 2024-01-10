/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:59:47 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/10 15:53:24 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


/*	INSTRUCTIONS:
	sa -> swap the first and second numbers of stack a
	sb -> swap the first and second numbers of stack b
	ss -> perform sa and sb at the same time
	pa -> push the first number of stack b to stack a
	pb -> push the first number of stack a to stack b
	ra -> move up all numbers in stack a, making the first number the last one
	rb -> move up all numbers in stack b, making the first number the last one
	rr -> perform ra and rb at the same time
	rra -> inverse of ra
	rrb -> inverse of rb
	rrr -> perform rra and rrb at the same time
	
	TODO:
	parse numbers in command line, both when they are separated (1 2 3) and when they're bound by commas ("1 2 3")
	get those numbers in a linked list (1->2->3)
	calculate where all those numbers should be, the correct position in the stack
	
	INPUT:
	./push_swap 3 2 1 4 -2 0
	./push_swap "3 2 1 4 -2 0"
	./push_swap "3 2" 1 4 "-2 0"
	
*/

void debug_print(t_stack *stack) {
    t_stack *current = stack;

    while (current != NULL) {
       	ft_printf("%d\n", current->n);
        current = current->next;
    }
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	// t_stack *stack_b;
	
	stack_a = NULL;
	// stack_b = NULL;
	if (ac < 2)
		ft_perror("Error");
	ft_parse_av(av, &stack_a);

	debug_print(stack_a);
}
