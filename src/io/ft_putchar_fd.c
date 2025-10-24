/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:59:18 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/22 17:23:20 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Escribe un carácter en un descriptor de archivo.
 *
 * @param c  Carácter a escribir.
 * @param fd Descriptor de archivo destino.
 * @return
 * - 1 si la escritura fue exitosa.  
 * - -1 si falla `write()` o si `fd` es inválido.
 *
 * @example
 * @code
 * ft_putchar_fd('A', 1);
 * @endcode
 */
ssize_t	ft_putchar_fd(int c, int fd)
{
	unsigned char	uc;

	if (fd < 0)
		return (FT_ERROR);
	uc = (unsigned char)c;
	return (write(fd, &uc, 1));
}

/**
 * @brief Escribe un carácter repetido en un descriptor de archivo.
 *
 * Imprime el carácter @p c exactamente @p n veces en el descriptor @p fd.
 * Se detiene si `write()` falla, devolviendo @c FT_ERROR (-1).
 *
 * @param c  Carácter a escribir.
 * @param n  Número de repeticiones.
 * @param fd Descriptor de archivo destino.
 *
 * @return
 * - Número total de caracteres escritos si tiene éxito.  
 * - @c FT_ERROR (-1) si `write()` falla o @p fd es inválido.
 *
 * @example
 * @code
 * ft_putnchar_fd(' ', 5, 1); // imprime "     " y devuelve 5
 * @endcode
 */
ssize_t	ft_putnchar_fd(int c, ssize_t n, int fd)
{
	ssize_t			total;
	ssize_t			bytes;
	unsigned char	uc;

	if (fd < 0)
		return (FT_ERROR);
	uc = (unsigned char)c;
	total = 0;
	while (total < n)
	{
		bytes = (write(fd, &uc, 1));
		if (bytes == FT_ERROR)
			return (FT_ERROR);
		total += bytes;
	}
	return (total);
}
