/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:06:04 by seyeo             #+#    #+#             */
/*   Updated: 2022/09/05 00:07:00 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread(void *argv)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = argv;
	arg = philo->arg;
	if (philo->id % 2)
		usleep(1000);
	else
		usleep(500);
	while (!arg->finish)
	{
		ft_philo_action(arg, philo); // 여기부터
		if (arg->eat_times == philo->eat_count)
		{
			arg->finished_eat++;
			break ;
		}
		ft_print_philo(arg, philo->id, "is sleeping");
		ft_pass_time((long long)arg->time_to_sleep, arg);
		ft_print_philo(arg, philo->id, "is thinking");
	}
}

int	ft_start_philo(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < arg->philo_num)
	{
		philo[i].last_eat_time = ft_get_time();
		if (pthread_create(&(philo[i].thread), NULL, ft_thread, &(philo[i])))
			return (1);
		i++;
	}
}
