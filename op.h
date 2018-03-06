/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:25:17 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/06 19:09:45 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

#include <stdint.h>

#define IND_SIZE	2
#define REG_SIZE	4
#define DIR_SIZE	REG_SIZE


# define REG_CODE	1
# define DIR_CODE	2
# define IND_CODE	3


#define MAX_ARGS_NUMBER	4
#define MAX_PLAYERS		4
#define MEM_SIZE		(4*1024)
#define IDX_MOD			(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE	(MEM_SIZE / 6)

#define COMMENT_CHAR	'#'
#define LABEL_CHAR		':'
#define DIRECT_CHAR		'%'
#define SEPARATOR_CHAR	','

#define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING	".name"
#define COMMENT_CMD_STRING	".comment"

#define REG_NUMBER		16

#define CYCLE_TO_DIE	1536
#define CYCLE_DELTA		50
#define NBR_LIVE		21
#define MAX_CHECKS		10

 /**
 ***
 **/

typedef char	t_arg_type;

#define T_REG		1
#define T_DIR		2
#define T_IND		4
#define T_LAB		8

/**
***
**/

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3


typedef struct	s_ins
{
	char	*name;
	int		ocp;
	int		param1;
	int		param2;
	int		param3;
}				t_ins;

typedef	struct	s_op
{
	char	*name;
	int		nb_param;
	int		param[3];
	int		length;
	int		ocp;
	int		size_no_ocp;
}				t_op;

typedef struct	header_s
{
	  unsigned int	magic;
	  char			prog_name[PROG_NAME_LENGTH + 1];
	  unsigned int	prog_size;
	  char			comment[COMMENT_LENGTH + 1];
}
header_t;

typedef struct	s_champ
{
	header_t		header;
	char			*code;
	int				reg[REG_NUMBER];
	int				placed;
	int				color;
}				t_champ;

typedef struct	s_corewar
{
	char	arena_id[MEM_SIZE + 1];
	char	arena[MEM_SIZE + 1];
	int		nb_champ;
	t_champ	tab_champ[6];
	int		cycle_to_die_current;
}				t_corewar;

header_t	ft_get_header(int fd);
t_champ		ft_get_champ(char *filename);
void		ft_get_var(t_ins *ins, char *code_champ);
t_ins		*ft_get_instru(char *code_champ);
int			ft_get_int(char *code_champ, int size);
