/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:27:26 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 20:53:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static ssize_t	effective_str_length(char *s, t_flags *f)
{
	ssize_t	len;

	len = ft_strlen_safe(s);
	if (f->dot && f->precision < len)
		len = f->precision;
	return (len);
}

static void	put_str_with_flags(char *s, t_snformat *snf)
{
	ssize_t	len;

	len = effective_str_length(s, &snf->f);
	if (snf->f.minus)
	{
		ft_putstrl_to_snf(s, len, snf);
		ft_putnchar_to_snf(' ', snf->f.width - len, snf);
	}
	else
	{
		ft_putnchar_to_snf(' ', snf->f.width - len, snf);
		ft_putstrl_to_snf(s, len, snf);
	}
}

/**
 * @brief Escribe una cadena de texto en el buffer de @ref t_snformat 
 * aplicando las banderas de formato.
 *
 * @details
 * Gestiona la conversión del tipo `'s'` dentro de @ref ft_snprintf(), 
 * escribiendo directamente en el buffer gestionado por @p snf.
 *
 * Antes de imprimir, normaliza las banderas mediante 
 * @ref ft_normalize_str_flags(), desactivando aquellas que no son válidas 
 * para cadenas (`0`, `+`, `#`, ` `).  
 *
 * Si el puntero @p s es @c NULL, se sustituye por la cadena literal 
 * <tt>"(null)"</tt>, manteniendo compatibilidad con el comportamiento estándar 
 * de `printf("%s", NULL)`.
 *
 * La impresión real se delega a @c put_str_with_flags(), que aplica las 
 * banderas de alineación (`-`), anchura (`width`) y precisión (`.`) antes 
 * de escribir en el buffer.
 *
 * @param s    Cadena de texto a escribir (terminada en '\0').
 * @param snf  Puntero a la estructura @ref t_snformat que contiene el buffer 
 *             y las banderas de formato activas.
 *
 * @return Nada.  
 * La estructura @p snf se actualiza internamente 
 * (posición, bytes escritos, etc.).
 *
 * @note
 * - Si @p snf es NULL, la función no realiza ninguna operación.  
 * - Si @p s es NULL, se imprime "(null)".  
 * - La bandera `.` (precisión) limita el número de caracteres escritos.  
 * - Las banderas `+`, `#`, ` ` y `0` no tienen efecto sobre cadenas.
 *
 * @example
 * @code
 * t_snformat snf;
 * init_snformat(&snf);
 * snf.f.width = 10;
 * snf.f.minus = true;
 * ft_snprintf_str("Hola", &snf);
 * // buffer -> "Hola      "
 * // snf.bytes = 10
 * @endcode
 *
 * @see ft_normalize_str_flags()
 * @see put_str_with_flags()
 * @see ft_snprintf_format()
 */
void	ft_snprintf_str(char *s, t_snformat *snf)
{
	if (!snf)
		return ;
	ft_normalize_str_flags(&snf->f);
	if (!s)
		s = "(null)";
	put_str_with_flags(s, snf);
}
