/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:24:20 by alvega-g          #+#    #+#             */
/*   Updated: 2024/01/19 18:34:45 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_check_list(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*check;

	current = stack_a;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->n == check->n)
				ft_perror("Error", stack_a, stack_b);
			check = check->next;
		}
		current = current->next;
	}
}

static void	ft_compare(char *token, char *temp,
	t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(token, temp, ft_strlen(token)))
	{
		free(temp);
		ft_perror("Error", stack_a, stack_b);
	}
}

static void	ft_add_to_list(char *token, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;
	t_stack	*current;
	char	*temp;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_perror("Error", *stack_a, *stack_b);
	if (token[0] == '+')
		token++;
	new->n = ft_atoi(token);
	temp = ft_itoa(new->n);
	ft_compare(token, temp, *stack_a, *stack_b);
	free(temp);
	new->next = NULL;
	if (*stack_a == NULL)
		*stack_a = new;
	else
	{
		current = *stack_a;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

static bool	ft_check_token(char *token)
{
	int	i;

	i = -1;
	while (token[++i])
	{
		if ((token[i] == '-' && !ft_isdigit(token[i + 1]))
			|| (token[i] == '+' && !ft_isdigit(token[i + 1])))
			return (false);
		if (token[i] == '-' || token[i] == '+')
			i++;
		if (!ft_isdigit(token[i]))
			return (false);
	}
	return (true);
}

void	ft_parse_av(char **av, t_stack **stack_a, t_stack **stack_b)
{
	char	*joined;
	char	*temp;
	char	*token;
	int		i;

	joined = ft_calloc(1, 1);
	i = 0;
	while (av[++i])
	{
		temp = ft_strjoin(joined, " ");
		free(joined);
		joined = ft_strjoin(temp, av[i]);
		free(temp);
	}
	token = ft_strtok(joined, " ");
	while (token)
	{
		if (ft_check_token(token) == false)
			ft_perror("Error", *stack_a, *stack_b);
		ft_add_to_list(token, stack_a, stack_b);
		token = ft_strtok(NULL, " \t");
	}
	free(joined);
	ft_check_list(*stack_a, *stack_b);
}
