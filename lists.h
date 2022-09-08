#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

/* linked_functions1.c */
size_t d_linked_len(const d_linked_t *h);
d_linked_t *add_d_node(d_linked_t **head, const int n);
size_t print_d_linked(const d_linked_t *h);
int delete_d_node_index(d_linked_t **head, unsigned int index);
d_linked_t *get_d_node_index(d_linked_t *head, unsigned int index);

/* linked_functions2.c */
d_linked_t *insert_d_node_index(d_linked_t **h, unsigned int index, int n);
d_linked_t *add_d_node_end(d_linked_t **head, const int n);
void free_d_linked(d_linked_t *head);

#endif
