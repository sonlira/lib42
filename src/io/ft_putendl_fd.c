/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:18:11 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/19 22:31:21 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Escribe una cadena con salto de línea en un descriptor.
 *
 * @param s  Cadena terminada en `'\0'`.
 * @param fd Descriptor de archivo destino.
 * @return
 * - Total de bytes escritos si tiene éxito.  
 * - `FT_ERROR` (-1) si ocurre algún error o si los parámetros son inválidos.
 *
 * @example
 * @code
 * if (ft_putendl_fd("Hola mundo", 1) == FT_ERROR)
 *     perror("ft_putendl_fd");
 * @endcode
 */
ssize_t	ft_putendl_fd(const char *s, int fd)
{
	ssize_t	total;

	if (!s || fd < 0)
		return (FT_ERROR);
	total = ft_putstr_fd(s, fd);
	if (total == FT_ERROR)
		return (FT_ERROR);
	if (ft_putchar_fd('\n', fd) == FT_ERROR)
		return (FT_ERROR);
	return (++total);
}
