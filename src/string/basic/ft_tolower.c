/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:19:22 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/13 17:21:38 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Convierte un carácter mayúsculo a minúsculo si corresponde.
 *
 * Si el valor recibido representa una letra mayúscula en ASCII ('A'–'Z'),
 * se devuelve su equivalente en minúscula ('a'–'z'). En cualquier otro caso,
 * se devuelve el mismo valor sin modificarlo.
 *
 * @param c Valor decimal del carácter a evaluar.
 *
 * @return El carácter convertido a minúscula si era mayúscula;
 *         en caso contrario, el mismo valor recibido.
 *
 * @note Se utiliza el tipo `int` para aceptar todos los valores posibles de
 *       `unsigned char` y el valor especial `EOF`, evitando desbordamientos
 *       o comportamientos indefinidos con caracteres extendidos 
 * 		 (por ejemplo, 'ñ').
 *
 * @example
 * ft_tolower('A'); // -> 'a'
 * ft_tolower('a'); // -> 'a'
 * ft_tolower('1'); // -> '1'
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
