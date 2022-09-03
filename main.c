/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:28:41 by seyeo             #+#    #+#             */
/*   Updated: 2022/09/03 21:50:16 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_philo	*philo;
	int		error_num;

	if (argc != 5 && argc != 6)
		return (print_error("argc error", 3));
	memset(&arg, 0, sizeof(t_arg));
}
