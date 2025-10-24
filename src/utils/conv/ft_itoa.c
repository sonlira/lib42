/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:05:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/24 14:37:02 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Convierte un número entero en una cadena de caracteres.
 *
 * @details
 * La función ft_itoa() toma un valor entero `n` y devuelve una cadena de
 * caracteres recién asignada que representa dicho número en base 10.
 * Incluye el signo '-' en caso de que el número sea negativo.
 *
 * Internamente, la función convierte el número a tipo `long` para evitar
 * desbordamientos al manejar el valor absoluto de `INT_MIN`. Utiliza
 * memoria dinámica mediante `ft_calloc()` para crear la cadena resultante,
 * que debe liberarse con `free()` cuando ya no se necesite.
 *
 * @param n El número entero que se desea convertir.
 *
 * @return Un puntero a la cadena resultante con la representación decimal
 *         del número. Devuelve `NULL` si la asignación de memoria falla.
 *
 * @note Si `n` es 0, la función devuelve la cadena `"0"`.
 *       La memoria devuelta debe ser liberada manualmente con `free()`
 *       para evitar fugas de memoria.
 *
 */
char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	size_t	size;

	num = n;
	size = ft_numlen_base(num, BASE_DEC, true);
	result = ft_calloc(size + 1, sizeof(*result));
	if (!result)
		return (NULL);
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		num = -num;
		result[0] = '-';
	}
	while (num)
	{
		result[--size] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
