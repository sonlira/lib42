/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 00:51:00 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 21:04:03 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Reemplaza el contenido de un puntero de cadena por otro.
 *
 * Esta función libera la cadena previamente asignada en `*dst` (si existe)
 * y luego asigna directamente el puntero `src` al destino, sin realizar
 * una duplicación de memoria (`strdup`).
 *
 * Es útil cuando se desea transferir la propiedad de un puntero de cadena
 * ya asignado dinámicamente, evitando una copia innecesaria.
 *
 * @param dst Doble puntero a la cadena de destino.
 *            Si `*dst` no es NULL, su memoria será liberada 
 *            antes de la asignación.
 * @param src Puntero a la nueva cadena que se asignará a `*dst`.
 *            Puede ser NULL, en cuyo caso `*dst` quedará como NULL.
 *
 * @return
 * - `true` si la operación se realizó correctamente.
 * - `false` si `dst` es NULL (puntero inválido).
 *
 * @note Esta función **no duplica** el contenido de `src`, 
 *       solo transfiere el puntero.
 *       El llamador pierde la propiedad de `src` 
 *       después de llamar a esta función.
 *
 * @example
 * @code
 * char *text = ft_strdup("Hola");
 * char *new  = ft_strdup("Adiós");
 *
 * ft_strreplace(&text, new);
 * // Ahora 'text' apunta a "Adiós" y la memoria de "Hola" fue liberada.
 * // 'new' ya no debe usarse directamente.
 * @endcode
 */
bool	ft_strreplace(char **dst, char *src)
{
	if (!dst)
		return (false);
	ft_free_safe((void **)dst);
	*dst = src;
	return (true);
}

/**
 * @brief Reemplaza una cadena solo si la nueva asignación es válida.
 *
 * Versión segura de `ft_strreplace()`.  
 * Esta función verifica que tanto `dst` como `src` sean válidos antes de
 * realizar la reasignación.  
 * Si `src` es NULL, no libera ni modifica `*dst`, evitando pérdida de datos.
 *
 * @param dst Doble puntero a la cadena de destino.  
 *            Si es NULL, la función devuelve false sin modificar nada.
 * @param src Puntero a la nueva cadena que se desea asignar.  
 *            Si es NULL, no se realiza ninguna acción.
 *
 * @return
 * - `true` si se reemplazó correctamente el contenido de `*dst`.
 * - `false` si `dst` o `src` son NULL.
 *
 * @note Esta función es ideal cuando se usa junto con `ft_strdup()`
 *       para evitar liberar memoria si la asignación falla:
 *       @code
 *       if (!ft_strreplace_safe(&line, ft_strdup("texto")))
 *           return (error());
 *       @endcode
 *
 * @see ft_strreplace
 */
bool	ft_strreplace_safe(char **dst, char *src)
{
	if (!dst || !src)
		return (false);
	return (ft_strreplace(dst, src));
}
