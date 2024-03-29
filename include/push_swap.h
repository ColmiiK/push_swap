/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:57:17 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/22 13:21:46 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*target_node;
	int				n;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
}					t_stack;
// Error checking & cleanup
void	ft_perror(char *s, t_stack *stack_a, t_stack *stack_b);
void	ft_perror_joined(char *s, t_stack *stack_a,
			t_stack *stack_b, char *joined);
void	ft_perror_node(t_stack *node, char *s);
void	ft_annihilation(t_stack *stack);
// Parsing
void	ft_parse_av(char **av, t_stack **stack_a, t_stack **stack_b);
// Sorting & utils
bool	ft_is_stack_sorted(t_stack *stack);
void	ft_sort_three(t_stack **stack);
void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_find_big(t_stack *stack);
t_stack	*ft_find_min(t_stack *stack);
int		ft_stack_len(t_stack *stack);
void	ft_index(t_stack *stack);
void	ft_init_stack_a(t_stack *stack_a, t_stack *stack_b);
void	ft_init_stack_b(t_stack *stack_a, t_stack *stack_b);
void	ft_min_on_top(t_stack **stack_a);
void	ft_prepare_push(t_stack **stack, t_stack *top, char c);
t_stack	*ft_find_cheapest(t_stack *stack);
bool	ft_check_big_ordered(t_stack *stack);
// Movements
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **dest, t_stack **src);
void	ft_rotate(t_stack **stack);
void	ft_rrotate(t_stack **stack);
void	ft_sa(t_stack **stack_a);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rra(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_pb(t_stack **stack_b, t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rrb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheap);
void	ft_rrotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheap);

#endif
