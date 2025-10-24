/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:21:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/15 18:39:08 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Copia un bloque de memoria de origen a destino.
 *
 * @param dst Puntero al bloque de memoria de destino.
 * @param src Puntero al bloque de memoria de origen.
 * @param n   Cantidad de bytes a copiar.
 * 
 * @return    Puntero al bloque de destino (`dst`), 
 *            o NULL si `dst` o `src` son NULL.
 *
 * @note Función segura: valida los punteros antes de acceder a memoria.
 *       No maneja solapamientos; para eso se debe usar `ft_memmove`.
 * @example
 *     char src[5] = "Hola";
 *     char dst[5];
 *     ft_memcpy(dst, src, 5);
 *     // dst ahora contiene "Hola"
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
