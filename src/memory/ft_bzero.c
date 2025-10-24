/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:11:24 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/15 18:18:06 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Rellena un bloque de memoria con ceros.
 *
 * @param s Puntero al bloque de memoria que se desea limpiar.
 * @param n Cantidad de bytes a establecer en cero.
 *
 * @note Función segura: valida el puntero antes de acceder a memoria.
 *       No realiza ninguna acción si `s` es NULL o `n` es 0.
 * @example
 *     char buffer[10];
 *     ft_bzero(buffer, sizeof(buffer));
 *     // buffer ahora contiene diez bytes en 0.
 */
void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	ft_memset(s, 0, n);
}
