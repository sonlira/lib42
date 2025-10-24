/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:11:38 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/12 17:17:31 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Calcula la longitud de una cadena de caracteres de forma segura.
 *
 * Recorre la cadena `str` hasta encontrar el carácter nulo `'\0'` y devuelve
 * el número de caracteres previos. A diferencia de la función estándar `strlen`,
 * esta versión es segura frente a punteros nulos: si `str` es inválido, devuelve
 * `FT_ERROR` en lugar de provocar un fallo de segmentación.
 *
 * @param str  Puntero a la cadena de caracteres terminada en `'\0'`.
 *
 * @return La longitud de la cadena (número de caracteres antes de `'\0'`),
 *         o `FT_ERROR` si `str` es nulo.
 *
 * @note Esta función recorre la cadena una sola vez y no realiza ninguna
 *       operación de escritura, por lo que es segura para cadenas constantes.
 *
 * @example
 * ssize_t len = ft_strlen("Hola mundo");
 * // len -> 10
 *
 * len = ft_strlen(NULL);
 * // len -> FT_ERROR
 */
ssize_t	ft_strlen(const char *str)
{
	ssize_t	length;

	length = 0;
	if (!str)
		return (FT_ERROR);
	while (str[length])
		length++;
	return (length);
}
