/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:16:16 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/24 16:17:14 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>   //Funciones POSIX: read, write, close, fork, etc.
# include <limits.h>   //Límites de tipos primitivos (INT_MAX, LONG_MIN, etc.)
# include <stdint.h>   //Tipos enteros con tamaño fijo (int8_t, uint64_t, etc.)
# include <stdlib.h>   //Utilidades generales: malloc, free, exit, atoi, etc.
# include <stdbool.h>  //Tipo booleano y valores true/false
# include <stdarg.h>   //Manejo de argumentos variables(va_list, va_start, etc.)
# include <sys/types.h>//Tipos del sistema (pid_t, size_t, off_t, mode_t, etc.)
# include <fcntl.h>    //Control de archivos: open, O_RDONLY, O_CREAT, etc.

#endif
