/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:29:03 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/06/23 09:26:42 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !ft_is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (size == 3 && !ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	else if (size > 3 && !ft_is_sorted(*stack_a))
		ft_sort(stack_a, stack_b);
}

void	free_arr(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	main(int c, char **args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;

	str = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (c > 1)
	{
		str = ft_parsing_stack(args);
		ft_parsing(str);
		ft_fill_stack(str, &stack_a);
		free_arr(str);
		ft_index_stack(stack_a, ft_size(stack_a));
		ft_push_swap(&stack_a, &stack_b, ft_size(stack_a));
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
	}
	return (0);
}

// ARG=$(shuf -i 1-1000 -n 500 | xargs); ./push_swap $ARG | ./checker_linux $ARG && ./push_swap $ARG | wc -l
