/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:59:47 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/26 12:47:54 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

static void	ft_instruction(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		ft_sa(stack_a);
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		ft_pa(stack_a, stack_b);
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		ft_ra(stack_a);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		ft_rra(stack_a);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		ft_sb(stack_b);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		ft_pb(stack_b, stack_a);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		ft_rb(stack_b);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		ft_rrb(stack_b);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		ft_ss(stack_a, stack_b);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		ft_rr(stack_a, stack_b);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		ft_rrr(stack_a, stack_b);
	else
		ft_perror("Error", *stack_a, *stack_b);
}

static void	ft_check_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		ft_instruction(line, stack_a, stack_b);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (ft_is_stack_sorted(*stack_a) == false)
		ft_perror("KO", *stack_a, *stack_b);
	ft_printf("OK\n");
	ft_annihilation(*stack_a);
	ft_annihilation(*stack_b);
}

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
	ft_check_instructions(&stack_a, &stack_b);
}
