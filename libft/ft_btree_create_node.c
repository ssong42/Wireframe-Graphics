/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:11:52 by ssong             #+#    #+#             */
/*   Updated: 2017/12/09 15:31:45 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_btree		*ft_btree_create_node(void *item)
{
	t_btree	*tmp;

	tmp = malloc(sizeof(t_btree));
	if (tmp)
	{
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->item = item;
	}
	return (tmp);
}
