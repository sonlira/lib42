/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_srts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:58:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/24 15:17:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Libera de forma segura un array de punteros de cadenas (fuentes).
 *
 * @details
 * Libera todos los elementos del array y el propio array, 
 * estableciendo el puntero original en `NULL` tras la liberación.
 * 
 * Si @p array o `*array` es `NULL`, no realiza ninguna acción.
 *
 * @param array  Puntero triple a un array de cadenas (`char ***`), 
 *               que será liberado y puesto a `NULL`.
 *
 * @note
 * - Equivalente a una versión “safe” de @ref ft_free_srcs().  
 * - Se recomienda usar esta función cuando el puntero original 
 *   debe quedar invalidado para evitar referencias colgantes.
 *
 * @example
 * @code
 * char **srcs = ft_arraydup((const char *[]){"a", "b", "c", NULL});
 * ft_sfree_srcs(&srcs);
 * // srcs == NULL
 * @endcode
 *
 * @see ft_free_array()
 * @see ft_free_srcs()
 */
void	ft_sfree_srts(char ***array)
{
	if (!array || !*array)
		return ;
	ft_free_array((void ***)array);
}

/**
 * @brief Libera un array de cadenas (fuentes) sin anular el puntero original.
 *
 * @details
 * Libera todos los elementos del array y luego el propio array,
 * pero no modifica el valor del puntero original.
 *
 * Si @p array o `*array` es `NULL`, no realiza ninguna acción.
 *
 * @param array  Array de cadenas terminado en `NULL`.
 *
 * @note
 * - Equivalente a liberar manualmente con `free()` cada elemento y luego el 
 * 	 array.  
 * - Usa internamente @ref ft_free_array_ret().
 *
 * @example
 * @code
 * char **srcs = ft_arraydup((const char *[]){"a", "b", "c", NULL});
 * ft_free_srcs(srcs);
 * // srcs sigue apuntando a memoria no válida (no se anula)
 * @endcode
 *
 * @see ft_free_array_ret()
 * @see ft_sfree_srcs()
 */
void	ft_free_srts(char **array)
{
	if (!array || !*array)
		return ;
	ft_free_array_ret((void **)array);
}

/**
 * @brief Libera un array de cadenas (fuentes) y devuelve `NULL`.
 *
 * @details
 * Versión retornable de @ref ft_free_srcs().  
 * Libera todos los elementos del array y el propio array, devolviendo `NULL`
 * para permitir un retorno limpio en funciones que fallan.
 *
 * Si @p array o `*array` es `NULL`, no realiza ninguna acción y devuelve `NULL`.
 *
 * @param array  Array de cadenas terminado en `NULL`.
 *
 * @return Siempre devuelve `NULL`, lo que permite simplificar el manejo de 
 * errores.
 *
 * @example
 * @code
 * char **srcs = ft_arraydup((const char *[]){"a", "b", "c", NULL});
 * if (error)
 *     return (ft_free_srcs_ret(srcs)); // libera y devuelve NULL
 * @endcode
 *
 * @see ft_free_array_ret()
 * @see ft_free_srcs()
 */
void	*ft_free_srts_ret(char **array)
{
	if (!array || !*array)
		return (NULL);
	return (ft_free_array_ret((void **)array));
}
