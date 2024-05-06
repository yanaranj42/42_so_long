/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:06:47 by yanaranj          #+#    #+#             */
/*   Updated: 2024/01/30 11:52:10 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 'newlst': keeps the references for the beggining of the list
 * 'newnode': new node to move through list. 
 * 'tmp': void variable to apply f function
 * WHILE: save the aply function (that affects to every element of the list)
 * 		  inside 'tmp'.
 * 		  'newnode' creates a new node with tmp (calling ft_lstnew).
 * 		  IF: it fails while creating the new node, delete 'tmp' and free the
 * 		  allocated memory of the whole list.(cannot create a copy)
 * 		  ELSE: add the 'newnode' at the end of the list, create a copy while
 * 		  iterate throgh the list
 * RETURN: 'newlst', the pointer to the fist element of the new list.
 *
void	*f(void *cont)
{
	int i;
	char *s;
	char *res;

	s = (void *)cont;
	res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (res)
	{
		i = -1;
		while(s[++i])
		{
			res[i] = s[i] + 1;
		}
		res[i] = '\0';
		return ((void *)res);
	}
	return NULL;
}

void	*del(void *cont)
{
	char *s;

	s = (void *) cont;
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (NULL);
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	void	*tmp;

	newlst = NULL;
	newnode = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		tmp = (f)(lst->content);
		newnode = ft_lstnew(tmp);
		if (!newnode)
		{
			ft_lstclear(&newlst, del);
			free(tmp);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&newlst, newnode);
			lst = lst->next;
		}
	}
	return (newlst);
}

/*
int main ()
{
	t_list *ptr;
	t_list *ptrmap;
	t_list *mylist;
	t_list *node = malloc(sizeof(t_list));
	node->content = ft_strdup("Unicornios!");
	node->next = malloc(sizeof(t_list));
	node->next->content = ft_strdup("Lagartos!");
	node->next->next = malloc(sizeof(t_list));
	node->next->next->content = ft_strdup("gtf");
	node->next->next->next = NULL;

	int i = 0;
	mylist = node;
	ptrmap = node;
	while(mylist)
	{
		printf("old list [%i] ----> |%s|\n", i++, (char *)mylist->content);
		mylist = mylist->next;
	}
	ptr = ft_lstmap(ptrmap, (void *)f, (void *)del);
	i = 0;
	while(ptr)
	{
		printf("\nnew list [%i] ----> |%s|\n", i++, (char *)ptr->content);
		ptr = ptr->next;
	}
	return (0);
}*/
