/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:10:45 by rthys             #+#    #+#             */
/*   Updated: 2018/03/05 14:48:25 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	add_champ(int rank, char *name)
{
	if (!open(name, O_RDONLY))
		/*FICHIER INEXISTANT*/
	else
	{
		
	}
	
}

static int	check_params(int ac, char **av, t_env *env)
{
	int i;
	int rank;

	i = 1;
	rank = 0;
	if (ac < 3)
		return (0);
	while (i < ac)
	{
		if (av[i] == '-')
		{
			if (ft_strequ(av[i], "-dump"))
				env->dump = ft_atoi(av[++i]);
			else if (ft_strequ(av[i], "-n"))
				rank = ft_atoi(av[++i]);
			else
				/*UNKNOWN OPTION*/
		}
		else
			add_champ(rank, av[i]);
		i++;
	}
}

int			init_env(t_env *env)
{
	env->cycles = 0;
	env->lives = 0;
	env->dump = 0;
	env->checks = 0;
}

int			main(int  ac, char **av)
{
	t_env *env;

	if ((!(env = (t_env *)malloc(sizeof(t_env))) || (!init_env(env))))
		return (0);
	*env = {0, 0, 0, 0, 0};
	init_env(env);


}
