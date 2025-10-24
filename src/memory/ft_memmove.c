/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:42:09 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/24 14:37:35 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Copia un bloque de memoria incluso cuando las áreas se solapan.
 *
 * Esta función es similar a `ft_memcpy`, pero maneja correctamente el 
 * caso en que las áreas de memoria origen (`src`) y destino (`dst`) 
 * **se solapan**, es decir, cuando parte del bloque de destino 
 * se solapa físicamente con el bloque de origen en memoria.
 *
 * En esos casos, `ft_memcpy` podría sobrescribir datos aún no copiados, causando
 * resultados corruptos. `ft_memmove`, en cambio, detecta la dirección del 
 * solapamiento y copia los bytes en el orden adecuado 
 * (de atrás hacia adelante si es necesario)
 * para garantizar una copia correcta.
 *
 * @param dst Puntero al bloque de destino.
 * @param src Puntero al bloque de origen.
 * @param n   Número de bytes a copiar.
 * 
 * @return    Puntero al bloque de destino (`dst`), 
 *            o NULL si `dst` o `src` son NULL.
 *
 * @note
 * - Si `dst < src`, las áreas no se pisan y se copia como `ft_memcpy`.
 * - Si `dst > src`, se copian los bytes en orden inverso para evitar 
 *                   sobreescritura.
 * - Si `n == 0`, la función no hace nada.
 *
 * @example
 * ### Ejemplo 1 — Copia sin solapamiento
 * @code
 * char src[6] = "Hola!";
 * char dst[6];
 * ft_memmove(dst, src, 6);
 * // dst contiene "Hola!"
 * @endcode
 *
 * ### Ejemplo 2 — Copia con solapamiento hacia adelante
 * @code
 * char str[] = "abcdef";
 * ft_memmove(str + 2, str, 4);
 * // El bloque de origen "abcd" se copia a partir de str[2]:
 * // Resultado final: "ababcd"
 * @endcode
 *
 * ### Ejemplo 3 — Copia con solapamiento hacia atrás
 * @code
 * char str[] = "123456";
 * ft_memmove(str, str + 2, 4);
 * // Copia el bloque "3456" al inicio del buffer:
 * // Resultado final: "345656"
 * @endcode
 */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst || !src)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		d[n] = s[n];
	return (dst);
}
