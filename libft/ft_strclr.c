/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:52:39 by tbui              #+#    #+#             */
/*   Updated: 2015/11/25 14:53:37 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_strclr(char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
}