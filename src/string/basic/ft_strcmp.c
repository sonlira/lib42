/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:03:52 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 15:17:25 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Compara lexicográficamente dos cadenas.
 *
 * Recorre ambas cadenas carácter a carácter hasta encontrar una diferencia
 * o hasta llegar al final. Si las cadenas son iguales, devuelve 0. En caso
 * contrario, devuelve la diferencia entre los caracteres que difieren.
 *
 * @param s1 Puntero a la primera cadena.
 * @param s2 Puntero a la segunda cadena.
 *
 * @return 0 si las cadenas son iguales;
 *         un valor positivo si s1 > s2;
 *         un valor negativo si s1 < s2.
 *
 * @note Esta función no valida punteros. Es responsabilidad del usuario
 *       pasar punteros válidos. Se mantiene este comportamiento por
 *       compatibilidad con la semántica estándar de strcmp.
 *
 * @example
 * ft_strcmp("hola", "hola");  // -> 0
 * ft_strcmp("hola", "holi");  // -> positivo
 * ft_strcmp("holi", "hola");  // -> negativo
 */
ssize_t	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
