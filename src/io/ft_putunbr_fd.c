/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:31:00 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/16 17:32:37 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Escribe un número sin signo en un descriptor de archivo.
 *
 * @param n  Número sin signo a escribir.
 * @param fd Descriptor de archivo destino.
 * @return
 * - Total de bytes escritos si tiene éxito.  
 * - `FT_ERROR` (-1) si `fd` es inválido o `write()` falla.
 *
 * @example
 * @code
 * ft_putunbr_fd(4294967295, 1); // imprime "4294967295"
 * @endcode
 */
ssize_t	ft_putunbr_fd(unsigned int n, int fd)
{
	ssize_t	total;
	ssize_t	result;

	if (fd < 0)
		return (FT_ERROR);
	total = 0;
	if (n >= 10)
	{
		result = ft_putunbr_fd(n / 10, fd);
		if (result == FT_ERROR)
			return (FT_ERROR);
		total += result;
	}
	if (ft_putchar_fd((n % 10) + '0', fd) == FT_ERROR)
		return (FT_ERROR);
	return (++total);
}
