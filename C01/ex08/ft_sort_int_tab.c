/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:02:12 by egrazina          #+#    #+#             */
/*   Updated: 2020/10/26 20:02:18 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int var;
	int var1;
	int var2;

	var = 0;
	while (var < size)
	{
		var1 = var + 1;
		while (var1 < size)
		{
			if (tab[var1] < tab[var])
			{
				var2 = tab[var];
				tab[var] = tab[var1];
				tab[var1] = var2;
			}
			var1++;
		}
		var++;
	}
}

int main()
{
    printf("\nTesting 08:\n\n");
    int arr1[9] = {5, 2, 3, 4, 1, 9, 8, 7, 6};
    ft_sort_int_tab(arr1, 9);
    for(int i = 0; i < 9; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}