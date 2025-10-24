/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strassign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:32:51 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/18 20:47:17 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Reemplaza de forma segura el contenido de una cadena dinámica.
 *
 * Si el puntero `*dest` ya contiene una cadena, se libera y se asigna
 * una nueva copia de `src`. Si ambas cadenas son iguales, no se realiza
 * ningún cambio. En caso de error de memoria, `*dest` permanece intacto.
 *
 * @param dest Doble puntero a la cadena destino (modificable).
 * @param src  Puntero a la cadena fuente (lectura).
 *
 * @return true si la operación fue exitosa; false si hubo error
 *         (punteros inválidos o fallo de reserva de memoria).
 *
 * @note Esta función gestiona memoria dinámica. La cadena resultante debe
 *       liberarse con `free` cuando ya no se utilice.
 *
 * @example
 * char *name = NULL;
 * ft_set_string(&name, "Paco");
 * ft_set_string(&name, "Paco"); // No realoca (igual contenido)
 * ft_set_string(&name, "42 Madrid"); // Reemplaza y libera la anterior
 */
bool	ft_strassign(char **dest, const char *src)
{
	char	*str;

	if (!dest || !src)
		return (false);
	if (*dest && !ft_strcmp(*dest, src))
		return (true);
	str = ft_strdup(src);
	if (!str)
		return (false);
	if (*dest)
		free(*dest);
	*dest = str;
	return (true);
}
