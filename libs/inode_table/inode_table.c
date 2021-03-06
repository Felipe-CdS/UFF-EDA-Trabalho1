/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:43:21 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 20:05:49 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inode_table.h"

t_itable	*it_new(int id, char *filename)
{
	t_itable	*new;

	if (!id)
		return (NULL);
	new = (t_itable *) malloc(sizeof(t_itable));
	if (!new)
		return (NULL);
	new->id = id;
	new->filename = strdup(filename);
	new->next = NULL;
	return (new);
}

t_itable	*it_last(t_itable *start)
{
	if (!start)
		return (NULL);
	if (!start->next)
		return (start);
	return (it_last(start->next));
}

void	it_add_front(t_itable **start, t_itable *new)
{
	new->next = *start;
	*start = new;
}

void	it_add_back(t_itable **start, t_itable *new)
{
	t_itable	*last;

	last = it_last(*start);
	if (last)
		last->next = new;
	else
		*start = new;
}

void	it_remove(t_itable **start, t_itable *target)
{
	t_itable	*x;
	t_itable	*previous;

	x = (*start);
	previous = NULL;	
	while (x && x != target)
	{
		previous = x;
		x = x->next;
	}
	if (x)
	{
		if(previous)
			previous->next = x->next;
		else
			*start = x->next; 
		free(x->filename);
		free(x);
	}
}

void	it_clear(t_itable **start)
{
	t_itable	*p;
	t_itable	*q;

	p = (*start);
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*start = NULL;
}

int	it_size(t_itable *start)
{
	if (!start)
		return (0);
	return (it_size(start->next) + 1);
}

t_itable	*it_search(t_itable *start, char *filename)
{
	if(!start) 
		return (NULL);
	if(!strcmp(start->filename, filename)) 
		return (start);
	return it_search(start->next, filename);
}

void	it_print(t_itable **start)
{
	t_itable	*p;
	
	p = NULL;
	p = (*start);
	printf("+---------------------------------------+\n");
	printf("|\t\ti-nodes Table\t\t|\n");
	printf("+---------------------------------------+\n");
	printf("| ID | %-33s|\n", "FILENAME");
	printf("+---------------------------------------+\n");
	while (p)
	{
		printf("| %03d | %-32s|\n", p->id, p->filename);
		p = p->next;
	}
	printf("+---------------------------------------+\n");
}
