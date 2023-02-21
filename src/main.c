/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:38:43 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/21 16:09:33 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

int main(int argc, char **argv)
{
    t_info  *info;

    info = malloc(sizeof(t_info));
    parsing(argc, argv, info);
    create_threads(info);
    return (0);
}
