#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Define the data structure (can replace with your own struct from Lab #11)
typedef struct data_t {
    int data;
} data_t;

// Define the node structure for the singly linked list
typedef struct node_t {
    data_t data;             // Data contained in the node
    struct node_t *next;     // Pointer to the next node
} node_t;

// Define the singly linked list structure with a head node
typedef struct forward_list_t {
    node_t *head;            // Head of the list
} forward_list_t;

// Function prototypes
void push_front(forward_list_t *list, data_t data);
void pop_front(forward_list_t *list);
void display_node(node_t *node);
void display_list(forward_list_t *list);
void free_list(forward_list_t **list);
void create_list(forward_list_t **list);
node_t *create_node(data_t data);
node_t *find(forward_list_t *list, data_t data);
node_t *find_prev_node(forward_list_t *list, data_t data);
void insert_after(forward_list_t *list, data_t target, data_t data);
void insert_before(forward_list_t *list, data_t target, data_t data);
void erase_after(forward_list_t *list, data_t target);
bool is_empty(forward_list_t *list);
bool is_equal(data_t first, data_t second);

// Main function
int main(int argc, char const *argv[]) {
    forward_list_t *list = NULL;
    create_list(&list); // Initialize the list

    // Add elements
    data_t data = {.data = 10};
    push_front(list, data);
    data.data = 20;
    push_front(list, data);
    data.data = 30;
    push_front(list, data);

    data_t target = {.data = 10};
    data.data = 50;
    insert_after(list, target, data);

    // Display elements
    printf("Initial List:\n");
    display_list(list);

    // Find a node and display it
    node_t *found = find(list, target);
    printf("\nFound node with data = %d:\n", target.data);
    display_node(found);

    // Insert before a specific element
    data.data = 75;
    insert_before(list, target, data);
    printf("\nList after inserting 75 before 10:\n");
    display_list(list);

    // Free list memory
    free_list(&list);
    return 0;
}

// Function implementations

// Create a new node
node_t *create_node(data_t data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (!node) {
        perror("Failed to create node");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Initialize the list
void create_list(forward_list_t **list) {
    *list = (forward_list_t *)malloc(sizeof(forward_list_t));
    if (!(*list)) {
        perror("Failed to create list");
        exit(EXIT_FAILURE);
    }
    (*list)->head = NULL; // Initially empty
}

// Add an element to the front of the list
void push_front(forward_list_t *list, data_t data) {
    node_t *node = create_node(data);
    node->next = list->head; // Point to the current head
    list->head = node;       // Update head to the new node
}

// Remove the front element of the list
void pop_front(forward_list_t *list) {
    if (list->head == NULL) {
        return; // List is empty
    }
    node_t *for_deletion = list->head;
    list->head = list->head->next; // Update head
    free(for_deletion);
}

// Display a specific node
void display_node(node_t *node) {
    if (node) {
        printf("Node at %p: %d\n", (void *)node, node->data.data);
    } else {
        printf("NULL\n");
    }
}

// Display the entire list
void display_list(forward_list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data.data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free all memory used by the list
void free_list(forward_list_t **list) {
    node_t *current = (*list)->head;
    while (current != NULL) {
        node_t *for_deletion = current;
        current = current->next;
        free(for_deletion);
    }
    free(*list);
    *list = NULL;
}

// Find a specific node in the list
node_t *find(forward_list_t *list, data_t data) {
    node_t *current = list->head;
    while (current != NULL) {
        if (current->data.data == data.data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Find the previous node of a specific node
node_t *find_prev_node(forward_list_t *list, data_t data) {
    node_t *current = list->head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data.data == data.data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Insert a node after a specific node
void insert_after(forward_list_t *list, data_t target, data_t data) {
    node_t *current = find(list, target);
    if (current) {
        node_t *node = create_node(data);
        node->next = current->next;
        current->next = node;
    }
}

// Insert a node before a specific node
void insert_before(forward_list_t *list, data_t target, data_t data) {
    node_t *prev = find_prev_node(list, target);
    if (prev) {
        node_t *node = create_node(data);
        node->next = prev->next;
        prev->next = node;
    } else if (list->head && list->head->data.data == target.data) {
        push_front(list, data); // Insert at the head
    }
}

// Check if the list is empty
bool is_empty(forward_list_t *list) {
    return list->head == NULL;
}

// Check if two data elements are equal
bool is_equal(data_t first, data_t second) {
    return first.data == second.data;
}
