/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <seyeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:54:34 by seyeo             #+#    #+#             */
/*   Updated: 2022/09/05 19:36:57 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_pass(long long time_to_eat, t_arg *arg)
{
	long long	start;
	long long	now;

	start = ft_get_time();
	while (!(arg->finish))
	{
		now = ft_get_time();
		if ((now - start) >= time_to_eat)
			break ;
		usleep(10);
	}
}

int	ft_philo_action(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left]));
	ft_print_philo(arg, philo->id, "has taken a fork");
	if (arg->philo_num != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->right]));
		ft_print_philo(arg, philo->id, "has taken a fork");
		ft_print_philo(arg, philo->id, "is eating");
		philo->last_eat_time = ft_get_time();
		philo->eat_count++;
		ft_pass((long long)arg->time_to_eat, arg);
		pthread_mutex_unlock(&(arg->forks[philo->right]));
	}
	pthread_mutex_unlock(&(arg->forks[philo->left]));
	return (0);
}

int	ft_print_philo(t_arg *arg, int id, char *str)
{
	long long	now;

	now = ft_get_time();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(arg->print));
	if (!(arg->finish))
		printf("%lld %d %s\n", now - arg->start_time, id + 1, str);
	pthread_mutex_unlock(&(arg->print));
	return (0);
}
