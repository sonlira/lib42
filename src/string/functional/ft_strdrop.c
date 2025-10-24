/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdrop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:28:01 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/24 14:36:51 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Avanza el puntero de una cadena mientras los caracteres cumplan una
 *        condición.
 *
 * Esta función recorre la cadena `s` y descarta los caracteres iniciales
 * para los cuales la función `f` devuelve `true`. Devuelve un puntero al
 * primer carácter que **no** cumple la condición.
 *
 * @param s Cadena de caracteres terminada en nulo.
 * @param f Puntero a una función que recibe un `int` (carácter)
 *          y devuelve `true` si debe ser descartado.
 * @return Puntero al primer carácter que no cumple la condición,
 *         o `NULL` si `s` o `f` son nulos.
 * 
 * @example
 * Ejemplo de uso:
 * @code
 * const char *str = "   hola";
 * const char *trimmed = ft_strdrop(str, isspace);
 * // trimmed -> "hola"
 * @endcode
 */
const char	*ft_strdrop(const char *s, bool (*f)(int))
{
	if (!s || !f)
		return (NULL);
	while (*s && f(*s))
		s++;
	return (s);
}
