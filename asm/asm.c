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

char	*check_cmd(char *cmd, int fd, char **line, size_t max_length)
{
	char *temp;

	*line = 0;
	while (!(*line) || **line == COMMENT_CHAR)
	{
		pr_free(*line);
		if (get_next_line(fd, line) != 1)
			print_error(ERR_GNL);
	}
	if (ft_strncmp(cmd, *line, ft_strlen(cmd))
		|| ft_strncmp(*line + ft_strlen(cmd), " \"", 2))
		print_error(ERR_INVALID_COMMAND);
	if (ft_strlen(temp = *line + ft_strlen(cmd) + 2) > max_length)
		print_error(ERR_COMMAND_LENGTH);
	return (temp);
}

void	parse_cmd(char *cmd, char *dest, int fd, size_t max_length)
{
	char	*line;
	char	*temp;
	int		end;

	end = 0;
	temp = check_cmd(cmd, fd, &line, max_length);
	while (!end)
	{
		if ((end = !!ft_strchr(temp, '"')))
		{
			if (ft_strchr(ft_strchr(temp, '"') + 1, '"'))
				print_error(ERR_SYNTAX);
			*ft_strchr(temp, '"') = 0;
		}
		if (ft_strlen(dest) + ft_strlen(temp) + !end > max_length)
			print_error(ERR_COMMAND_LENGTH);
		ft_strcpy(dest + ft_strlen(dest), temp);
		if (!end)
			ft_memcpy(dest + ft_strlen(dest), "\n", 2);
		ft_printf("%s\n", dest);
		pr_free(line);
		if (!end && get_next_line(fd, &line) != 1)
			print_error(ERR_GNL);
		temp = line;
	}
}

void	save_file(char *input_filename, header_t header)//, char *code_buffer)
{
	int			output_fd;
	char		*output_filename;

	input_filename[ft_strlen(input_filename) - 2] = 0;
	if (!(output_filename = ft_strjoin(input_filename, OUTPUT_EXTENSION)))
		print_error(ERR_MALLOC);
	if ((output_fd = open(output_filename, O_WRONLY | O_CREAT,
		S_IRUSR | S_IWUSR)) == -1)
		print_error(ERR_FILE_CREATION);
	pr_free(output_filename);
	write(output_fd, &header, sizeof(header_t));
	//write(output_fd, code_buffer, ft_strlen(code_buffer));
	//pr_free(code_buffer);
}

/*
//TODO
char	*parse_code(header_t header, int input_fd)
{
	return ();
}*/

int		main(int argc, char *argv[])
{
	header_t	header;
	int			input_fd;

	if (argc < 2)
		print_error(ERR_USAGE);
	if (ft_strcmp(INPUT_EXTENSION, argv[1] + ft_strlen(argv[1]) - 2))
		print_error(ERR_WRONG_EXTENSION);
	if ((input_fd = open(argv[1], O_RDONLY, S_IRUSR)) == -1)
		print_error(ERR_FILE_READING);
	ft_bzero(&header, sizeof(header_t));
	header.magic = COREWAR_EXEC_MAGIC;
	header.prog_size = 0x42424242;//a definir dans parse_code
	parse_cmd(NAME_CMD_STRING, header.prog_name, input_fd, PROG_NAME_LENGTH);
	parse_cmd(COMMENT_CMD_STRING, header.comment, input_fd, COMMENT_LENGTH);
	save_file(argv[1], header);//, parse_code(header, input_fd));
	return (0);
}
