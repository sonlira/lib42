/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:50:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 19:54:44 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Libera un array de cadenas creado por `ft_split` y lo pone a `NULL`.
 *
 * Libera cada una de las subcadenas almacenadas en el array y, finalmente,
 * libera el propio array. Además, asigna `NULL` al puntero original para evitar
 * punteros colgantes.
 *
 * @param split  Triple puntero que referencia el array a liberar.
 *               Debe llamarse como `ft_free_split(&array)`.
 *
 * @note Esta versión es más segura, ya que evita el acceso a memoria liberada
 *       al dejar el puntero original en `NULL`. Sin embargo, requiere pasar
 *       la dirección del puntero (`&array`) al llamar a la función.
 *
 * @example
 * char **words = ft_split("Hola mundo", ' ');
 * ft_free_split(&words);
 * // Ahora `words == NULL`
 */
void	ft_sfree_split(char ***split)
{
	if (!split || !*split)
		return ;
	ft_free_array((void ***)split);
}

/**
 * @brief Libera un array de cadenas generado por @ref ft_split().
 *
 * @details
 * Libera cada elemento del array (cada cadena) y luego el propio array.  
 * No devuelve ningún valor y no modifica el puntero original.
 *
 * Si @p split o `*split` es `NULL`, la función no realiza ninguna acción.
 *
 * @param split  Array de cadenas terminado en `NULL` (como el devuelto por 
 * @ref ft_split()).
 *
 * @note
 * - Equivalente a liberar con `free()` cada cadena más el array principal.  
 * - No pone @p split a `NULL` tras liberar.  
 * - Usa internamente @ref ft_free_array_ret().
 *
 * @example
 * @code
 * char **words = ft_split("Hola mundo", ' ');
 * // ... usar words ...
 * ft_free_split(words);
 * @endcode
 *
 */
void	ft_free_split(char **split)
{
	if (!split || !*split)
		return ;
	ft_free_array_ret((void **)split);
}

/**
 * @brief Libera un array de cadenas generado por @ref ft_split() y 
 * devuelve `NULL`.
 *
 * @details
 * Versión retornable de @ref ft_free_split().  
 * Libera todas las cadenas del array y el array principal, devolviendo el 
 * valor retornado por @ref ft_free_array_ret() (generalmente `NULL`), 
 * lo que permite usar esta función en expresiones de retorno.
 *
 * Si @p split o `*split` es `NULL`, no realiza ninguna acción y devuelve `NULL`.
 *
 * @param split  Array de cadenas terminado en `NULL`.
 *
 * @return Siempre devuelve `NULL`, permitiendo simplificar el retorno tras
 *  liberar memoria.
 *
 * @example
 * @code
 * char **words = ft_split("Hola mundo", ' ');
 * if (!words)
 *     return (NULL);
 * if (error)
 *     return (ft_free_split_ret(words)); // libera y devuelve NULL
 * @endcode
 *
 */
void	*ft_free_split_ret(char **split)
{
	if (!split || !*split)
		return (NULL);
	return (ft_free_array_ret((void **)split));
}
