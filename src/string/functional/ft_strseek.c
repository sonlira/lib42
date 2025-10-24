/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strseek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:38:59 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/20 14:50:57 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Avanza el puntero de una cadena hasta el primer carácter que cumpla
 *        una condición.
 *
 * Esta función recorre la cadena `s` hasta encontrar el primer carácter
 * para el cual la función `f` devuelve `true`. Devuelve un puntero a ese
 * carácter, o al terminador nulo `'\0'` si no se encuentra ninguno.
 *
 * @param s Cadena de caracteres terminada en nulo.
 * @param f Puntero a una función que recibe un `int` (carácter)
 *          y devuelve `true` si cumple la condición buscada.
 * @return Puntero al primer carácter que cumple la condición,
 *         o al terminador nulo si no se encuentra ninguno.
 *         Devuelve `NULL` si `s` o `f` son nulos.
 * @example
 * Ejemplo de uso:
 * @code
 * const char *str = "abc123";
 * const char *digits = ft_strseek(str, isdigit);
 * // digits -> "123"
 * @endcode
 */
const char	*ft_strseek(const char *s, bool (*f)(int))
{
	if (!s || !f)
		return (NULL);
	while (*s && !f(*s))
		s++;
	return (s);
}
