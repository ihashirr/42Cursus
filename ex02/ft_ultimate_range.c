/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 07:08:08 by mhashir           #+#    #+#             */
/*   Updated: 2023/03/15 10:02:33 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		len;
	int		i;

	i = 0;
	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	*range = (int *)malloc(sizeof(int) * len);
	if (!*range)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (i);
}
/*#include <stdio.h>
int main(void)
{   
    int *p[5];
    int i =0;
    int n;
    n = ft_ultimate_range(p,5,10);
    printf("length is : %d\n",n);
    while (p[0][i] != 0)
    {
        printf("%d\n",p[0][i]);
        i++;
    }
    free(p[0]);
    return (0);
}*/
