#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIFO 1
#define LIFO 2
#define FILO 3

struct Node
{
    int element;
    struct Node *next;
};

typedef struct
{
    struct Node *head;
    struct Node *tail;
    unsigned int size;
    unsigned int type;
} LinkedList;

int linked_list_init(LinkedList *ll, unsigned int ll_type)
{
    if (ll_type != 1 && ll_type != 2 && ll_type != 3)
    {
        return -1;
    }

    ll->size = 0;
    ll->head = NULL;
    ll->tail = NULL;
    ll->type = ll_type;
}

int linked_list_push(LinkedList *ll, int element)
{
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));

    ll->size++;
    node->element = element;
    if (ll->type == 1 || ll->type == 3)
    {
        if (ll->head != NULL)
        {
            node->next = ll->head;
        }
        else
        {
            ll->tail = node;
        }
        ll->head = node;
    }
    else
    {
        if (ll->tail != NULL)
        {
            ll->tail->next = node;
        }
        else
        {
            ll->head = node;
        }
        ll->tail = node;
    }
    return 0;
}

// This function search for a node which in next attribute have the same as next parameter
struct Node *linked_list_get_node_with_next_pointing_to(LinkedList *ll, struct Node *next)
{

    if (ll->head == NULL)
    {
        return NULL;
    }

    struct Node *node;

    node = ll->head;

    while (node->next != NULL)
    {
        if (node->next == next)
        {
            return node;
        }
        node = node->next;
    }

    return NULL;
}

int linked_list_pop(LinkedList *ll, int *element_pointer)
{
    if (ll->size <= 0)
    {
        return -1;
    }

    if (ll->type == 1 || ll->type == 2)
    {
        *element_pointer = ll->head->element;
        free(ll->head);
        ll->head = ll->head->next;
    }
    else
    {
        *element_pointer = ll->tail->element;
        free(ll->tail);
        struct Node *tail;
        if ((tail = linked_list_get_node_with_next_pointing_to(ll, ll->tail)) != NULL)
        {
            ll->tail = tail;
            tail->next = NULL;
        }
    }

    ll->size--;
    return 0;
}

void linked_list_print(LinkedList *ll)
{
    if (ll->head == NULL)
        return;

    struct Node *n = ll->head;
    printf("Linkedlist elements: ");
    while (n->next != NULL)
    {
        printf(" %d ", n->element);
        n = n->next;
    }
    printf(" %d \n", n->element);
}

void main()
{
    LinkedList ll;
    linked_list_init(&ll, FILO);
    linked_list_push(&ll, 10);
    linked_list_push(&ll, 20);
    linked_list_push(&ll, 30);
    linked_list_print(&ll);
    int msg;
    linked_list_pop(&ll, &msg);
    linked_list_print(&ll);
}