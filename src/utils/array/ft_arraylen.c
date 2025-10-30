/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:42:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 21:02:47 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Calcula la longitud de un array genérico terminado en NULL.
 *
 * La función ft_arraylen() cuenta cuántos elementos contiene un array
 * de punteros terminado en NULL, sin importar el tipo de los elementos.
 *
 * Si el puntero `array` es NULL, la función devuelve `FT_ERROR`
 * (normalmente definido como -1) para indicar un error.
 *
 * @param array Array de punteros terminado en NULL.
 *
 * @return El número de elementos del array (sin contar el NULL final),
 *         o `FT_ERROR` si el puntero `array` es NULL.
 *
 * @note Esta función es genérica y puede usarse con arrays de cualquier tipo
 *       siempre que terminen en un puntero NULL.
 *
 * @see ft_arraydup(), ft_arrayassign(), ft_free_array_safe()
 */
ssize_t	ft_arraylen(void **array)
{
	ssize_t	length;

	length = 0;
	if (!array)
		return (FT_ERROR);
	while (array[length])
		length++;
	return (length);
}

/**
 * @brief Calcula la longitud de un array de cadenas (fuentes).
 *
 * @details
 * Devuelve el número de elementos del array @p array, sin contar el terminador 
 * `NULL`.
 * 
 * Internamente delega en @ref ft_arraylen(), adaptada a arrays de `char *`.
 *
 * @param array  Array de cadenas terminado en `NULL`.
 *
 * @return La cantidad de elementos del array, o `FT_ERROR` 
 * (normalmente definido como -1) si el puntero @p array es `NULL`.
 *
 * @example
 * @code
 * char *srcs[] = {"uno", "dos", "tres", NULL};
 * ssize_t count = ft_srcslen(srcs);
 * // count = 3
 * @endcode
 *
 * @see ft_arraylen()
 * @see ft_free_srcs()
 * @see ft_sfree_srcs()
 */
ssize_t	ft_strslen(char **array)
{
	return (ft_arraylen((void **)array));
}
