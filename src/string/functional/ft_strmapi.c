/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:05:27 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/20 19:05:13 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Crea una nueva cadena aplicando una función a cada carácter de la 
 * original.
 *
 * Esta función recorre la cadena `s` y aplica la función `f` a cada carácter,
 * pasando también el índice del carácter como primer argumento. La cadena
 * original no se modifica; el resultado se devuelve en una nueva cadena 
 * dinámica.
 *
 * @param s Puntero a la cadena de origen. Debe ser válido (no NULL).
 * @param f Puntero a la función que se aplicará a cada carácter.
 *          Debe tener la forma `char f(unsigned int, char)`.
 *
 * @return Un puntero a la nueva cadena modificada, o NULL si ocurre un error
 *         (punteros inválidos o fallo de reserva de memoria).
 *
 * @note Esta función forma parte de la versión segura de libft (`lib42`).
 *       Valida los punteros de entrada y el resultado de malloc.
 *       La memoria devuelta debe liberarse con `free`.
 *
 * @example
 * char upper_if_even(unsigned int i, char c)
 * {
 *     return (i % 2 == 0) ? ft_toupper(c) : c;
 * }
 *
 * char *str = ft_strmapi("abcdef", upper_if_even);
 * // Resultado: "AbCdEf"
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	ssize_t	size;
	char	*result;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if (size == FT_ERROR)
		return (NULL);
	result = ft_calloc((size_t)size + 1, sizeof(*result));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
