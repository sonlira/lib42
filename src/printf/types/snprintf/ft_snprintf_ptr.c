/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:27:22 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 20:53:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_internal.h"

static void	put_prufix(char *ptr_addres, t_snformat *snf)
{
	if (ft_strcmp(ptr_addres, "(nil)"))
		ft_putstr_to_snf("0x", snf);
}

static ssize_t	effective_num_length(void *ptr)
{
	if (!ptr)
		return (ft_strlen_safe("(nil)"));
	return (ft_unumlen_base((uint64_t)ptr, BASE_HEX) + 2);
}

static void	put_ptr_with_flags(void *ptr, char *ptr_addres, t_snformat *snf)
{
	ssize_t	len;

	len = effective_num_length(ptr);
	if (snf->f.minus)
	{
		put_prufix(ptr_addres, snf);
		ft_putstr_to_snf(ptr_addres, snf);
		ft_putnchar_to_snf(' ', snf->f.width - len, snf);
	}
	else
	{
		ft_putnchar_to_snf(' ', snf->f.width - len, snf);
		put_prufix(ptr_addres, snf);
		ft_putstr_to_snf(ptr_addres, snf);
	}
}

/**
 * @brief Escribe un puntero de memoria en formato hexadecimal dentro del buffer 
 * de @ref t_snformat.
 *
 * @details
 * Gestiona la conversión del tipo `'p'` dentro de @ref ft_snprintf(), 
 * escribiendo directamente en el buffer controlado por @p snf.
 *
 * Antes de imprimir, normaliza las banderas mediante 
 * @ref ft_normalize_ptr_flags(), desactivando aquellas que no tienen efecto
 * sobre punteros (`+`, `#`, ` `, `0`, `.`).
 *
 * Si el puntero @p ptr es @c NULL, se genera la cadena literal <tt>"(nil)"</tt>,
 * tal como lo hace la función `printf("%p", NULL)` estándar.  
 * En caso contrario, convierte la dirección de memoria a su representación
 * hexadecimal (en minúsculas) mediante @c ft_itoa_base().
 *
 * Finalmente, la función delega la escritura en @c put_ptr_with_flags(), 
 * que aplica las banderas de alineación (`-`) y anchura (`width`), y 
 * escribe el resultado en el buffer gestionado por @p snf`.
 *
 * @param ptr  Puntero que se desea imprimir (de tipo @c void*).
 * @param snf  Puntero a la estructura @ref t_snformat que contiene el buffer 
 *             y las banderas de formato activas.
 *
 * @return Nada.  
 * La estructura @p snf se actualiza internamente 
 * (posición, bytes escritos, etc.).
 *
 * @note
 * - Si @p snf es NULL, la función no realiza ninguna operación.  
 * - Si @p ptr es NULL, imprime "(nil)".  
 * - Siempre utiliza letras minúsculas (`a-f`) para la conversión.  
 * - La memoria temporal generada por @c ft_strdup() o @c ft_itoa_base()
 *   se libera al final de la función.
 *
 * @example
 * @code
 * t_snformat snf;
 * init_snformat(&snf);
 * snf.f.type = 'p';
 * ft_snprintf_ptr((void *)0x7ffeefbff5b8, &snf);
 * // buffer -> "0x7ffeefbff5b8"
 * // snf.bytes = 14
 * @endcode
 *
 * @see ft_normalize_ptr_flags()
 * @see ft_itoa_base()
 * @see put_ptr_with_flags()
 * @see ft_snprintf_format()
 */
void	ft_snprintf_ptr(void *ptr, t_snformat *snf)
{
	char	*ptr_addres;

	if (!snf)
		return ;
	ft_normalize_ptr_flags(&snf->f);
	if (!ptr)
		ptr_addres = ft_strdup("(nil)");
	else
		ptr_addres = ft_itoa_base((uint64_t)ptr, BASE_HEX_LOWER_STR);
	if (!ptr_addres)
		return ;
	put_ptr_with_flags(ptr, ptr_addres, snf);
	free(ptr_addres);
}
