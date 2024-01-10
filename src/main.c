/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:59:47 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/10 17:05:29 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


/*	INSTRUCTIONS:
	
	TODO:
	calculate where all those numbers should be, the correct position in the stack
	
	DONE:
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
	parse numbers in command line, both when they are separated (1 2 3) and when they're bound by commas ("1 2 3")
	get those numbers in a linked list (1->2->3)
	

	INPUT:
	./push_swap 3 2 1 4 -2 0
	./push_swap "3 2 1 4 -2 0"
	./push_swap "3 2" 1 4 "-2 0"
	
*/

void print_stacks_side_by_side(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *current_a = stack_a;
    t_stack *current_b = stack_b;

    ft_printf("Stack A | Stack B\n");
    ft_printf("--------|--------\n");

    while (current_a != NULL || current_b != NULL) {
        if (current_a != NULL) {
            ft_printf("%d \t| ", current_a->n);
            current_a = current_a->next;
        } else {
            ft_printf("\t| ");
        }

        if (current_b != NULL) {
            ft_printf("%d\n", current_b->n);
            current_b = current_b->next;
        } else {
            ft_printf("\n");
        }
    }
	ft_printf("\n");
}

void debug_print(t_stack *stack_a, t_stack *stack_b)
{
    ft_printf("BEFORE MOVE:\n");
    print_stacks_side_by_side(stack_a, stack_b);

    ft_rrotate(&stack_a);
	ft_rotate(&stack_a);


    ft_printf("AFTER MOVE:\n");
    print_stacks_side_by_side(stack_a, stack_b);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		ft_perror("Error");
	ft_parse_av(av, &stack_a);
	
	debug_print(stack_a, stack_b);

}
