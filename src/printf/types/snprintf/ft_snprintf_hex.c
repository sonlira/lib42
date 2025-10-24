/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:27:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 18:28:04 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static void	put_prefix(uint32_t un, t_snformat *snf)
{
	if (snf->f.hash && un)
	{
		if (snf->f.type == 'x')
			return (ft_putstr_to_snf("0x", snf));
		else
			return (ft_putstr_to_snf("0X", snf));
	}
}

static void	put_dot_precision(uint32_t un, char *hex, t_snformat *snf)
{
	if (snf->f.dot && !snf->f.precision && !un)
		return ;
	put_prefix(un, snf);
	ft_putnchar_to_snf('0', snf->f.precision - ft_strlen(hex), snf);
	ft_putstr_to_snf(hex, snf);
}

static ssize_t	effective_num_length(uint32_t un, t_flags *f)
{
	ssize_t	len;

	if (f->dot && !f->precision && !un)
		return (0);
	len = ft_unumlen_base(un, BASE_HEX);
	if (f->dot && f->precision > len)
		len = f->precision;
	if (f->hash && un)
		len += 2;
	return (len);
}

static void	put_hex_with_flags(uint32_t un, char *hex, t_snformat *snf)
{
	ssize_t	len;

	len = effective_num_length(un, &snf->f);
	if (snf->f.minus)
	{
		put_dot_precision(un, hex, snf);
		ft_putnchar_to_snf(' ', snf->f.width - len, snf);
	}
	else
	{
		if (snf->f.zero && !snf->f.dot)
		{
			put_prefix(un, snf);
			ft_putnchar_to_snf('0', snf->f.width - len, snf);
			ft_putstr_to_snf(hex, snf);
		}
		else
		{
			ft_putnchar_to_snf(' ', snf->f.width - len, snf);
			put_dot_precision(un, hex, snf);
		}
	}
}

/**
 * @brief Escribe un número sin signo en formato hexadecimal dentro del buffer 
 * de @ref t_snformat.
 *
 * @details
 * Gestiona las conversiones de tipo `'x'` y `'X'` en la versión @ref 
 * ft_snprintf(),
 * escribiendo el resultado directamente en el buffer controlado por @p snf.
 *
 * Antes de generar la cadena, normaliza las banderas con 
 * @ref ft_normalize_unum_flags() para desactivar aquellas no aplicables a 
 * números sin signo (`+`, ` `, etc.).
 *
 * Luego selecciona la base hexadecimal correspondiente (`a-f` o `A-F`)
 * según el tipo (`x` o `X`) y convierte el número @p un a cadena mediante 
 * @c ft_itoa_base().  
 * 
 * Finalmente, llama a @c put_hex_with_flags() para aplicar las banderas de 
 * formato (`#`, `0`, `-`, `width`, `precision`, etc.) y escribir el resultado 
 * en el buffer.  
 * La memoria temporal generada por @c ft_itoa_base() se libera al final.
 *
 * @param un   Valor entero sin signo (de tipo @c uint32_t) a imprimir.
 * @param snf  Puntero a la estructura @ref t_snformat que contiene el buffer
 *             y las banderas de formato activas.
 *
 * @return Nada.  
 * La estructura @p snf se actualiza internamente 
 * (posición, bytes escritos, etc.).
 *
 * @note
 * - Si @p snf es NULL, no realiza ninguna operación.  
 * - La bandera `#` antepone "0x" o "0X" si el valor es distinto de cero.  
 * - La bandera `0` se ignora cuando se especifica precisión.  
 * - La conversión usa letras minúsculas o mayúsculas según `snf->f.type`.
 *
 * @example
 * @code
 * t_snformat snf;
 * init_snformat(&snf);
 * snf.f.type = 'X';
 * snf.f.hash = true;
 * ft_snprintf_hex(3735928559u, &snf);
 * // buffer -> "0XDEADBEEF"
 * // snf.bytes = 10
 * @endcode
 *
 * @see ft_normalize_unum_flags()
 * @see put_hex_with_flags()
 * @see ft_itoa_base()
 * @see ft_snprintf_format()
 */
void	ft_snprintf_hex(uint32_t un, t_snformat *snf)
{
	char	*hex;
	char	*base_hex_str;

	if (!snf)
		return ;
	ft_normalize_unum_flags(&snf->f);
	base_hex_str = BASE_HEX_LOWER_STR;
	if (snf->f.type == 'X')
		base_hex_str = BASE_HEX_UPPER_STR;
	hex = ft_itoa_base(un, base_hex_str);
	if (!hex)
		return ;
	put_hex_with_flags(un, hex, snf);
	free(hex);
}
