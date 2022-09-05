/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <seyeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:28:55 by seyeo             #+#    #+#             */
/*   Updated: 2022/09/05 18:25:35 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				finish;
	int				finished_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_arg;

typedef struct s_philo
{
	struct s_arg	*arg;
	pthread_t		thread;
	int				id;
	int				left;
	int				right;
	long long		last_eat_time;
	int				eat_count;
}	t_philo;

int			print_error(char *str, int error_num);
int			ft_atoi(char *str);
long long	ft_get_time(void);
int			ft_init_arg(t_arg *arg, int argc, char *argv[]);
int			ft_init_philo(t_philo **philo, t_arg *arg);
int			ft_start_philo(t_arg *arg, t_philo *philo);
int			ft_print_philo(t_arg *arg, int id, char *str);
int			ft_philo_action(t_arg *arg, t_philo *philo);
void		ft_pass(long long time_to_eat, t_arg *arg);
#endif
