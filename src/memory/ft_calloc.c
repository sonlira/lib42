/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:00:33 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/15 21:12:01 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Reserva memoria para un arreglo e inicializa su contenido a cero.
 *
 * @details
 * Esta función combina dos operaciones:
 * 1. Reserva de memoria dinámica para `count` elementos de tamaño `size`.
 * 2. Inicialización de todos los bytes a cero.
 *
 * Si la reserva falla o los parámetros son demasiado grandes para
 * representarse en memoria, la función devuelve NULL.
 *
 * @param count Número de elementos a reservar.
 * @param size  Tamaño en bytes de cada elemento.
 * @return
 * Puntero a la memoria recién asignada (inicializada a cero),
 * o NULL si la reserva falla o si el tamaño total es inválido.
 *
 * @note
 * - Usa `ft_memset` internamente para rellenar con ceros.
 * - Antes de multiplicar `count * size`, comprueba que el resultado
 *   no exceda la capacidad del sistema.  
 *   Esta verificación **evita errores de desbordamiento**, que ocurren
 *   cuando el resultado es tan grande que “se da la vuelta” y produce
 *   una reserva más pequeña de la esperada.
 *
 * @example
 * ### Ejemplo 1 — Reserva de arreglo de enteros
 * @code
 * int *nums = ft_calloc(5, sizeof(int));
 * // Reserva espacio para 5 enteros e inicializa a 0.
 * @endcode
 *
 * ### Ejemplo 2 — Fallo por desbordamiento
 * @code
 * void *ptr = ft_calloc(SIZE_MAX, SIZE_MAX);
 * // ptr == NULL: la multiplicación sería demasiado grande.
 * @endcode
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc (count * size);
	if (!ptr)
		return (NULL);
	return (ft_memset(ptr, 0, (count * size)));
}
