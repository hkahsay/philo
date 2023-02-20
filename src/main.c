/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:38:43 by hkahsay           #+#    #+#             */
/*   Updated: 2023/02/19 07:42:49 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

// void test_ms_sleep()
// {
//     printf("%ld\n", actual_time_msec());
//     ms_sleep(200);
//     printf("%ld\n", actual_time_msec());
//     ms_sleep(400);
//     printf("%ld\n", actual_time_msec());
// }

// void test_elapsed_time(t_info  *info)
// {
//     set_philos(info);
//     printf("%ld\n", elapsed_time(info));
//     ms_sleep(200);
//     printf("%ld\n", elapsed_time(info));
// }

// void test_display_status(t_info  *info)
// {
//     set_philos(info);
//     display_status(elapsed_time(info), info->philo, "test after 0 ms");
//     ms_sleep(200);
//     display_status(elapsed_time(info), info->philo, "test after 200 ms");
// }

int main(int argc, char *argv[])
{
    t_info  *info;
    info = malloc(sizeof(t_info));
    parsing(argc, argv, info);
    create_threads(info);
    return (0);
}