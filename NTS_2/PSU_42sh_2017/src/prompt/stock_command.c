/*
** EPITECH PROJECT, 2018
** MINISHELL2
** File description:
** stock command 
*/

char	**malloc_command(char *command)
{
	int	pipe_counted = count_pipe(command);
	char	**stock = malloc(sizeof(char *) * pipe_counted);
	int	lenght = stack_len(command);

	while (y < pipe_counted) {
		stock[y] = malloc(sizeof(char) * lenght);
		if (stock[y] == NULL)
			return (NULL);
		y += 1;
	}
	stock[y] = NULL;
}

int	stack_lenght(char *command, t_stockage *auxiliaire)
{
	int	i = 0;
	static int	acc= 0;

	while (auxiliaire->str[i] != '|' && (auxiliaire->str[i])) {
		i += 1;
	}
	acc = i;
	auxiliaire->str = auxiliaire->*str + acc;
	return (i);
}
