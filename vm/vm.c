/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:10:45 by rthys             #+#    #+#             */
/*   Updated: 2018/03/05 13:41:19 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		init_env(t_env *env)
{
	env->cycles = 0;
	env->lives = 0;
	env->dump = 0;
	env->checks = 0;
}

int		main(int  ac, char **av)
{
	t_env *env;

	if ((!(env = (t_env *)malloc(sizeof(t_env))) || (!init_env(env))))
		return (0);
	if (ac < 

}
