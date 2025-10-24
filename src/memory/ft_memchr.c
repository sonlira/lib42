/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:13:19 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/15 19:41:00 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Busca un byte específico en un bloque de memoria.
 *
 * @param s   Puntero al bloque de memoria donde buscar.
 * @param c   Valor del byte que se desea encontrar 
 *            (interpretado como unsigned char).
 * @param n   Cantidad de bytes que se van a examinar.
 * 
 * @return    Puntero al primer byte coincidente dentro del bloque,
 *            o NULL si el byte no se encuentra o si `s` es NULL.
 *
 * @note Función segura: valida el puntero antes de acceder a memoria.
 *       No depende de terminadores '\0' como las funciones de cadena.
 *
 * @example
 *     char buffer[] = {0x10, 0x20, 0x30, 0x40};
 *     unsigned char *found = ft_memchr(buffer, 0x30, 4);
 *     // found apunta al tercer byte del buffer.
 *
 * @example
 *     char text[] = "Hola mundo";
 *     char *p = ft_memchr(text, 'm', 11);
 *     // p apunta a 'm' dentro de la cadena.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	b = (unsigned char *)s;
	while (i < n)
	{
		if (b[i] == (unsigned char)c)
			return ((void *)&b[i]);
		i++;
	}
	return (NULL);
}
