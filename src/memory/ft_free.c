/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:02:20 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/15 21:25:53 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Libera memoria y pone el puntero original a NULL.
 *
 * @details
 * Esta función recibe **un doble puntero** (`void **`) al bloque de memoria
 * que se desea liberar. Primero libera la memoria apuntada, y luego asigna
 * `NULL` al puntero original, evitando punteros colgantes.
 *
 * Es diferente de `free(ptr)` porque también **anula el puntero original**.
 *
 * @param ptr Doble puntero al bloque de memoria a liberar.
 *
 * @note
 * - Si `ptr` o `*ptr` son NULL, no hace nada.
 * - Se usa para liberar variables que deben quedar anuladas tras 
 * 	 liberar memoria.
 * - Para pasar un puntero normal, **debes castear su dirección a `void **`**:
 *   ```c
 *   char *str = malloc(20);
 *   ft_free((void **)&str);
 *   ```
 *   Esto permite que la función modifique el puntero original y lo deje en NULL.
 *
 * @example
 * ### Ejemplo 1 — Liberar un puntero y anularlo
 * @code
 * char *str = malloc(10);
 * if (!str)
 *     return ;
 * ft_free((void **)&str);
 * // Ahora 'str' == NULL, no apunta a memoria liberada.
 * @endcode
 *
 * ### Ejemplo 2 — Comparación con free normal
 * @code
 * char *s1 = malloc(5);
 * char *s2 = malloc(5);
 * free(s1);          // s1 ahora apunta a memoria inválida
 * ft_free((void **)&s2); // s2 ahora es NULL
 * @endcode
 */
void	ft_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * @brief Libera memoria y devuelve siempre NULL.
 *
 * @details
 * Esta función libera el puntero recibido (si no es NULL) y retorna NULL.
 * Es útil para liberar memoria dentro de funciones que deben **retornar NULL**
 * al fallar, evitando escribir dos líneas (`free` + `return NULL`).
 *
 * A diferencia de `ft_free`, esta función **no modifica el puntero original**,
 * solo lo libera. Su propósito es simplificar retornos.
 *
 * @param ptr Puntero al bloque de memoria a liberar.
 * @return Siempre devuelve NULL.
 *
 * @note
 * Ideal para usar en expresiones de retorno directo:
 * ```c
 * if (error)
 *     return (ft_free_ret(ptr));
 * ```
 *
 * @example
 * ### Ejemplo — Diferencia con ft_free
 * @code
 * char *s1 = malloc(10);
 * char *s2 = malloc(10);
 *
 * s1 = ft_free_ret(s1);
 * // s1 == NULL (retorno explícito)
 *
 * ft_free((void **)&s2);
 * // s2 == NULL (modificado por referencia)
 * @endcode
 */
void	*ft_free_ret(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}
