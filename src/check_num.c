/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:15:26 by hkahsay           #+#    #+#             */
/*   Updated: 2023/03/09 16:06:48 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

int	is_blank(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long	ft_atoi_long(char *str)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (is_blank(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str++ - 48;
	}
	if (nb > MAX_INT || nb < MIN_INT || nb < 0)
	{
		printf(RED"ERROR\n");
		exit(0);
		printf("%ld\n", nb);
		return (0);
	}
	return ((int)nb * sign);
}

int	is_num_l(char	*str)
{
	long int	nb;

	while (*str)
	{
		if (*str >= '0' && *str <='9')
			str++;
		else
			return (0);
	}
	nb = ft_atoi_long(str);
	return (1);
}
