/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:44:09 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 18:49:37 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Cuenta cuántas veces aparece un carácter en una cadena.
 *
 * Recorre la cadena completa y devuelve el número de ocurrencias
 * del carácter indicado. Si el puntero recibido es NULL,
 * devuelve FT_ERROR (-1).
 *
 * @param s Puntero a la cadena en la que se buscará.
 * @param c Valor decimal del carácter a contar.
 *
 * @return Número de ocurrencias del carácter en la cadena;
 *         FT_ERROR (-1) si el puntero es inválido.
 *
 * @note No modifica la cadena original. La comparación se realiza
 *       en base al valor numérico del carácter (cast a int).
 *
 * @example
 * ft_count_char("banana", 'a'); // -> 3
 * ft_count_char("42 Madrid", 'z'); // -> 0
 * ft_count_char(NULL, 'a'); // -> FT_ERROR
 */
ssize_t	ft_count_char(const char *s, int c)
{
	ssize_t	count;

	if (!s)
		return (FT_ERROR);
	count = 0;
	while (*s)
	{
		if ((int)*s == c)
			count++;
		s++;
	}
	return (count);
}
