/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:16:27 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 17:24:38 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/* ************************************************************************** */
/*                          FUNCIONES PRINCIPALES PRINTF                      */
/* ************************************************************************** */

/**
 * Implementaciones de printf personalizadas.
 * 
 * Estas funciones permiten imprimir texto formateado en distintos
 * descriptores de archivo (stdout, stderr, etc.), soportando banderas,
 * tipos de datos y formatos personalizados.
 */

ssize_t		ft_printf(const char *format, ...);
ssize_t		ft_eprintf(const char *format, ...);


/* ************************************************************************** */
/*                          FUNCIONES PRINCIPALES SNPRINTF                    */
/* ************************************************************************** */

/**
 * Versiones de las funciones printf adaptadas para escribir en un buffer
 * de tamaño limitado (similar a snprintf).
 * 
 * No escriben en un descriptor de archivo, sino directamente en memoria.
 */

ssize_t		ft_snprintf(char *s, size_t n, char *format, ...);

#endif