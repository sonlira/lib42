/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:19:37 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 19:12:55 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Concatena de forma segura una cadena al final de otra.
 *
 * Añade la cadena `src` al final del buffer `dst` sin exceder el tamaño máximo
 * indicado por `dstsize`. La cadena resultante en `dst` siempre termina en '\0'
 * (si hay espacio suficiente). A diferencia de la función estándar `strlcat`,
 * esta versión es segura frente a punteros nulos: si `dst` o `src` 
 * son inválidos,
 * devuelve `FT_ERROR` en lugar de provocar un fallo de segmentación.
 *
 * @param dst      Puntero al buffer de destino, que ya debe contener una cadena
 *                 terminada en '\0'. 
 * @param src      Puntero a la cadena de origen que se añadirá al final de 
 * `dst`.
 * @param dstsize  Tamaño total del buffer de destino 
 * (incluyendo el carácter '\0').
 *
 * @return La longitud total que habría tenido la cadena resultante si hubiera
 *         suficiente espacio (longitud original de `dst` + longitud de `src`),
 *         o `FT_ERROR` si alguno de los punteros es nulo.
 *
 * @note Si `dstsize` es menor o igual que la longitud de `dst`, no se copia nada
 *       y se devuelve `dstsize + strlen(src)`. Esto permite detectar 
 * truncamientos
 *       comparando el valor retornado con `dstsize`.
 *
 * @example
 * char dst[10] = "Hola";
 * ssize_t len = ft_strlcat(dst, " mundo", sizeof(dst));
 * // dst -> "Hola mund"
 * // len -> 11 (longitud teórica completa de "Hola mundo")
 *
 * if (len == FT_ERROR)
 *     printf("Error: puntero nulo\n");
 * else if ((size_t)len >= sizeof(dst))
 *     printf("Cadena truncada\n");
 * else
 *     printf("Concatenación completada: %s\n", dst);
 */
ssize_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	ssize_t	dst_len;
	ssize_t	src_len;

	if (!dst || !src)
		return (FT_ERROR);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len == FT_ERROR || src_len == FT_ERROR)
		return (FT_ERROR);
	if (dstsize <= (size_t)dst_len)
		return (dstsize + src_len);
	i = dst_len;
	while (*src && i < (dstsize - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
