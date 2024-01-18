/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:55 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/18 17:59:42 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <libft.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				n;

}					t_stack;
// Error checking & cleanup
void	ft_perror(char *s);
void	ft_annihilation(t_stack *stack);
// Parsing
void	ft_parse_av(char **av, t_stack **stack);
// Sorting & utils
bool	ft_is_stack_sorted(t_stack *stack);
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

#endif
