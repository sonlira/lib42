/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:07:53 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 21:30:57 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Crea una matriz bidimensional dinámica con opción de terminador NULL.
 *
 * @details
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
 * @note La matriz devuelta debe liberarse utilizando una de las funciones:
 * @ref ft_free_matrix_safe(), @ref ft_free_matrix() o @ref ft_free_matrix_ret().
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
 * @brief Libera de forma segura una matriz bidimensional.
 *
 * @details
 * Esta función libera una matriz de punteros (`void **`) y, además, 
 * pone el puntero original a `NULL` tras liberar su contenido.
 *
 * Si se conoce el número de filas @p n, se usa @ref ft_free_array_n_safe();  
 * de lo contrario, @ref ft_free_array_safe() asume una matriz terminada en `NULL`.
 *
 * @param matrix  Puntero triple a la matriz (`void ***`), que será 
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
 * int **m = (int **)ft_create_matrix(3, 4, sizeof(int),false);
 * ft_free_matrix((void **)m, 3);
 * // m == NULL
 * @endcode
 *
 * @see ft_free_array_safe()
 * @see ft_free_array_n_safe()
 */
void	ft_free_matrix_safe(void ***matrix, size_t n)
{
	if (!matrix || !*matrix)
		return ;
	if (n > 0)
		ft_free_array_n_safe(matrix, n);
	else
		ft_free_array_safe(matrix);
}

/**
 * @brief Libera una matriz bidimensional sin anular el puntero.
 *
 * @details
 * Libera cada fila y la matriz principal, pero no modifica el puntero original.
 * Si se conoce el número de filas @p n, se usa @ref ft_free_array_n_ret();  
 * de lo contrario, @ref ft_free_array_ret() libera hasta encontrar `NULL`.
 *
 * @param matrix  Matriz bidimensional (`void **`) a liberar.
 * @param n       Número de filas de la matriz.  
 *                Si es 0, se asume que la matriz está terminada en `NULL`.
 *
 * @note
 * - Si @p matrix o `*matrix` es `NULL`, no realiza ninguna acción.  
 * - No pone @p matrix a `NULL` tras la liberación.
 *
 * @example
 * @code
 * int **m = (int **)ft_create_matrix(3, 4, sizeof(int),false);
 * ft_free_matrix((void **)m, 3);
 * // m sigue apuntando a memoria no válida (no se anula)
 * @endcode
 *
 * @see ft_free_array_ret()
 * @see ft_free_array_n_ret()
 */
void	ft_free_matrix(void **matrix, size_t n)
{
	if (!matrix || !*matrix)
		return ;
	ft_free_matrix_safe((void ***)&matrix, n);
}

/**
 * @brief Libera una matriz bidimensional y devuelve `NULL`.
 *
 * @details
 * Libera cada fila y la matriz principal, pero no modifica el puntero original.
 * Si se conoce el número de filas @p n, se utiliza @ref ft_free_array_n_ret();  
 * de lo contrario, @ref ft_free_array_ret() libera hasta encontrar `NULL`.
 *
 * @param matrix  Matriz bidimensional (`void **`) a liberar.
 * @param n       Número de filas de la matriz.  
 *                Si es 0, se asume que la matriz está terminada en `NULL`.
 *
 * @note
 * - Si @p matrix o `*matrix` es `NULL`, no realiza ninguna acción.  
 * - No asigna `NULL` a @p matrix tras la liberación.
 *
 * @return Siempre devuelve `NULL`.
 *
 * @example
 * @code
 * return (ft_free_matrix_ret((void **)m, 3)); // Devuelve NULL
 * @endcode
 *
 * @see ft_free_array_ret()
 * @see ft_free_array_n_ret()
 */
void	*ft_free_matrix_ret(void **matrix, size_t n)
{
	if (!matrix || !*matrix)
		return (NULL);
	if (n > 0)
		return (ft_free_array_n_ret(matrix, n));
	else
		return (ft_free_array_ret(matrix));
}
