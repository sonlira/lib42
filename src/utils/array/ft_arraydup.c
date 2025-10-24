/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:38:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 19:06:33 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Duplica un array de cadenas de caracteres.
 *
 * La función ft_arraydup() crea una copia profunda del array de cadenas
 * `array`. Para cada elemento del array original, se reserva memoria
 * y se almacena una nueva copia mediante ft_strdup(). El nuevo array
 * se termina con un puntero NULL, igual que el original.
 *
 * Si en algún momento ocurre un error de asignación de memoria,
 * la función libera toda la memoria reservada hasta el momento
 * utilizando ft_free_array_ret() y devuelve NULL.
 *
 * @param array Array de cadenas terminado en NULL que se desea duplicar.
 *
 * @return Un nuevo array con copias independientes de cada cadena,
 *         o NULL si `array` es NULL, si se produce un error de memoria,
 *         o si ft_arraylen() devuelve FT_ERROR.
 *
 * @note El array devuelto debe ser liberado con ft_free_array_ret()
 *       o una función equivalente que libere cada cadena y el propio array.
 *
 * @see ft_arraylen(), ft_strdup(), ft_calloc(), ft_free_array_ret()
 */
char	**ft_arraydup(char **array)
{
	ssize_t	size;
	size_t	i;
	char	**dups;

	if (!array)
		return (NULL);
	size = ft_arraylen((void **)array);
	if (size == FT_ERROR)
		return (NULL);
	dups = ft_calloc((size_t)(size + 1), sizeof(*dups));
	if (!dups)
		return (NULL);
	while (array[i])
	{
		dups[i] = ft_strdup(array[i]);
		if (!dups[i])
			return (ft_free_array_ret((void **)dups));
		i++;
	}
	return (dups);
}
