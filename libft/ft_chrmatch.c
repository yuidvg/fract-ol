/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:37:01 by ynishimu          #+#    #+#             */
/*   Updated: 2023/02/25 14:42:00 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_chrmatch(char c, char *targets)
{
	while (targets)
	{
		if (c == *targets)
			return (true);
		targets++;
	}
	return (false);
}
