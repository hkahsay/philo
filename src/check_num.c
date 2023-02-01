/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:15:26 by hkahsay           #+#    #+#             */
/*   Updated: 2023/01/31 18:43:38 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

int	is_blank(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (is_blank(*str))
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str++ - 48;
	}
	return (nb * sign);
}

long	ft_atoi_long(char *str)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (is_blank(*str))
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str++ - 48;
	}
	return ((int)nb * sign);
}

int	is_num_l(char	*str)
{
	long int	nbr;

	while (*str)
	{
		if (*str >= '0' && *str < '9')
			str++;
		else
			return (0);
	}
	nbr = ft_atoi_long(str);
	if (nbr > MAX_INT && nbr < MIN_INT)
	{
		printf(RED"ERRtOR\n");
		return (0);
	}
	return (1);
}
