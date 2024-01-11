/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:59:47 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/11 16:10:27 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


/*	INSTRUCTIONS:
	
	COST ANALYSIS:
	Every 'a' node needs a target node from stack 'b'
	The target node will be the closest smaller number to the 'a' node
	If no closest smaller number is found, then the target node will be the max value
	sum(operations to bring 'a' to top + operations to bring 'a->target node' on top)
	after each push, we re-evaluate the costs and choose the cheapest move
	
	SORT THREE:
	Ensure biggest number is last
	Perform sa if needed
	

	FLOW:
	If stack a is bigger than 3: push 2 numbers to stack b
	Until stack a is equal to 3: calculate costs and perform cheapest move from stack a to stack b, repeat until there are 3 nodes left in a
	Sort those three nodes
	Push all nodes in stack b to stack a: calculate costs and perform cheapest move from stack b to stack a
	Rotate or reverse rotate to take the smallest node to the top

	
	TODO:
	Utility functions:
		-Find stack lenght
		-Find the last node
		-Find the min and the max node


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

void debug_print(t_stack **stack_a, t_stack **stack_b)
{
    ft_printf("BEFORE MOVE:\n");
    print_stacks_side_by_side(*stack_a, *stack_b);

	if (ft_is_stack_sorted(*stack_a) == false)
	{
		ft_printf("STACK IS NOT SORTED\n");
		if (ft_stack_len(*stack_a) == 2)
			ft_sa(stack_a);
		else if (ft_stack_len(*stack_a) == 3)
			ft_sort_three(stack_a);
	}
	else
		ft_printf("STACK IS SORTED\n");

    ft_printf("\nAFTER MOVE:\n");
    print_stacks_side_by_side(*stack_a, *stack_b);
}

void leaks()
{
	system("leaks -q push_swap");
}

void ft_annihilation(t_stack *stack)
{
	t_stack *current;
	t_stack *next;
	
	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    
    // atexit(leaks);
    stack_a = NULL;
    stack_b = NULL;
    if (ac < 2)
        ft_perror("Error");
    ft_parse_av(av, &stack_a);
    
    
    debug_print(&stack_a, &stack_b);
    
    ft_annihilation(stack_a);
    ft_annihilation(stack_b);
}
