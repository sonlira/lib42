/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:54:59 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 14:11:05 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Aplica una función a cada carácter de una cadena, 
 *        modificándola in situ (madifica la cadena original).
 *
 * Esta función recorre la cadena `s` y llama a `f` para cada carácter,
 * pasando también el índice como primer argumento. La función `f` puede
 * modificar el carácter directamente a través del puntero recibido.
 *
 * @param s Puntero a la cadena que se modificará.
 * @param f Puntero a la función que se aplicará a cada carácter.
 *          Debe tener la forma `void f(unsigned int, char *)`.
 *
 * @note Si alguno de los punteros es NULL, la función no realiza ninguna acción.
 *       No devuelve valor alguno.
 *       La cadena **no debe ser un literal** (por ejemplo `"hola"`), ya que los
 *       literales son de solo lectura. Use una cadena mutable, 
 *       como `char str[]`.
 *
 * @example
 * void upper_if_even(unsigned int i, char *c)
 * {
 *     if (i % 2 == 0)
 *         *c = ft_toupper(*c);
 * }
 *
 * char str[] = "abcdef";
 * ft_striteri(str, upper_if_even);
 * // Resultado: str = "AbCdEf"
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
