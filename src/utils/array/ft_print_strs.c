/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:52:38 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 19:12:13 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

/**
 * @brief Función para imprimir arrays de cadenas con opciones de formato.
 *
 * Esta función recorre un array de cadenas terminado en NULL e imprime cada
 * elemento en una nueva línea. Permite mostrar el número de elemento, su índice
 * y el total de elementos al final, según las opciones indicadas.
 *
 * Ejemplo de salida:
 * @code
 * 1. [0] Hola
 * 2. [1] Mundo
 * Total: 2
 * @endcode
 *
 * @param array       Array de cadenas terminado en NULL (char **).
 * @param with_index  Si es true, imprime el índice entre corchetes antes 
 * de cada cadena.
 * @param show_num    Si es true, imprime un número enumerando cada línea 
 * (comenzando en 1).
 * @param with_total  Si es true, imprime el total de cadenas al finalizar.
 *
 * @return El número total de cadenas impresas.
 *
 * @note Si @p array es NULL, la función imprime "(null array)" en stderr
 *       y devuelve 0.
 */
size_t	ft_putstrs_op(
	char **array,
	bool with_index,
	bool show_num,
	bool with_total
)
{
	size_t	i;

	if (!array)
	{
		ft_putendl_fd("(null array)", STDERR_FILENO);
		return (0);
	}
	i = 0;
	while (array[i])
	{
		if (show_num)
			ft_printf("%u. ", (unsigned int)(i + 1));
		if (with_index)
			ft_printf("[%u] ", (unsigned int)i);
		ft_putendl_fd(array[i], STDOUT_FILENO);
		i++;
	}
	if (with_total)
		ft_printf("Total: %u\n", (unsigned int)i);
	return (i);
}

/**
 * @brief Imprime un array de cadenas de forma simple.
 *
 * @details
 * Imprime cada string del array seguido de un salto de línea.
 * Internamente utiliza `ft_print_strs()` con todas las opciones
 * desactivadas, por lo que no muestra índices ni conteos.
 *
 * @param array Array de cadenas terminado en NULL.
 * @return size_t Número total de cadenas impresas.
 */
size_t	ft_putstrs(char **array)
{
	return (ft_putstrs_op(array, false, false, false));
}
