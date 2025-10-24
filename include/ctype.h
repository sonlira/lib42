/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:18:20 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/15 22:24:55 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTYPE_H
# define CTYPE_H

/* ************************************************************************** */
/*                FUNCIONES DE CLASIFICACIÓN DE CARACTERES (CTYPE)            */
/* ************************************************************************** */

/**
 * Estas funciones evalúan caracteres individuales.
 * No modifican memoria ni dependen de cadenas completas.
 * Devuelven true o false según el tipo de carácter evaluado.
 */

bool	ft_isalpha(int c);
bool	ft_isdigit(int c);
bool	ft_isalnum(int c);
bool	ft_isascii(int c);
bool	ft_isprint(int c);
bool	ft_isspace(int c); // # add

#endif
