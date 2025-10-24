/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:03:07 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/22 17:31:36 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Escribe una cadena en un descriptor de archivo.
 *
 * @param s  Cadena terminada en `'\0'`.
 * @param fd Descriptor de archivo destino.
 * @return
 * - Número total de bytes escritos si tiene éxito.  
 * - `FT_ERROR` (-1) si falla `write()` o si los parámetros son inválidos.
 *
 * @example
 * @code
 * if (ft_putstr_fd("Hola, mundo", 1) == FT_ERROR)
 *     perror("ft_putstr_fd");
 * @endcode
 */
ssize_t	ft_putstr_fd(const char *s, int fd)
{
	ssize_t	len;
	ssize_t	total;
	ssize_t	bytes;

	if (!s || fd < 0)
		return (FT_ERROR);
	len = ft_strlen(s);
	if (len == FT_ERROR)
		return (FT_ERROR);
	total = 0;
	while (total < len)
	{
		bytes = write(fd, s + total, len - total);
		if (bytes == FT_ERROR)
			return (FT_ERROR);
		total += bytes;
	}
	return (total);
}

/**
 * @brief Escribe una cadena en un descriptor de archivo hasta un límite de 
 * 		bytes.
 *
 * @details
 * La función `ft_putstrl_fd()` escribe en el descriptor `fd` como máximo `len`
 * bytes de la cadena `s`. Si `write()` devuelve menos bytes de los esperados,
 * la función reintenta la escritura hasta completar el total o hasta que ocurra
 * un error.
 *
 * A diferencia de `write()` estándar, esta función devuelve `
 * FT_ERROR` (típicamente `-1`)
 * si se produce algún fallo, incluyendo punteros nulos o errores internos
 * reportados por `ft_strlen()`.
 *
 * @param s   Cadena terminada en nulo que se desea escribir.
 * @param len Máximo número de bytes a escribir de la cadena.
 * @param fd  Descriptor de archivo donde se escribirá la cadena.
 *
 * @return La cantidad total de bytes escritos si la operación tiene éxito,
 *        o `FT_ERROR` si ocurre un error o si `ft_strlen()` devuelve `FT_ERROR`.
 *
 * @note Si `len` es menor que la longitud de la cadena, se escriben solo los 
 * 		primeros `len` caracteres. Si `len` excede la longitud, se escribe la 
 * 		cadena completa.
 *
 * @example
 * ft_putstrl_fd("Hello, world!", 5, STDOUT_FILENO); // escribe "Hello"
 */
ssize_t	ft_putstrl_fd(const char *s, ssize_t len, int fd)
{
	ssize_t	total;
	ssize_t	bytes;

	if (!s || fd < 0)
		return (FT_ERROR);
	total = 0;
	while (s[total] && total < len)
	{
		bytes = write(fd, s + total, len - total);
		if (bytes == FT_ERROR)
			return (FT_ERROR);
		total += bytes;
	}
	return (total);
}
