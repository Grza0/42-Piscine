/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:13:43 by egrazina          #+#    #+#             */
/*   Updated: 2020/10/25 19:13:46 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int swap;

	i = 0;
	while (i < --size)
	{
		swap = tab[i];
		tab[i] = tab[size];
		tab[size] = swap;
		i++;
	}
}

int main()
{
    printf("\nTesting 07:\n\n");
    int arr1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ft_rev_int_tab(arr1, 9);
    for(int i = 0; i < 9; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}