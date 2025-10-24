/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:35:45 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 11:00:37 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Escribe un número sin signo en formato hexadecimal.
 *
 * @param n     Número sin signo a escribir.
 * @param fd    Descriptor de archivo destino.
 * @param upper Si es true, usa letras mayúsculas (A–F).
 * @return
 * - Total de bytes escritos si tiene éxito.  
 * - `FT_ERROR` (-1) si `fd` es inválido o `write()` falla.
 *
 * @example
 * @code
 * ft_puthex_fd(255, 1, 0); // imprime "ff"
 * ft_puthex_fd(255, 1, 1); // imprime "FF"
 * @endcode
 */
ssize_t	ft_puthex_fd(uint64_t n, int fd, bool upper)
{
	const char	*base;
	ssize_t		total;
	ssize_t		result;

	if (fd < 0)
		return (FT_ERROR);
	base = BASE_HEX_LOWER_STR;
	if (upper)
		base = BASE_HEX_UPPER_STR;
	total = 0;
	if (n >= 16)
	{
		result = ft_puthex_fd(n / 16, fd, upper);
		if (result == FT_ERROR)
			return (FT_ERROR);
		total += result;
	}
	if (ft_putchar_fd(base[n % 16], fd) == FT_ERROR)
		return (FT_ERROR);
	return (++total);
}
