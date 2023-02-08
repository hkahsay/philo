/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:38:43 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/08 12:42:45 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

int main(int argc, char **argv)
{
    t_info  *philo;

    philo = malloc(sizeof(t_info));
    parsing(argc, argv, philo);
    create_threads(philo);
    return (0);
}
