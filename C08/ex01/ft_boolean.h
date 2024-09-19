/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:44:13 by jopedro-          #+#    #+#             */
/*   Updated: 2024/09/18 09:53:45 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H

#ifdef FT_BOOLEAN_H

#include <unistd.h>

#define TRUE 		1
#define FALSE 		0
#define EVEN(nbr)	((nbr % 2)? TRUE : FALSE)
#define EVEN_MSG	"I have an even number of arguments.\n"
#define ODD_MSG		"I have an odd number of arguments.\n"

typedef int		t_bool;

#endif
