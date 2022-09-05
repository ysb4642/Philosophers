/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <seyeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:28:41 by seyeo             #+#    #+#             */
/*   Updated: 2022/09/05 19:21:00 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_philo	*philo;
	int		error_num;

	if (!(argc == 5 || argc == 6))
		return (print_error("argc error", 3));
	memset(&arg, 0, sizeof(t_arg));
	error_num = ft_init_arg(&arg, argc, argv);
	if (error_num)
		return (print_error("arg init error", error_num));
	error_num = ft_init_philo(&philo, &arg);
	if (error_num)
		return (print_error("philo init error", error_num));
	error_num = ft_start_philo(&arg, philo);
	if (error_num)
		return (print_error("philo start error", error_num));
	return (0);
}
