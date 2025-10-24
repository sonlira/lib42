/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:18:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/20 18:19:52 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef FD_MAX
/**
 * @brief Número máximo de descriptores de archivo admitidos.
 *
 * Define la cantidad máxima de descriptores (`fd`) que pueden ser gestionados
 * simultáneamente por `get_next_line()`. Cada descriptor mantiene su propio
 * almacenamiento interno.
 *
 * @note 1024 es el valor estándar en sistemas UNIX.
 */
#  define FD_MAX 1024
# endif

# ifndef BUFFER_SIZE
/**
 * @brief Tamaño del búfer de lectura utilizado por `read()`.
 *
 * Define la cantidad de bytes leídos en cada llamada al sistema.
 * Un valor mayor puede mejorar el rendimiento al reducir llamadas a `read()`,
 * pero también aumenta el uso de memoria.
 *
 * @note Puede ajustarse en tiempo de compilación mediante la opción:
 * `-D BUFFER_SIZE=<valor>`.
 */
#  define BUFFER_SIZE 5
# endif

/* ************************************************************************** */
/*                FUNCIONES DE LECTURA DE LÍNEAS (GET_NEXT_LINE)              */
/* ************************************************************************** */

/**
 * Estas funciones gestionan la lectura de archivos línea a línea.
 * Mantienen un almacenamiento interno por descriptor (`fd`) que
 * conserva los datos no procesados entre llamadas sucesivas.
 */

char	*get_next_line(int fd);
void	get_next_line_free(int fd); // # add

#endif
