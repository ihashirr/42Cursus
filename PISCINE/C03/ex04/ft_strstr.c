/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:54:16 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/14 03:14:59 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int		x;
	unsigned int		y;

	x = 0;
	y = 0;
	if (to_find[x] == '\0')
	{
		return (str);
	}
	while (str[x] != '\0')
	{
		while (str[x + y] == to_find[y] && str[x + y] != '\0')
		{
			y++ ;
		}
		if (to_find[y] == '\0')
		{
			return (str + x);
		}
		x++ ;
		y = 0;
	}
	return (0);
}
