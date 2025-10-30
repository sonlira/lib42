/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:20:51 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/30 17:33:13 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_INTERNAL_H
# define PRINTF_INTERNAL_H

# include "lib42.h"

/**
 * @struct s_flags
 * @brief Representa todas las banderas y parámetros de formato para una 
 *        conversión de printf.
 * @details
 * Esta estructura almacena toda la información obtenida al analizar
 * una secuencia de formato del tipo `%[flags][width][.precision][type]`.
 * 
 * Se utiliza para controlar el comportamiento de impresión en ft_printf,
 * incluyendo alineación, relleno, signos, prefijos y precisión numérica.
 */
typedef struct s_flags
{
	bool	minus; // '-' flag: alinea el texto a la izquierda.
	bool	zero; // '0' flag: rellena con ceros en lugar de espacios.
	bool	hash; // '#' flag: añade prefijo (0x, 0X, etc.) en hex/octal.
	bool	space;// ' ' flag: inserta un espacio delante de números positivos.
	bool	plus; // '+' flag: muestra siempre el signo '+' o '-'.
	bool	dot; //'.' flag: indica presencia de precisión.
	int		width; // Ancho mínimo del campo.
	int		precision;//Precisión: número mínimo de dígitos o máximo de chars.
	char	type; //Tipo de conversión: 'd', 'i', 'x', 'X', 's', 'c', etc.
}	t_flags;

/**
 * @struct s_snformat
 * @brief Estructura que almacena el estado interno de ft_snprintf.
 *
 * @details
 * Contiene toda la información necesaria para gestionar la escritura 
 * formateada en un buffer limitado, simulando el comportamiento de `snprintf`.
 * 
 * Los campos permiten llevar control sobre las banderas de formato,
 * la posición actual de escritura, el tamaño máximo permitido, y el total 
 * de bytes escritos durante la operación.
 */
typedef struct s_snformat
{
	t_flags	f; // Estructura con las banderas de formato
	char	*s; // Puntero al buffer destino
	size_t	n; // Tamaño máximo permitido (n)
	size_t	i; // Posición actual de escritura
	ssize_t	bytes; // Total de bytes escritos
}	t_snformat;

/* ************************************************************************** */
/*                          FUNCIONES DE GESTIÓN DE FLAGS                     */
/* ************************************************************************** */

/**
 * Estas funciones se encargan de analizar, inicializar y normalizar
 * las banderas utilizadas por las funciones ft_printf y ft_snprintf.
 * 
 * Incluyen tanto el análisis del formato como la validación de tipos
 * y la preparación de estructuras auxiliares.
 */

const char	*ft_printf_flags(const char *s, t_flags *f);
bool		ft_isflag_simple(int c);
bool		ft_is_valid_type(int c);
bool		init_flags(t_flags *f);
bool		init_snformat(t_snformat *snf);

void		ft_normalize_char_flags(t_flags *f);
void		ft_normalize_num_flags(t_flags *f);
void		ft_normalize_unum_flags(t_flags *f);
void		ft_normalize_ptr_flags(t_flags *f);
void		ft_normalize_str_flags(t_flags *f);

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

ssize_t		ft_printf_format(t_flags *f, va_list *vlist, int fd);

/* ************************************************************************** */
/*                      FUNCIONES DE FORMATEO DE TIPOS (PRINTF)               */
/* ************************************************************************** */

/**
 * Estas funciones imprimen tipos de datos específicos según las banderas
 * configuradas en la estructura t_flags.
 */

ssize_t		ft_printf_char(int c, t_flags *f, int fd);
ssize_t		ft_printf_str(char *s, t_flags *f, int fd);
ssize_t		ft_printf_num(int n, t_flags *f, int fd);
ssize_t		ft_printf_unum(uint32_t un, t_flags *f, int fd);
ssize_t		ft_printf_hex(uint32_t un, t_flags *f, int fd);
ssize_t		ft_printf_ptr(void *ptr, t_flags *f, int fd);

/* ************************************************************************** */
/*                          FUNCIONES PRINCIPALES SNPRINTF                    */
/* ************************************************************************** */

/**
 * Versiones de las funciones printf adaptadas para escribir en un buffer
 * de tamaño limitado (similar a snprintf).
 * 
 * No escriben en un descriptor de archivo, sino directamente en memoria.
 */

void		ft_snprintf_format(t_snformat *snf, va_list *vlist);

/* ************************************************************************** */
/*                      FUNCIONES DE FORMATEO DE TIPOS (SNPRINTF)             */
/* ************************************************************************** */

/**
 * Estas funciones escriben en el buffer interno de t_snformat según el tipo.
 * 
 * No retornan el número de caracteres escritos, sino que actualizan
 * los valores internos de la estructura.
 */

void		ft_snprintf_char(int c, t_snformat *snf);
void		ft_snprintf_str(char *s, t_snformat *snf);
void		ft_snprintf_num(int n, t_snformat *snf);
void		ft_snprintf_unum(uint32_t un, t_snformat *snf);
void		ft_snprintf_hex(uint32_t un, t_snformat *snf);
void		ft_snprintf_ptr(void *ptr, t_snformat *snf);

/* ************************************************************************** */
/*                      FUNCIONES DE ESCRITURA EN BUFFER (SNF)                */
/* ************************************************************************** */

/**
 * Estas funciones escriben directamente en el buffer interno de la estructura
 * t_snformat, gestionando el control del tamaño máximo y la posición actual.
 */

void		ft_putchar_to_snf(int c, t_snformat *snf);
void		ft_putnchar_to_snf(int c, ssize_t n, t_snformat *snf);
void		ft_putstr_to_snf(const char *s, t_snformat *snf);
void		ft_putstrl_to_snf(const char *s, ssize_t len, t_snformat *snf);

#endif
