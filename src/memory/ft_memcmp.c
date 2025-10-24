/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:43:43 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/15 19:59:21 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Compara dos bloques de memoria byte a byte.
 *
 * @details
 * Recorre los primeros `n` bytes de los bloques apuntados por `s1` y `s2`,
 * comparando cada par de bytes. Devuelve la diferencia entre el primer par
 * que difiere o 0 si todos son iguales.
 *
 * A diferencia de las funciones de cadena, esta comparación **no se detiene en
 * el carácter nulo ('\\0')**, sino que analiza exactamente `n` bytes.
 *
 * @param s1 Puntero al primer bloque de memoria.
 * @param s2 Puntero al segundo bloque de memoria.
 * @param n  Número de bytes a comparar.
 * 
 * @return
 * - Valor < 0 si el primer byte distinto en `s1` es menor que en `s2`
 * - 0 si ambos bloques son idénticos en los primeros `n` bytes
 * - Valor > 0 si el primer byte distinto en `s1` es mayor que en `s2`
 *
 * @note
 * Esta función no valida punteros nulos; se asume que ambos apuntan a 
 * memoria válida.
 *
 * @example
 * ### Ejemplo 1 — Bloques iguales
 * @code
 * char a[] = "abcd";
 * char b[] = "abcd";
 * ssize_t diff = ft_memcmp(a, b, 4);
 * // diff == 0
 * @endcode
 *
 * ### Ejemplo 2 — Diferencia en el tercer byte
 * @code
 * char a[] = "abc";
 * char b[] = "abd";
 * ssize_t diff = ft_memcmp(a, b, 3);
 * // diff < 0 porque 'c' < 'd'
 * @endcode
 *
 * ### Ejemplo 3 — Comparación parcial
 * @code
 * char a[] = "abcdef";
 * char b[] = "abcxyz";
 * ssize_t diff = ft_memcmp(a, b, 3);
 * // diff == 0 (solo compara los tres primeros bytes)
 * @endcode
 */
ssize_t	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	i = 0;
	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	while (i < n)
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}
