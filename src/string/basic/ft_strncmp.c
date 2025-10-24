/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:50:17 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/12 18:41:03 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Compara dos cadenas de caracteres hasta un número máximo de bytes.
 *
 * Recorre las cadenas `s1` y `s2` carácter por carácter, comparándolas como
 * valores `unsigned char`, hasta encontrar una diferencia o hasta alcanzar el
 * límite de bytes indicado por `n`. Devuelve la diferencia numérica entre los
 * primeros caracteres distintos encontrados.
 *
 * Si ambas cadenas son idénticas durante los primeros `n` caracteres, la función
 * devuelve `0`. Si `s1` es lexicográficamente menor que `s2`, el valor será
 * negativo; si es mayor, será positivo.
 *
 * A diferencia de otras funciones “_safe_”, esta versión **no realiza 
 * comprobaciones
 * de punteros nulos**, siguiendo la semántica de la función estándar `strncmp`.
 * Pasar punteros inválidos provoca comportamiento indefinido.
 *
 * @param s1  Puntero a la primera cadena de caracteres a comparar.
 * @param s2  Puntero a la segunda cadena de caracteres a comparar.
 * @param n   Número máximo de caracteres a comparar.
 *
 * @return Un valor negativo, cero o positivo según el resultado de la 
 * comparación:
 *         - `< 0` → `s1` es menor que `s2`.
 *         - `0`   → Las cadenas son iguales hasta `n` caracteres.
 *         - `> 0` → `s1` es mayor que `s2`.
 *
 * @note La comparación se detiene al llegar a un carácter nulo (`'\0'`) o cuando
 *       se alcanza el límite `n`. El resultado depende del orden ASCII de los
 *       caracteres comparados.
 *
 * @example
 * ft_strncmp("Hola", "Hilo", 1); // → 0       (iguales hasta el primer carácter)
 * ft_strncmp("Hola", "Hilo", 2); // → positivo ('o' - 'i' = 111 - 105)
 */
ssize_t	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
