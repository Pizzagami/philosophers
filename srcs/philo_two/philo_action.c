/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:54:25 by selgrabl          #+#    #+#             */
/*   Updated: 2020/09/29 14:54:26 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		get_fork(t_philo *philo, t_timeval t_start)
{
	sem_wait(philo->mutext);
	sem_wait(philo->output);
	display(t_start, philo->number, "has taken a fork");
	sem_post(philo->output);
	sem_wait(philo->mutext);
	sem_wait(philo->output);
	display(t_start, philo->number, "has taken a fork");
	sem_post(philo->output);
}

void		release_fork(t_philo *philo)
{
	sem_post(philo->mutext);
	sem_post(philo->mutext);
}

void		eat(t_philo *philo, t_timeval t_start)
{
	struct timeval t_start_action;

	gettimeofday(&t_start_action, NULL);
	sem_wait(philo->output);
	display(t_start, philo->number, "is eating");
	sem_post(philo->output);
	ft_sleep(t_start_action, philo->time_to_eat);
}

void		psleep(t_philo *philo, t_timeval t_start)
{
	struct timeval t_start_action;

	gettimeofday(&t_start_action, NULL);
	sem_wait(philo->output);
	display(t_start, philo->number, "is sleeping");
	sem_post(philo->output);
	ft_sleep(t_start_action, philo->time_to_sleep);
	sem_wait(philo->output);
	display(t_start, philo->number, "is thinking");
	sem_post(philo->output);
}
