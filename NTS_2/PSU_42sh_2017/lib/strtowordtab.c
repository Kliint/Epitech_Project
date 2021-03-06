/*
** EPITECH PROJECT, 2018
** MINISHELL1
** File description:
** strtowordtab
*/

#include "shell.h"

int	nbr_word(char *str)
{
	int	i = 0;
	int	word = 0;

	while (str[i] != '\0')
	{
		if ((str[i] <= 126 && str[i] >= 125) ||
		    (str[i] <= 96 && str[i] >= 91) ||
		    (str[i] <= 64 && str[i] >= 58) ||
		    (str[i] <= 47))
			word++;
		i++;
	}
	return (word);
}

int	letter(char *str)
{
	int	i = 0;
	int	letter = 1;

	while (str[i] != '\0')
	{
		if ((str[i] <= 126 && str[i] >= 125) ||
		    (str[i] <= 96 && str[i] >= 91) ||
		    (str[i] <= 64 && str[i] >= 58) ||
		    (str[i] <= 47))
			i++;
		else
		{
			i++;
			letter++;
		}
	}
	return (letter);
}

int	check(char str)
{
	if ((str < '~' && str > '|') ||
	    (str <= '{' && str >= '}') ||
	    (str <= ',' && str >= '"') ||
	    (str <= '@' && str >= ':') ||
	    (str == '!' ||str == ' ' ) ||
	    (str == '\t' || str <= 31))
		return (1);
	else
		return (0);
	return (0);
}

char	**epur_tab(char **tab)
{
	char	**new;
	int	x = 0;
	int	i = 0;

	if ((new = malloc(sizeof(char *) * 255)) == NULL)
		return (NULL);
	while (tab[i] != NULL)
	{
		if (tab[i][0] < 33)
			i++;
		else
		{
			if ((new[x] = malloc(sizeof(char *) * 255)) == NULL)
				return (NULL);
			new[x++] = tab[i++];
		}
	}
	new[x] = NULL;
	return (new);
}

char	**my_str_to_wordtab(char *str)
{
	char	**tab;
	int  	i = 0;
	int  	x = 0;
	int	y = 0;
	int	j = 0;

	if ((tab = malloc(sizeof(char) * (nbr_word(str)) * 255)) == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if ((tab[j] = malloc(sizeof(char *) * (letter(str) * 255))) == NULL)
			return (NULL);
		if ((check(str[i])) == 1)
		{
			tab[x++][y] = '\0';
			i++;
			y = 0;
		}
		else
			tab[x][y++] = str[i++];
		j++;
	}
	return (epur_tab(tab));
}
