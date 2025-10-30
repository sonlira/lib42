/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:27:10 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 17:39:19 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static void	put_char_with_flags(int c, t_snformat *snf)
{
	if (snf->f.minus)
	{
		ft_putchar_to_snf(c, snf);
		ft_putnchar_to_snf(' ', snf->f.width - 1, snf);
	}
	else
	{
		if (snf->f.zero && snf->f.type == '%')
			ft_putnchar_to_snf('0', snf->f.width - 1, snf);
		else
			ft_putnchar_to_snf(' ', snf->f.width - 1, snf);
		ft_putchar_to_snf(c, snf);
	}
}

/**
 * @brief Escribe un carácter en el buffer de @ref t_snformat aplicando las 
 * banderas de formato.
 *
 * @details
 * Gestiona la conversión del tipo `'c'` o `'%'` en la versión de
 * @ref ft_snprintf(), escribiendo directamente en el buffer controlado
 * por @p snf.  
 * 
 * Antes de escribir, llama a @ref ft_normalize_char_flags() para limpiar
 * las banderas no aplicables a caracteres (como `+`, `#`, ` ` o `.`).
 * 
 * La impresión real se realiza mediante @c put_char_with_flags(), que
 * aplica las banderas de anchura (`width`), alineación (`-`) y relleno (`0`),
 * escribiendo en el buffer gestionado por @p snf.
 *
 * @param c    Carácter a escribir.
 * @param snf  Puntero a la estructura @ref t_snformat que contiene el buffer
 *             y las banderas de formato activas.
 *
 * @return Nada.  
 * La posición, el conteo de bytes y el contenido del buffer son actualizados
 * dentro de @p snf.
 *
 * @note
 * - Si @p snf es NULL, la función no realiza ninguna operación.  
 * - Las banderas `+`, `#`, ` ` y `.` no afectan a este tipo.  
 * - La bandera `0` se ignora si está activa la bandera `-`.
 *
 * @example
 * @code
 * t_snformat snf;
 * init_snformat(&snf);
 * snf.f.width = 5;
 * ft_snprintf_char('A', &snf);
 * // buffer -> "    A"
 * // snf.bytes = 5
 * @endcode
 *
 * @see ft_normalize_char_flags()
 * @see put_char_with_flags()
 * @see ft_snprintf_format()
 */
void	ft_snprintf_char(int c, t_snformat *snf)
{
	if (!snf)
		return ;
	ft_normalize_char_flags(&snf->f);
	put_char_with_flags(c, snf);
}
