/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf_unum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:28:12 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 19:04:32 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static void	put_dot_precision(uint32_t un, char *unum, t_snformat *snf)
{
	if (snf->f.dot && !snf->f.precision && !un)
		return ;
	ft_putnchar_to_snf('0', snf->f.precision - ft_strlen(unum), snf);
	ft_putstr_to_snf(unum, snf);
}

static ssize_t	effective_num_length(uint32_t un, t_flags *f)
{
	ssize_t	len;

	if (f->dot && !f->precision && !un)
		return (0);
	len = ft_unumlen_base(un, BASE_DEC);
	if (f->dot && f->precision > len)
		len = f->precision;
	return (len);
}

static void	put_unum_with_flags(uint32_t un, char *unum, t_snformat *snf)
{
	ssize_t	len;

	len = effective_num_length(un, &snf->f);
	if (snf->f.minus)
	{
		put_dot_precision(un, unum, snf);
		ft_putnchar_to_snf(' ', snf->f.width - len, snf);
	}
	else
	{
		if (snf->f.zero && !snf->f.dot)
		{
			ft_putnchar_to_snf('0', snf->f.width - len, snf);
			ft_putstr_to_snf(unum, snf);
		}
		else
		{
			ft_putnchar_to_snf(' ', snf->f.width - len, snf);
			put_dot_precision(un, unum, snf);
		}
	}
}

/**
 * @brief Escribe un número entero sin signo en formato decimal dentro del 
 * buffer de @ref t_snformat.
 *
 * @details
 * Gestiona la conversión del tipo `'u'` dentro de @ref ft_snprintf(), 
 * escribiendo directamente en el buffer controlado por @p snf.
 *
 * Antes de generar la cadena, normaliza las banderas mediante 
 * @ref ft_normalize_unum_flags(), eliminando aquellas que no son válidas
 * para enteros sin signo (`+`, ` `, `#`).
 *
 * Luego convierte el valor @p un a su representación decimal mediante 
 * @c ft_itoa_base() usando la base @c BASE_DEC.  
 * Si la conversión falla (por falta de memoria), la función retorna sin 
 * escribir nada.
 *
 * Finalmente, delega la escritura en @c put_unum_with_flags(), que aplica 
 * las banderas de formato (`0`, `-`, `width`, `precision`, etc.) y actualiza
 * el estado del buffer (posición y conteo de bytes).
 *
 * @param un   Valor entero sin signo (de tipo @c uint32_t) a escribir.
 * @param snf  Puntero a la estructura @ref t_snformat que contiene el buffer 
 *             y las banderas de formato activas.
 *
 * @return Nada.  
 * La estructura @p snf se actualiza internamente 
 * (posición, bytes escritos, etc.).
 *
 * @note
 * - Si @p snf es NULL, la función no realiza ninguna operación.  
 * - Las banderas `+`, ` ` y `#` se desactivan automáticamente.  
 * - La bandera `0` se ignora si se especifica precisión (`.`).  
 * - La cadena temporal generada por @c ft_itoa_base() se libera al final.
 *
 * @example
 * @code
 * t_snformat snf;
 * init_snformat(&snf);
 * snf.f.type = 'u';
 * snf.f.width = 8;
 * ft_snprintf_unum(12345u, &snf);
 * // buffer -> "   12345"
 * // snf.bytes = 8
 * @endcode
 *
 * @see ft_normalize_unum_flags()
 * @see ft_itoa_base()
 * @see put_unum_with_flags()
 * @see ft_snprintf_format()
 */
void	ft_snprintf_unum(uint32_t un, t_snformat *snf)
{
	char	*unum;

	if (!snf)
		return ;
	ft_normalize_unum_flags(&snf->f);
	unum = ft_itoa_base(un, BASE_DEC_STR);
	if (!unum)
		return ;
	put_unum_with_flags(un, unum, snf);
	free(unum);
}
