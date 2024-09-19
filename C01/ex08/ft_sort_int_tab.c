/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro- <jopedro-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:21:32 by jopedro-          #+#    #+#             */
/*   Updated: 2024/09/09 10:10:30 by jopedro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	b;
	int	i;
	int	tmp;

	i = 0;
	b = 1;
	while (b)
	{
		b = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				b = 1;
			}
			++i;
		}
	}
}

/*int	main(void)
{
	int tab[6] = {9, 8, 23, 4, 2, 6};
	ft_sort_int_tab(tab, 6);
}*/
