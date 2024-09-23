/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:44:13 by jopedro-          #+#    #+#             */
/*   Updated: 2024/09/19 09:34:40 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H

#ifdef FT_BOOLEAN_H

#include <unistd.h>

#define TRUE 		1
#define FALSE 		0
#define EVEN(nbr)	is_even(nbr)
static inline int is_even(int x) {
	return (x % 2 == 0);
}
#define EVEN_MSG	"I have an even number of arguments.\n"
#define ODD_MSG		"I have an odd number of arguments.\n"

typedef int		t_bool;

#endif
