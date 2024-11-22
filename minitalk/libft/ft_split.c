/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:57:25 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/09 10:18:22 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_ar(size_t i, char **ar)
{
	while (i > 0)
	{
		i--;
		free(ar[i]);
	}
	free(ar);
}

static	char	**sep(char const *s, char c, char **ar, size_t cwords)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < cwords)
	{
		while (s[j] && s[j] == c)
			j++;
		ar[i] = ft_substr(s, j, word_len(&s[j], c));
		if (!ar[i])
		{
			free_ar(i, ar);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	ar[i] = NULL;
	return (ar);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**ar;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ar = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ar)
		return (NULL);
	ar = sep(s, c, ar, words);
	return (ar);
}

/* int	main(void)
{
	char	**words = ft_split("hola,mundo,soy,un,programador", ',');
	int		i = 0;

	while (words[i] != NULL)
	{
		printf("%s\n", words[i]);
		i++;
	}

	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);

	return (0);
} */
/* Esta función de ft_split sirve para separar texto con un delimitador
que eliges para crear subcadenas y ver cuantas palabras
hay en el texto
count_words: cuenta el número de palabras en la cadena s que están
separadas por c.
word_len: devuelve la longitud de la palabra comenznado por la posición
actual de s, terminando cuando encuentra c.
free_ar: libera memoria asignada a cada cadena en el array ar y
luego libera la memoria asignada al propio array. se usa cuando hay un error
durante la creación del array de palabras.
sep: llena el array con las palabras de la cadena s. Para cada palabra,
se reserva memoria con la función ft_substr, que devuelve una subcadena s
que comienza en la posición actual y tiene la longitud de la palabra. */
