/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	save_file(char *input_filename, header_t *header, char *champion)
{
	int			output_fd;
	char		*output_filename;

	input_filename[ft_strlen(input_filename) - ft_strlen(INPUT_EXTENSION)] = 0;
	if (!(output_filename = ft_strjoin(input_filename, OUTPUT_EXTENSION)))
		print_error(ERR_MALLOC);
	if ((output_fd = open(output_filename, O_WRONLY | O_CREAT,
		S_IRUSR | S_IWUSR)) == -1)
		print_error(ERR_FILE_CREATION);
	pr_free(output_filename);
	write(output_fd, &header, sizeof(header_t));
	write(output_fd, champion, ft_strlen(champion));
}

char	*parse_champion(header_t *header, int input_fd)
{
	static char	champion[CHAMP_MAX_SIZE + 1];
	char		*line;
	int			g;
	int			i;

	g = 1;
	ft_bzero(champion, CHAMP_MAX_SIZE + 1);
	//champion[CHAMP_MAX_SIZE] = EOF;
	line = 0;
	i = 0;
	while (g == 1)
	{
		skip_empty_lines(&line, input_fd, &g);
		if (line)
			parse_op(split_op(line), header, champion);
		pr_free(line);
		if ((g = get_next_line(input_fd, &line)) == -1)
			print_error(ERR_GNL);
	}
	//champion[CHAMP_MAX_SIZE] = 0;
	return (champion);
}

int		main(int argc, char *argv[])
{
	header_t	header;
	int			input_fd;

	if (argc < 2)
		print_error(ERR_USAGE);
	if (ft_strcmp(INPUT_EXTENSION, argv[1] + ft_strlen(argv[1])
											- ft_strlen(INPUT_EXTENSION)))
		print_error(ERR_WRONG_EXTENSION);
	if ((input_fd = open(argv[1], O_RDONLY, S_IRUSR)) == -1)
		print_error(ERR_FILE_READING);
	ft_bzero(&header, sizeof(header_t));
	header.magic = COREWAR_EXEC_MAGIC;
	parse_cmd(NAME_CMD_STRING, header.prog_name, input_fd, PROG_NAME_LENGTH);
	parse_cmd(COMMENT_CMD_STRING, header.comment, input_fd, COMMENT_LENGTH);
	save_file(argv[1], &header, parse_champion(&header, input_fd));
	return (0);
}
