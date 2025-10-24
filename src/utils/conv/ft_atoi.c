/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:04:46 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/21 16:58:38 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Convierte una cadena de caracteres en un número entero.
 *
 * @details
 * La función ft_atoi() analiza la cadena apuntada por `s` y la convierte
 * en un valor entero con signo de tipo `int`. Omite los espacios en blanco
 * iniciales, maneja un signo opcional ('+' o '-') y convierte la secuencia
 * de dígitos posterior en un número entero.
 *
 * @param s Puntero a la cadena terminada en nulo que se desea convertir.
 *          Si `s` es NULL, la función devuelve 0.
 *
 * @return El valor entero convertido.
 *         Devuelve 0 si la cadena es NULL.
 *         Devuelve `INT_MAX` o `INT_MIN` en caso de desbordamiento.
 *
 * @note Si el resultado excede los límites representables por un `int`,
 *       la función devuelve `INT_MAX` o `INT_MIN` según corresponda.
 *       Esta implementación evita comportamientos indefinidos y detiene
 *       la conversión en cuanto detecta un desbordamiento.
 */
int	ft_atoi(const char *s)
{
	long	result;
	int		sign;

	if (!s)
		return (0);
	sign = 1;
	result = 0;
	s = ft_strdrop(s, ft_isspace);
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		result = result * 10 + (*s - '0');
		if (sign == 1 && result > INT_MAX)
			return (INT_MAX);
		if (sign == -1 && result > (long)INT_MAX + 1)
			return (INT_MIN);
		s++;
	}
	return ((int)(result * sign));
}
