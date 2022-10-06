#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: pointer to the dlistint_t list.
 * @n: data to be added at the begning
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *h;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		for (; h->prev != NULL;)
			h = h->prev;
	}
	new_node->next = h;
	if (h != NULL)
		h->prev = new_node;
	*head = new_node;
	return (new_node);
}

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: pointer to the dlistint_t list.
 * @n: data to be added at the end
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *h;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;
	h = *head;

	if (h == NULL)
	{
		*head = new_node;
	}
	else
	{
		for (; h->next != NULL;)
			h = h->next;
		h->next = new_node;
	}
	new_node->prev = h;
	return (new_node);
}
