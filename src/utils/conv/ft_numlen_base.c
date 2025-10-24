/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:37:20 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 10:56:47 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Calcula la cantidad de dígitos necesarios para representar
 *        un número entero en una base determinada.
 *
 * @details
 * Esta función cuenta cuántos caracteres se necesitan para imprimir
 * un número (`num`) en la base especificada (`base`).
 * 
 * Si `count_signed` es verdadero, se incluye un carácter adicional
 * en el conteo cuando el número es negativo (para el signo '-').
 *
 * Internamente maneja correctamente el caso de `LONG_MIN`, evitando
 * overflow al convertir el número a un valor absoluto sin signo
 * mediante la expresión `(-1 * (num + 1)) + 1` o '(-((num + 1))) + 1'
 * ambas son iguales.
 *
 * @param num          Número a analizar.
 * @param base         Base numérica (debe ser >= 2).
 * @param count_signed Si es `true`, incluye el signo en el conteo
 *                     si el número es negativo.
 *
 * @return La cantidad de caracteres necesarios para representar
 *         el número en la base indicada. Devuelve 0 si la base es menor que 2.
 * @example
 * Ejemplos:
 *       - `ft_numlen_base(0, 10, false)`  → 1  
 *       - `ft_numlen_base(-42, 10, false)` → 2  
 *       - `ft_numlen_base(-42, 10, true)`  → 3  
 *       - `ft_numlen_base(255, 16, false)` → 2
 */
size_t	ft_numlen_base(long long num, size_t base, bool count_signed)
{
	size_t		count;
	uint64_t	un;

	count = 0;
	if (base < 2)
		return (0);
	if (num == 0)
		return (1);
	if (num < 0)
	{
		un = (uint64_t)(-1 * (num + 1)) + 1;
		if (count_signed)
			++count;
	}
	else
		un = (uint64_t)num;
	while (un)
	{
		un /= base;
		++count;
	}
	return (count);
}

/**
 * @brief Calcula la cantidad de dígitos necesarios para representar
 *        un número sin signo en una base determinada.
 *
 * @details
 * Esta función cuenta cuántos caracteres se necesitan para imprimir
 * un número (`num`) en la base especificada (`base`).
 *
 * @param num          Número a analizar.
 * @param base         Base numérica (debe ser >= 2).
 *
 * @return La cantidad de caracteres necesarios para representar
 *         el número en la base indicada. Devuelve 0 si la base es menor que 2.
 * @example
 * Ejemplos:
 *       - `ft_numlen_base(0, 10)`  → 1  
 *       - `ft_numlen_base(42, 10)` → 2    
 *       - `ft_numlen_base(255, 16)` → 2
 */
size_t	ft_unumlen_base(uint64_t num, size_t base)
{
	size_t		count;

	count = 0;
	if (base < 2)
		return (0);
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		++count;
	}
	return (count);
}
