/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:13:19 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 18:59:23 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Libera un array de punteros terminado en NULL.
 *
 * @details
 * Recorre el array de punteros hasta encontrar un elemento NULL, liberando
 * cada elemento con `ft_free` y luego el propio array principal.
 * Tras la llamada, el puntero original queda anulado (NULL) para evitar
 * accesos inválidos.
 *
 * Esta función asume que el array fue asignado dinámicamente y que cada
 * elemento también fue reservado mediante `malloc` o equivalente.
 *
 * @param array Triple puntero al array de punteros 
 * (por ejemplo, `(void ***)&arr`).
 *
 * @note
 * Debe usarse solo con arrays **terminados en NULL**.  
 * Para pasar el array correctamente, se recomienda usar:
 * ```c
 * ft_free_array((void ***)&array);
 * ```
 *
 * @example
 * ### Ejemplo — Liberar array de cadenas dinámicas
 * @code
 * // Crear array dinámico de 3 cadenas + terminador NULL
 * char **arr = malloc(4 * sizeof(char *));
 * arr[0] = malloc(6);
 * arr[1] = malloc(6);
 * arr[2] = malloc(6);
 * arr[3] = NULL;
 *
 * ft_free_array((void ***)&arr);
 * // arr == NULL
 * @endcode
 */
void	ft_free_array(void ***array)
{
	size_t	i;

	if (!array || !*array)
		return ;
	i = 0;
	while ((*array)[i])
	{
		ft_free(&(*array)[i]);
		i++;
	}
	ft_free(*array);
}

/**
 * @brief Libera un array terminado en NULL y devuelve siempre NULL.
 *
 * @details
 * Igual que `ft_free_array`, pero diseñada para expresiones de retorno.
 * Libera cada elemento, luego el array principal, y devuelve siempre NULL.
 * Útil para liberar memoria al final de una función con un simple `return`.
 *
 * @param array Doble puntero al array de punteros terminado en NULL.
 * @return Siempre devuelve NULL.
 *
 * @note
 * Usar cuando se desea liberar memoria dentro de una función
 * y devolver NULL directamente:
 * ```c
 * return (ft_free_array_ret(array));
 * ```
 *
 * @example
 * ### Ejemplo — Retorno inmediato con liberación
 * @code
 * char **arr = malloc(3 * sizeof(char *));
 * arr[0] = malloc(5);
 * arr[1] = malloc(5);
 * arr[2] = NULL;
 *
 * if (error)
 *     return (ft_free_array_ret(arr));
 * @endcode
 */
void	*ft_free_array_ret(void **array)
{
	size_t	i;

	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
	{
		ft_free(&array[i]);
		i++;
	}
	return (ft_free_ret(array));
}

/**
 * @brief Libera un array de punteros de tamaño conocido.
 *
 * @details
 * Libera los `n` primeros elementos del array y luego el propio array principal.
 * Se utiliza cuando el array **no está terminado en NULL**, pero su tamaño
 * (`n`) es conocido.
 *
 * @param array Triple puntero al array de punteros 
 * (por ejemplo, `(void ***)&arr`).
 * @param n     Número de elementos a liberar.
 *
 * @note
 * Debe usarse cuando el array no tiene terminador NULL, por ejemplo:
 * ```c
 * ft_free_array_n((void ***)&array, 3);
 * ```
 *
 * @example
 * ### Ejemplo — Liberar matriz de punteros de tamaño fijo
 * @code
 * int **nums = malloc(3 * sizeof(int *));
 * nums[0] = malloc(4 * sizeof(int));
 * nums[1] = malloc(4 * sizeof(int));
 * nums[2] = malloc(4 * sizeof(int));
 *
 * ft_free_array_n((void ***)&nums, 3);
 * // nums == NULL
 * @endcode
 */
void	ft_free_array_n(void ***array, size_t n)
{
	size_t	i;

	if (!array || !*array)
		return ;
	i = 0;
	while (i < n)
	{
		ft_free(&(*array)[i]);
		i++;
	}
	ft_free(*array);
}

/**
 * @brief Libera un array de punteros de tamaño conocido y devuelve NULL.
 *
 * @details
 * Versión equivalente a `ft_free_array_n`, pero diseñada para expresiones
 * de retorno. Libera `n` elementos y el array principal, devolviendo NULL.
 *
 * @param array Doble puntero al array de punteros.
 * @param n     Número de elementos a liberar.
 * @return Siempre devuelve NULL.
 *
 * @note
 * Útil para liberar memoria en funciones que devuelven NULL tras error:
 * ```c
 * return (ft_free_array_n_ret(array, 3));
 * ```
 *
 * @example
 * ### Ejemplo — Retorno tras liberar una matriz parcial
 * @code
 * int **matrix = malloc(3 * sizeof(int *));
 * matrix[0] = malloc(4 * sizeof(int));
 * matrix[1] = malloc(4 * sizeof(int));
 * matrix[2] = malloc(4 * sizeof(int));
 *
 * if (error)
 *     return (ft_free_array_n_ret(matrix, 3));
 * @endcode
 */
void	*ft_free_array_n_ret(void **array, size_t n)
{
	size_t	i;

	if (!array)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ft_free(&array[i]);
		i++;
	}
	return (ft_free_ret(array));
}
