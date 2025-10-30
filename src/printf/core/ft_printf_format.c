/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:50:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 17:38:20 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

/**
 * @brief Selecciona y ejecuta la función de impresión adecuada según el tipo de
 *        formato.
 * @details
 * Esta función actúa como un despachador central: a partir del tipo almacenado
 * en la estructura @p t_flags, llama a la función específica que formatea e
 * imprime el valor correspondiente desde la lista de argumentos @p vlist.
 *
 * Soporta los siguientes tipos:
 * - 'c' : carácter
 * - 's' : cadena
 * - 'd' / 'i' : entero con signo
 * - 'u' : entero sin signo
 * - 'x' / 'X' : entero hexadecimal (minúsculas o mayúsculas)
 * - 'p' : puntero (dirección de memoria)
 * - '%' : carácter '%' literal (no consume argumentos)
 *
 * Cada función interna devuelve el número de caracteres escritos, que se acumula
 * posteriormente por ft_printf_core().
 *
 * @param f  Puntero a una estructura @p t_flags con la información del formato.
 * @param vlist  Puntero a la lista de argumentos variables (tipo @c va_list).
 * @param fd Descriptor de archivo donde se escribirá la salida 
 *        (por ejemplo, 1 para stdout).
 *
 * @return El número de caracteres escritos si la conversión fue exitosa,
 *         o @c FT_ERROR (-1) si ocurre un error o el tipo es desconocido.
 *
 * @note No modifica la lista de argumentos en el caso del tipo '%'.
 *
 * @example
 * @par Ejemplo
 * @code
 * va_list args;
 * va_start(args, fmt);
 * t_flags flags;
 * flags.type = 'd';
 * ssize_t printed = ft_printf_format(&flags, &args, 1);
 * va_end(args);
 * // printed contiene el número de caracteres escritos por la conversión '%d'
 * @endcode
 */
ssize_t	ft_printf_format(t_flags *f, va_list *vlist, int fd)
{
	if (!f || !vlist || fd < 0)
		return (FT_ERROR);
	if (f->type == 'c')
		return (ft_printf_char(va_arg(*vlist, int), f, fd));
	if (f->type == 's')
		return (ft_printf_str(va_arg(*vlist, char *), f, fd));
	if (f->type == 'd' || f->type == 'i')
		return (ft_printf_num(va_arg(*vlist, int), f, fd));
	if (f->type == 'u')
		return (ft_printf_unum(va_arg(*vlist, unsigned int), f, fd));
	if (f->type == 'x' || f->type == 'X')
		return (ft_printf_hex(va_arg(*vlist, unsigned int), f, fd));
	if (f->type == 'p')
		return (ft_printf_ptr(va_arg(*vlist, void *), f, fd));
	if (f->type == '%')
		return (ft_printf_char('%', f, fd));
	return (FT_ERROR);
}

/**
 * @brief Selecciona y ejecuta la función de impresión adecuada según el tipo de
 *        formato (versión para escritura en buffer).
 *
 * @details
 * Esta versión de @ref ft_printf_format() trabaja sobre una estructura 
 * @ref t_snformat en lugar de escribir en un descriptor de archivo.
 * 
 * De acuerdo con el tipo de formato almacenado en @p snf->f.type, la función 
 * invoca la rutina correspondiente que escribe el valor formateado directamente 
 * en el buffer de destino.
 *
 * Tipos soportados:
 * - `'c'` : carácter
 * - `'s'` : cadena
 * - `'d'` / `'i'` : entero con signo
 * - `'u'` : entero sin signo
 * - `'x'` / `'X'` : entero hexadecimal
 * - `'p'` : puntero
 * - `'%'` : carácter literal '%'
 *
 * @param snf     Puntero a la estructura @ref t_snformat que controla el buffer.
 * @param vlist   Puntero a la lista de argumentos variable (tipo @c va_list).
 *
 * @return Nada.  
 * La estructura @p snf se actualiza internamente 
 * (posición, bytes escritos, etc.).
 *
 * @note
 * - No devuelve valor, ya que la contabilización se gestiona dentro de @p snf.  
 * - Si el tipo no es reconocido, la función no realiza ninguna operación.
 *
 * @example
 * @code
 * va_list args;
 * va_start(args, fmt);
 * t_snformat snf;
 * init_snformat(&snf);
 * snf->f.type = 'x';
 * ft_snprintf_format(&snf, &args);
 * va_end(args);
 * // snf.s contendrá el valor hexadecimal resultante
 * @endcode
 *
 * @see ft_snprintf_core()
 * @see ft_printf_format()
 */
void	ft_snprintf_format(t_snformat *snf, va_list *vlist)
{
	if (!snf || !vlist)
		return ;
	if (snf->f.type == 'c')
		return (ft_snprintf_char(va_arg(*vlist, int), snf));
	if (snf->f.type == 's')
		return (ft_snprintf_str(va_arg(*vlist, char *), snf));
	if (snf->f.type == 'd' || snf->f.type == 'i')
		return (ft_snprintf_num(va_arg(*vlist, int), snf));
	if (snf->f.type == 'u')
		return (ft_snprintf_unum(va_arg(*vlist, unsigned int), snf));
	if (snf->f.type == 'x' || snf->f.type == 'X')
		return (ft_snprintf_hex(va_arg(*vlist, uint32_t), snf));
	if (snf->f.type == 'p')
		return (ft_snprintf_ptr(va_arg(*vlist, unsigned int *), snf));
	if (snf->f.type == '%')
		return (ft_snprintf_char('%', snf));
}
