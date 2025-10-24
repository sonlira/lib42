/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:45:23 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/16 14:54:48 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Rellena un bloque de memoria con un byte específico.
 *
 * @param s   Puntero al bloque de memoria que se desea modificar.
 * @param c   Valor del byte a escribir (interpretado como unsigned char).
 * @param n   Cantidad de bytes a rellenar.
 * 
 * @return    Puntero al bloque de memoria (`s`), o NULL si `s` es NULL.
 *
 * @note Función segura: valida el puntero antes de acceder a memoria.
 * @example
 *     char buffer[5];
 *     ft_memset(buffer, 'A', 5);
 *     // buffer ahora contiene: "AAAAA"
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;
	size_t			i;

	if (!s)
		return (NULL);
	b = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		b[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
