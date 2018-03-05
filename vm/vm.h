/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:06:03 by rthys             #+#    #+#             */
/*   Updated: 2018/03/05 15:06:30 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H

# define VM_H

typedef struct		s_env
{
	unsigned int	cycles;
	unsigned int	lives;
	unsigned int	dump;
	unsigned int	checks;
	unsigned int	nb_champs;
}					t_env;

typedef struct		s_champ
{
	char			*name;
	unsigned int	size;
	char			*comment;
}

#endif