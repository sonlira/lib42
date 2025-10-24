/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:40:50 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 19:10:45 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Copia una cadena de forma segura en un buffer de destino.
 *
 * Esta función copia la cadena `src` en el buffer `dst`, asegurando que no se
 * exceda el tamaño máximo indicado por `dstsize` y que el resultado esté
 * siempre terminado en '\0' (si `dstsize` es mayor que 0).
 *
 * A diferencia de la función estándar `strlcpy`, esta versión es segura frente
 * a punteros nulos: si `dst` o `src` son inválidos, no realiza ninguna copia y
 * devuelve `FT_ERROR`.
 *
 * @param dst      Puntero al buffer de destino donde se copiará la cadena.
 * @param src      Puntero a la cadena de origen terminada en '\0'.
 * @param dstsize  Tamaño total del buffer de destino (incluyendo el '\0').
 *
 * @return La longitud total de la cadena `src` (sin truncar) si la operación
 *         fue exitosa, o `FT_ERROR` si alguno de los punteros es nulo.
 *
 * @note Si `dstsize` es 0, no se realiza ninguna copia, pero se devuelve la
 *       longitud de `src`. El valor de retorno puede usarse para detectar si
 *       la cadena fue truncada comparándolo con `dstsize`.
 *
 * @example
 * char dst[5];
 * ssize_t len = ft_strlcpy(dst, "Hola mundo", sizeof(dst));
 * // dst -> "Hola"
 * // len -> 10
 *
 * if (len == FT_ERROR)
 *     printf("Error: puntero nulo\n");
 * else if ((size_t)len >= sizeof(dst))
 *     printf("Cadena truncada\n");
 * else
 *     printf("Copia completada correctamente\n");
 */
ssize_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (FT_ERROR);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return ((ssize_t)i);
}
