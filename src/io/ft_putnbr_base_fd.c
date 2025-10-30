/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:46:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 20:53:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Escribe un número entero en una base personalizada en un descriptor.
 *
 * @details
 * Esta función permite imprimir un número entero `n` en un descriptor de archivo
 * `fd` utilizando una base definida por el usuario.  
 * La base debe ser una cadena con caracteres únicos e imprimibles, de longitud
 * mínima 2 (por ejemplo: `"01"`, `"0123456789ABCDEF"`, `"poneyvif"`).
 * 
 * @param n     Número entero a escribir.
 * @param src_base Cadena con los símbolos de la base 
 * 				(mínimo 2 caracteres únicos).
 * @param fd    Descriptor de archivo destino.
 * @return
 * - Total de bytes escritos si tiene éxito.  
 * - `FT_ERROR` (-1) si el descriptor, la base o la escritura fallan.
 *
 * @note
 * La función es completamente segura: valida el descriptor, la base, el signo
 * y todos los errores de escritura.  
 * Devuelve el número total de bytes escritos o `FT_ERROR` en caso de fallo.
 *
 * @example
 * ft_putnbr_base_fd(42, "01", 1);                // imprime "101010"
 * ft_putnbr_base_fd(255, "0123456789ABCDEF", 1); // imprime "FF"
 * ft_putnbr_base_fd(-42, "01234567", 1);         // imprime "-52"
 * ft_putnbr_base_fd(0, "poneyvif", 1);           // imprime "p"
 * 
 */
ssize_t	ft_putnbr_base_fd(unsigned int un, const char *src_base, int fd)
{
	ssize_t		total;
	ssize_t		result;
	ssize_t		len;

	if (fd < 0 || !src_base)
		return (FT_ERROR);
	len = ft_strlen_safe(src_base);
	if (len < 2 || !ft_is_valid_base(src_base))
		return (FT_ERROR);
	total = 0;
	if (un >= len)
	{
		result = ft_putnbr_base_fd(un / len, src_base, fd);
		if (result == FT_ERROR)
			return (FT_ERROR);
		total += result;
	}
	if (ft_putchar_fd(src_base[un % len], fd) == FT_ERROR)
		return (FT_ERROR);
	return (++total);
}
