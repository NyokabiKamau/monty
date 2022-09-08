#include "monty.h"
#include "lists.h"

/**
 * insert_d_node_index - inserts a node at a given index
 * in a doubly linked list
 * @h: double pointer to the list
 * @index: index of the node to insert
 * @n: data to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
d_linked_t *insert_d_node_index(d_linked_t **h, unsigned int index, int n)
{
	unsigned int i;
	d_linked_t *new;
	d_linked_t *temp = *h;

	if (index == 0)
		return (add_d_node(h, n));

	for (i = 0; temp && i < index; i++)
	{
		if (i == index - 1)
		{
			if (temp->next == NULL)
				return (add_d_node_end(h, n));
			new = malloc(sizeof(d_linked_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

/**
 * add_d_node_end - adds a new node at the end of a doubly linked list
 * @head: double pointer to the list
 * @n: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
d_linked_t *add_d_node_end(d_linked_t **head, const int n)
{
	d_linked_t *new;
	d_linked_t *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(d_linked_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}

/**
 * free_d_linked - frees a doubly linked list
 * @head: pointer to the list to free
 */
void free_d_linked(d_linked_t *head)
{
	d_linked_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
