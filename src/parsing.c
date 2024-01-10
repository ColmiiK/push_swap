/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:24:20 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/10 12:36:16 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_check_list(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->n == check->n)
				ft_perror("Error");
			check = check->next;
		}
		current = current->next;
	}
}

static void	ft_add_to_list(t_stack **stack, char *token)
{
	t_stack	*new;
	t_stack	*current;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_perror("Error");
	new->n = ft_atoi(token);
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	ft_parse_av(char **av, t_stack **stack)
{
	char	*joined;
	char	*token;
	int		i;

	joined = ft_calloc(1, 1);
	i = 0;
	while (av[++i])
	{
		joined = ft_strjoin(joined, av[i]);
		joined[ft_strlen(joined)] = ' ';
	}
	i = -1;
	while (joined[++i])
	{
		if (!((joined[i] >= '0' && joined[i] <= '9')
				|| joined[i] == ' '))
			ft_perror("Error");
	}
	token = ft_strtok(joined, " ");
	while (token)
	{
		ft_add_to_list(stack, token);
		token = ft_strtok(NULL, " ");
	}
	ft_check_list(*stack);
}
