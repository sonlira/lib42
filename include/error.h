/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:08:12 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/23 18:50:26 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
/**
 * @brief Código de error genérico utilizado en el proyecto.
 *
 * @details
 * Este valor se emplea en funciones que devuelven conteos, longitudes o bytes 
 * escritos, donde un resultado negativo indica un fallo en la operación.  
 * 
 * Se usa principalmente para:
 * - Detectar punteros no válidos o nulos.
 * - Fallos de asignación de memoria.
 * - Errores de escritura o lectura.
 *
 * No debe utilizarse en funciones de comparación ni en aquellas donde `-1` 
 * pueda ser un valor válido de retorno.
 *
 * @example
 * @code
 * ssize_t result = ft_printf("Hola %s\n", name);
 * if (result == FT_ERROR)
 *     return (handle_error());
 * @endcode
 *
 * @note
 * Sigue la convención de las funciones del sistema (por ejemplo, `write()`, 
 * `read()`, `printf()`), donde `-1` representa un error genérico.  
 * Equivalente a @c -1.
 */
# define FT_ERROR -1

#endif
