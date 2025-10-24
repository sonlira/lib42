/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:09:00 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 17:32:20 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Convierte un carácter minúsculo a mayúsculo si corresponde.
 *
 * Si el valor recibido representa una letra minúscula en ASCII ('a'–'z'),
 * se devuelve su equivalente en mayúscula ('A'–'Z'). En cualquier otro caso,
 * se devuelve el mismo valor sin modificarlo.
 *
 * @param c Valor decimal del carácter a evaluar.
 *
 * @return El carácter convertido a mayúscula si era minúscula;
 *         en caso contrario, el mismo valor recibido.
 *
 * @note Se utiliza el tipo `int` para aceptar todos los valores posibles de
 *       `unsigned char` y el valor especial `EOF`, evitando desbordamientos
 *       o comportamientos indefinidos con caracteres extendidos
 *       (por ejemplo, 'ñ').
 *
 * @example
 * ft_toupper('A'); // -> 'A'
 * ft_toupper('a'); // -> 'A'
 * ft_toupper('1'); // -> '1'
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
