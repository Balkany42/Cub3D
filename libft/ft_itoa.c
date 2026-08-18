/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <mgrager@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 05:07:55 by mgrager           #+#    #+#             */
/*   Updated: 2025/11/20 18:54:46 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_compteur(long int n);

char	*ft_itoa(int n)
{
	int			compteur;
	long int	nb;
	char		*str;

	nb = n;
		compteur = ft_compteur(nb);
	if (nb < 0)
		nb = -nb;
	str = (char *)malloc((sizeof (char)) * (compteur + 1));
	if (str == 0)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[compteur] = '\0';
	while (nb > 0)
	{
		compteur--;
		str[compteur] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

long int	ft_compteur(long int n)
{
	long int	compteur;

	compteur = 0;
	if (n < 0)
	{
		compteur++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		compteur++;
	}
	if (compteur == 0)
		compteur++;
	return (compteur);
}
