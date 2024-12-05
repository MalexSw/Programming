#include <stdlib.h>
#include <stdio.h>

typedef struct data_t {
    int data; // Example data, replace with your struct from Lab 11
} data_t;

typedef struct node_t {
    data_t data;
    struct node_t *next;
    struct node_t *prev;
} node_t;

typedef struct doubly_list_t {
    node_t *head;
    node_t *tail;
} doubly_list_t;

// Function prototypes
void create_list(doubly_list_t **list);
node_t *create_node(data_t data);
void push_front(doubly_list_t *list, data_t data);
void push_back(doubly_list_t *list, data_t data);
void display_list(doubly_list_t *list);
void display_list_reverse(doubly_list_t *list);
void free_list(doubly_list_t **list);
void insert_after(doubly_list_t *list, data_t target, data_t data);
void insert_before(doubly_list_t *list, data_t target, data_t data);
void erase(doubly_list_t *list, data_t target);

// Create an empty list
void create_list(doubly_list_t **list) {
    *list = (doubly_list_t *)malloc(sizeof(doubly_list_t));
    (*list)->head = NULL;
    (*list)->tail = NULL;
}

// Create a new node
node_t *create_node(data_t data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Add a node at the front
void push_front(doubly_list_t *list, data_t data) {
    node_t *node = create_node(data);
    if (list->head == NULL) { // List is empty
        list->head = list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
}

// Add a node at the back
void push_back(doubly_list_t *list, data_t data) {
    node_t *node = create_node(data);
    if (list->tail == NULL) { // List is empty
        list->head = list->tail = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
}

// Display the list
void display_list(doubly_list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        printf("%d <-> ", current->data.data);
        current = current->next;
    }
    printf("NULL\n");
}

// Display the list in reverse order
void display_list_reverse(doubly_list_t *list) {
    node_t *current = list->tail;
    while (current != NULL) {
        printf("%d <-> ", current->data.data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Free the list
void free_list(doubly_list_t **list) {
    node_t *current = (*list)->head;
    while (current != NULL) {
        node_t *for_deletion = current;
        current = current->next;
        free(for_deletion);
    }
    free(*list);
    *list = NULL;
}

// Insert a node after a target node
void insert_after(doubly_list_t *list, data_t target, data_t data) {
    node_t *current = list->head;
    while (current != NULL) {
        if (current->data.data == target.data) {
            node_t *node = create_node(data);
            node->next = current->next;
            node->prev = current;
            if (current->next != NULL) {
                current->next->prev = node;
            } else {
                list->tail = node; // Update tail if at the end
            }
            current->next = node;
            return;
        }
        current = current->next;
    }
}

// Insert a node before a target node
void insert_before(doubly_list_t *list, data_t target, data_t data) {
    node_t *current = list->head;
    while (current != NULL) {
        if (current->data.data == target.data) {
            node_t *node = create_node(data);
            node->next = current;
            node->prev = current->prev;
            if (current->prev != NULL) {
                current->prev->next = node;
            } else {
                list->head = node; // Update head if at the beginning
            }
            current->prev = node;
            return;
        }
        current = current->next;
    }
}

// Erase a target node
void erase(doubly_list_t *list, data_t target) {
    node_t *current = list->head;
    while (current != NULL) {
        if (current->data.data == target.data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next; // Update head if at the beginning
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev; // Update tail if at the end
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

// Main function to test the doubly linked list
int main() {
    doubly_list_t *list;
    create_list(&list);

    // Add nodes
    data_t data = {.data = 10};
    push_front(list, data);
    data.data = 20;
    push_front(list, data);
    data.data = 30;
    push_back(list, data);

    // Display list
    display_list(list);

    // Display list in reverse
    display_list_reverse(list);

    // Insert before and after
    data_t target = {.data = 20};
    data.data = 15;
    insert_before(list, target, data);
    data.data = 25;
    insert_after(list, target, data);

    // Display updated list
    display_list(list);

    // Erase a node
    erase(list, target);

    // Display list after deletion
    display_list(list);

    // Free the list
    free_list(&list);
}
