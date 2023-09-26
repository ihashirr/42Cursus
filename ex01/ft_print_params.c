/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:26:20 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/14 11:27:24 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	y_axis;

	i = 1;
	while (ac > i)
	{
		y_axis = 0;
		while (av[i][y_axis] != '\0')
		{
			write(1, &av[i][y_axis], 1);
			y_axis++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
