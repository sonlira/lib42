/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:11:38 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 21:47:49 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Calcula la longitud de una cadena de caracteres de forma segura.
 *
 * @details
 * Recorre la cadena @p str hasta encontrar el carácter nulo (`'\0'`) y devuelve
 * el número de caracteres previos. A diferencia de la función estándar 
 * `strlen(3)`, esta versión es segura ante punteros nulos: si @p str es 
 * inválido, devuelve `FT_ERROR` en lugar de provocar un fallo de segmentación.
 *
 * @param str  Puntero a una cadena de caracteres terminada en `'\0'`.
 *
 * @return La longitud de la cadena (número de caracteres antes de `'\0'`),
 *         o `FT_ERROR` si @p str es `NULL`.
 *
 * @note
 * - Esta función recorre la cadena una sola vez y no realiza operaciones de
 *   escritura, por lo que es segura para cadenas constantes.
 * - El valor devuelto no incluye el carácter nulo final.
 *
 * @example
 * @code
 * ssize_t len = ft_strlen_safe("Hola mundo");
 * // len = 10
 *
 * len = ft_strlen_safe(NULL);
 * // len = FT_ERROR
 * @endcode
 */
ssize_t	ft_strlen_safe(const char *str)
{
	ssize_t	length;

	length = 0;
	if (!str)
		return (FT_ERROR);
	while (str[length])
		length++;
	return (length);
}

/**
 * @brief Calcula la longitud de una cadena de caracteres.
 *
 * @details
 * Recorre la cadena @p str hasta encontrar el carácter nulo (`'\0'`) y devuelve
 * el número de caracteres previos. Si @p str no apunta a una cadena válida,
 * el comportamiento es indefinido. Para un manejo seguro de punteros nulos,
 * use @ref ft_strlen_safe().
 *
 * @param str  Puntero a una cadena terminada en `'\0'`.
 * @return Longitud de la cadena (número de caracteres antes de `'\0'`).
 *
 * @example
 * @code
 * size_t len = ft_strlen("Hola mundo");
 * // len = 10
 * @endcode
 * 
 * @see ft_strlen_safe()
 */
size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}
