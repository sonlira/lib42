/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:42:39 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 11:01:46 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Escribe la dirección de un puntero en formato hexadecimal.
 *
 * @param ptr Puntero a escribir (puede ser NULL).
 * @param fd  Descriptor de archivo destino.
 * @return
 * - Total de bytes escritos si tiene éxito.  
 * - `FT_ERROR` (-1) si `fd` es inválido o ocurre un fallo de escritura.
 *
 * @example
 * @code
 * int x = 42;
 * ft_putptr_fd(&x, 1);   // imprime "0x..." con la dirección de x
 * ft_putptr_fd(NULL, 1); // imprime "(nil)"
 * @endcode
 */
ssize_t	ft_putptr_fd(void *ptr, int fd)
{
	ssize_t	total;
	ssize_t	result;

	if (fd < 0)
		return (FT_ERROR);
	if (!ptr)
		return (ft_putstr_fd("(nil)", fd));
	if (ft_putstr_fd("0x", fd) == FT_ERROR)
		return (FT_ERROR);
	total = 2;
	result = ft_puthex_fd((uint64_t)ptr, fd, 0);
	if (result == FT_ERROR)
		return (FT_ERROR);
	return (total + result);
}
