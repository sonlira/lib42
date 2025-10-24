/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:48:43 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/24 14:36:24 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static size_t	word_size(const char *s, char delimiter)
{
	size_t	size;

	size = 0;
	while (s[size] && s[size] != delimiter)
		size++;
	return (size);
}

static size_t	count_word(const char *s, char delimiter)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != delimiter)
		{
			count++;
			s += word_size(s, delimiter);
		}
		else
			s++;
	}
	return (count);
}

static bool	fill_array(char **array, size_t size, const char *s, char delimiter)
{
	size_t	i;

	i = 0;
	while (*s && i < size)
	{
		if (*s != delimiter)
		{
			array[i] = ft_substr(s, 0, word_size(s, delimiter));
			if (!array[i])
			{
				ft_sfree_split(&array);
				return (false);
			}
			i++;
			s += word_size(s, delimiter);
		}
		else
			s++;
	}
	return (true);
}

/**
 * @brief Divide una cadena en subcadenas según un delimitador dado.
 *
 * Crea un array dinámico de cadenas (terminado en `NULL`) a partir de la cadena
 *`s`, separando las “palabras” mediante el carácter `c`. Cada elemento del array
 * se reserva en memoria dinámica e incluye su propio carácter nulo (`'\0'`).
 *
 * Si `s` es nulo o la reserva de memoria falla en algún punto, la función
 * devuelve `NULL`. En caso de error durante la creación del array, se liberan
 * todas las subcadenas ya reservadas antes de devolver `NULL`.
 *
 * @param s  Puntero a la cadena que se desea dividir.
 * @param c  Carácter delimitador utilizado para separar las subcadenas.
 *
 * @return Un puntero al nuevo array de cadenas (terminado en `NULL`), o `NULL`
 *         si se produce un error de memoria o si `s` es nulo.
 *
 * @note Cada subcadena y el array principal se reservan con `malloc()` y deben
 *       liberarse usando `ft_free_split()`.
 *
 * @example
 * char **words = ft_split("Hola mundo 42", ' ');
 * // words -> ["Hola", "mundo", "42", NULL]
 *
 * for (size_t i = 0; words[i]; i++)
 *     printf("[%s]\n", words[i]);
 *
 * ft_free_split(words);
 */
char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	size;

	if (!s)
		return (NULL);
	size = count_word(s, c);
	array = ft_calloc((size + 1), sizeof(char *));
	if (!array)
		return (NULL);
	if (!fill_array(array, size, s, c))
		return (NULL);
	return (array);
}
