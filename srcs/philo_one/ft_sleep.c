/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:54:25 by selgrabl          #+#    #+#             */
/*   Updated: 2020/09/29 14:54:26 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    ft_sleep(struct timeval t_start, int end)
{
        struct timeval now;

        gettimeofday(&now, NULL);
        now = diff_time(t_start, now);
        while ((int)(now.tv_sec * 1000000  + now.tv_usec) < end)
        {
                gettimeofday(&now, NULL);
                now = diff_time(t_start, now);
                usleep(50);
        }
}
