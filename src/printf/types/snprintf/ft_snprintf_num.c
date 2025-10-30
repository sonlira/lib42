/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:27:17 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 20:53:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static void	put_signed(bool neg, t_snformat *snf)
{
	if (neg)
		return (ft_putchar_to_snf('-', snf));
	if (snf->f.plus)
		return (ft_putchar_to_snf('+', snf));
	if (snf->f.space)
		return (ft_putchar_to_snf(' ', snf));
}

static void	put_dot_precision(uint32_t un, char *num, bool neg, t_snformat *snf)
{
	if (snf->f.dot && !snf->f.precision && !un)
		return ;
	put_signed(neg, snf);
	ft_putnchar_to_snf('0', snf->f.precision - ft_strlen_safe(num), snf);
	ft_putstr_to_snf(num, snf);
}

static ssize_t	effective_num_length(uint32_t un, bool neg, t_flags *f)
{
	ssize_t	len;

	if (f->dot && !f->precision && !un)
		return (0);
	len = ft_unumlen_base(un, BASE_DEC);
	if (f->dot && f->precision > len)
		len = f->precision;
	if (neg || f->plus || f->space)
		++len;
	return (len);
}

static void	put_num_with_flags(uint32_t un, char *num, bool neg, \
	t_snformat *snf)
{
	ssize_t	len;

	len = effective_num_length(un, neg, &snf->f);
	if (snf->f.minus)
	{
		put_dot_precision(un, num, neg, snf);
		ft_putnchar_to_snf(' ', snf->f.width - len, snf);
	}
	else
	{
		if (snf->f.zero && !snf->f.dot)
		{
			put_signed(neg, snf);
			ft_putnchar_to_snf('0', snf->f.width - len, snf);
			ft_putstr_to_snf(num, snf);
		}
		else
		{
			ft_putnchar_to_snf(' ', snf->f.width - len, snf);
			put_dot_precision(un, num, neg, snf);
		}
	}
}

/**
 * @brief Escribe un número entero con signo en el buffer de @ref t_snformat.
 *
 * @details
 * Gestiona las conversiones de tipo `'d'` y `'i'` dentro de @ref ft_snprintf(),
 * escribiendo directamente en el buffer controlado por @p snf.
 *
 * La función convierte el valor @p n a positivo (si es negativo) y almacena
 * el estado del signo en la variable local @p neg.  
 * Posteriormente, convierte el número a una cadena decimal mediante 
 * @c ft_itoa_base() usando @c BASE_DEC_STR como base.
 *
 * Antes de escribir, normaliza las banderas de formato mediante 
 * @ref ft_normalize_num_flags(), desactivando combinaciones no válidas
 * (`0` con precisión o `-`, `#` en números con signo, etc.).
 *
 * Finalmente, delega la escritura en @c put_num_with_flags(), que aplica 
 * las banderas de signo (`+`, ` `), alineación (`-`), relleno (`0`), 
 * anchura (`width`) y precisión (`.`), escribiendo el resultado en el buffer.
 *
 * @param n    Valor entero (con signo) a escribir.
 * @param snf  Puntero a la estructura @ref t_snformat que contiene el buffer 
 *             y las banderas de formato activas.
 *
 * @return Nada.  
 * La estructura @p snf se actualiza internamente 
 * (posición, bytes escritos, etc.).
 *
 * @note
 * - Si @p snf es NULL, la función no realiza ninguna operación.  
 * - Si @p n es negativo, el signo se maneja manualmente y no forma parte de la 
 * cadena devuelta por @c ft_itoa_base().  
 * - La bandera `+` imprime explícitamente el signo positivo.  
 * - La bandera ` ` (espacio) imprime un espacio para números positivos si `+` 
 * no está activa.
 *
 * @example
 * @code
 * t_snformat snf;
 * init_snformat(&snf);
 * snf.f.type = 'd';
 * snf.f.plus = true;
 * ft_snprintf_num(-42, &snf);
 * // buffer -> "-42"
 * // snf.bytes = 3
 * @endcode
 *
 * @see ft_normalize_num_flags()
 * @see ft_itoa_base()
 * @see put_num_with_flags()
 * @see ft_snprintf_format()
 */
void	ft_snprintf_num(int n, t_snformat *snf)
{
	long	un;
	bool	neg;
	char	*num;

	if (!snf)
		return ;
	un = n;
	neg = (n < 0);
	if (neg)
		un = -un;
	num = ft_itoa_base(un, BASE_DEC_STR);
	if (!num)
		return ;
	ft_normalize_num_flags(&snf->f);
	put_num_with_flags(un, num, neg, snf);
}
