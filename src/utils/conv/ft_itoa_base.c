/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:15:42 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 20:53:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Convierte un número sin signo a una cadena de caracteres según una 
 * 		base.
 *
 * @details
 * La función `ft_itoa_base()` toma un número sin signo `un` y devuelve una
 * cadena de caracteres recién asignada que representa el número en la base
 * definida por la cadena `src_base`. Cada carácter de `src_base` representa
 * un dígito distinto de la base.
 *
 * La base debe ser válida, es decir:
 *  - Tener al menos dos símbolos.
 *  - No contener caracteres duplicados.
 *  - No incluir espacios, ni los símbolos '+' o '-'.
 *
 * Internamente, la función reserva memoria dinámica mediante `ft_calloc()`
 * y convierte el número de forma iterativa. La memoria devuelta debe
 * liberarse con `free()` cuando ya no se necesite.
 *
 * @param un        Valor numérico sin signo a convertir.
 * @param src_base  Cadena con los símbolos que representan la base.
 *
 * @return
 * Un puntero a la cadena resultante con la representación del número en la
 * base indicada. Devuelve `NULL` si:
 *  - La base no es válida.
 *  - Ocurre un error en la asignación de memoria.
 *
 * @note Si `un` es 0, la función devuelve la cadena formada por el primer
 *       carácter de `src_base`.
 */
char	*ft_itoa_base(uint64_t un, const char *src_base)
{
	ssize_t		base;
	size_t		size;
	char		*result;

	if (!src_base)
		return (NULL);
	base = ft_strlen_safe(src_base);
	if (base < 2 || !ft_is_valid_base(src_base))
		return (NULL);
	size = ft_unumlen_base(un, (size_t)base);
	if (!size)
		return (NULL);
	result = ft_calloc(size + 1, sizeof(*result));
	if (!result)
		return (NULL);
	if (un == 0)
		result[0] = src_base[0];
	while (un)
	{
		result[--size] = src_base[un % base];
		un /= base;
	}
	return (result);
}
