/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:07:53 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/24 14:36:43 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Crea una matriz bidimensional dinámica con opción de terminador NULL.
 *
 * La función ft_create_matrix() reserva memoria para una matriz de `rows`
 * filas y `cols` columnas, donde cada elemento ocupa `size` bytes.
 * Todas las posiciones se inicializan a cero mediante ft_calloc().
 *
 * Si `add_null` es true, se reserva una posición adicional al final del
 * array de filas y se inicializa automáticamente con NULL, lo que permite
 * tratar la matriz como un array de punteros terminado en NULL.
 *
 * @param rows Número de filas de la matriz.
 * @param cols Número de columnas de la matriz.
 * @param size Tamaño, en bytes, de cada elemento.
 * @param add_null Si es true, añade un puntero NULL al final del array.
 *
 * @return Un puntero a la matriz recién creada, o NULL si ocurre un error
 *         de memoria durante la reserva.
 *
 * @note Si alguna asignación falla, se libera toda la memoria reservada
 *       mediante ft_free_array_n_ret().
 * 		En caso de ser una matrix de int se puede usar
 * 	   ft_sfree_matrix() o ft_free_matrix().
 *
 * @see ft_calloc(), ft_free_array_n_ret(), ft_arraylen()
 */
void	**ft_create_matrix(size_t rows, size_t cols, size_t size, bool add_null)
{
	void	**m;
	size_t	i;

	m = ft_calloc(rows + add_null, sizeof(*m));
	if (!m)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		m[i] = ft_calloc(cols, size);
		if (!m[i])
			return (ft_free_array_n_ret(m, rows));
		i++;
	}
	return (m);
}

/**
 * @brief Crea una matriz bidimensional sin terminador NULL.
 *
 * Esta función es un envoltorio (*wrapper*) de conveniencia para
 * ft_create_matrix(), que llama internamente con el parámetro
 * `add_null = false`. Crea una matriz de `rows` filas y `cols`
 * columnas, donde cada elemento ocupa `size` bytes.
 *
 * @param rows Número de filas de la matriz.
 * @param cols Número de columnas de la matriz.
 * @param size Tamaño, en bytes, de cada elemento.
 *
 * @return Un puntero a la matriz recién creada, o NULL si ocurre un error
 *         de memoria durante la reserva.
 *
 * @note La matriz devuelta **no** contiene un puntero NULL al final.
 *       Por lo tanto, no debe liberarse mediante ft_free_array(),
 *       sino con una función que libere un número fijo de filas,
 *       como ft_free_array_n_ret() o similar.
 * 		En caso de ser una matrix de int se puede usar
 * 	   ft_sfree_matrix() o ft_free_matrix().
 *
 * @see ft_create_matrix(), ft_free_array_n_ret()
 */
void	**ft_create_matrix_raw(size_t rows, size_t cols, size_t size)
{
	return (ft_create_matrix(rows, cols, size, false));
}

/**
 * @brief Crea una matriz bidimensional terminada en NULL.
 *
 * Esta función es un envoltorio (*wrapper*) de conveniencia para
 * ft_create_matrix(), que llama internamente con el parámetro
 * `add_null = true`. Crea una matriz de `rows` filas y `cols`
 * columnas, donde cada elemento ocupa `size` bytes, e incluye
 * un puntero NULL al final del array de filas.
 *
 * @param rows Número de filas de la matriz.
 * @param cols Número de columnas de la matriz.
 * @param size Tamaño, en bytes, de cada elemento.
 *
 * @return Un puntero a la matriz recién creada, o NULL si ocurre un error
 *         de memoria durante la reserva.
 *
 * @note La matriz resultante termina con un puntero NULL, lo que permite
 *       usar funciones genéricas como ft_arraylen() o ft_free_array()
 *       para contar o liberar las filas automáticamente.
 *
 * @see ft_create_matrix(), ft_free_array(), ft_arraylen()
 */
void	**ft_create_matrix_null(size_t rows, size_t cols, size_t size)
{
	return (ft_create_matrix(rows, cols, size, true));
}

/**
 * @brief Libera de forma segura una matriz bidimensional de enteros.
 *
 * @details
 * Esta función libera una matriz de punteros (`int **`) y, además, 
 * pone el puntero original a `NULL` tras liberar su contenido.
 *
 * Si se conoce el número de filas @p n, se usa @ref ft_free_array_n();  
 * de lo contrario, @ref ft_free_array() asume una matriz terminada en `NULL`.
 *
 * @param matrix  Puntero triple a la matriz (`int ***`), que será 
 * liberado y puesto a `NULL`.
 * @param n       Número de filas de la matriz.  
 *                 Si es 0, se asume que la matriz está terminada en `NULL`.
 *
 * @note
 * - Si @p matrix o `*matrix` es `NULL`, no hace nada.  
 * - Equivalente a `free()` múltiple con anulación del puntero original.
 *
 * @example
 * @code
 * int **m = ft_create_matrix(3, 4);
 * ft_sfree_matrix(&m, 3);
 * // m == NULL
 * @endcode
 *
 * @see ft_free_array()
 * @see ft_free_array_n()
 */
void	ft_sfree_matrix(int ***matrix, size_t n)
{
	if (!matrix || !*matrix)
		return ;
	if (n > 0)
		ft_free_array_n((void ***)matrix, n);
	else
		ft_free_array((void ***)matrix);
}

/**
 * @brief Libera una matriz bidimensional de enteros sin anular el puntero.
 *
 * @details
 * Libera cada fila y la matriz principal, pero no modifica el puntero original.
 * Si se conoce el número de filas @p n, se usa @ref ft_free_array_n_ret();  
 * de lo contrario, @ref ft_free_array_ret() libera hasta encontrar `NULL`.
 *
 * @param matrix  Matriz bidimensional (`int **`) a liberar.
 * @param n       Número de filas de la matriz.  
 *                 Si es 0, se asume que la matriz está terminada en `NULL`.
 *
 * @note
 * - Si @p matrix o `*matrix` es `NULL`, no realiza ninguna acción.  
 * - No pone @p matrix a `NULL` tras la liberación.
 *
 * @example
 * @code
 * int **m = ft_create_matrix(3, 4);
 * ft_free_matrix(m, 3);
 * // m sigue apuntando a memoria no válida (no se anula)
 * @endcode
 *
 * @see ft_free_array_ret()
 * @see ft_free_array_n_ret()
 */
void	ft_free_matrix(int **matrix, size_t n)
{
	if (!matrix || !*matrix)
		return ;
	if (n > 0)
		ft_free_array_n_ret((void **)matrix, n);
	else
		ft_free_array_ret((void **)matrix);
}
