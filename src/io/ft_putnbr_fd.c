/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:00:08 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/16 17:29:11 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Escribe un número entero en un descriptor.
 *
 * @param n  Número entero a escribir.
 * @param fd Descriptor de archivo destino.
 * @return
 * - Total de bytes escritos si tiene éxito.  
 * - `FT_ERROR` (-1) si falla `write()` o si `fd` es inválido.
 *
 * @example
 * @code
 * if (ft_putnbr_fd(-42, 1) == FT_ERROR)
 *     perror("ft_putnbr_fd");
 * @endcode
 */
ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	total;
	ssize_t	result;

	if (fd < 0)
		return (FT_ERROR);
	total = 0;
	if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == FT_ERROR)
			return (FT_ERROR);
		++total;
		n = -n;
	}
	if (n >= 10)
	{
		result = ft_putnbr_fd(n / 10, fd);
		if (result == FT_ERROR)
			return (FT_ERROR);
		total += result;
	}
	if (ft_putchar_fd((n % 10) + '0', fd) == FT_ERROR)
		return (FT_ERROR);
	return (++total);
}
