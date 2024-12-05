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
void display_list(forward_list_t *list);
void free_list(forward_list_t **list);
void create_list(forward_list_t **list);
node_t *create_node(data_t data);
void save_to_text_file(forward_list_t *list, const char *filename);
void load_from_text_file(forward_list_t *list, const char *filename);
void save_to_binary_file(forward_list_t *list, const char *filename);
void load_from_binary_file(forward_list_t *list, const char *filename);

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

    // Display initial list
    printf("Initial List:\n");
    display_list(list);

    // Save the list to text and binary files
    save_to_text_file(list, "list.txt");
    save_to_binary_file(list, "list.bin");

    // Create a new list and load data from the files
    forward_list_t *new_list = NULL;
    create_list(&new_list);

    // Load from text file
    load_from_text_file(new_list, "list.txt");
    printf("\nList after loading from text file:\n");
    display_list(new_list);

    // Load from binary file
    load_from_binary_file(new_list, "list.bin");
    printf("\nList after loading from binary file:\n");
    display_list(new_list);

    // Free list memory
    free_list(&list);
    free_list(&new_list);

    return 0;
}

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

// Save the linked list to a text file
void save_to_text_file(forward_list_t *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    node_t *current = list->head;
    while (current != NULL) {
        fprintf(file, "%d\n", current->data.data);
        current = current->next;
    }

    fclose(file);
}

// Load the linked list from a text file
void load_from_text_file(forward_list_t *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }

    data_t data;
    while (fscanf(file, "%d", &data.data) != EOF) {
        push_front(list, data); // Insert at the front (reverse order)
    }

    fclose(file);
}

// Save the linked list to a binary file
void save_to_binary_file(forward_list_t *list, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    node_t *current = list->head;
    while (current != NULL) {
        fwrite(&current->data, sizeof(data_t), 1, file);
        current = current->next;
    }

    fclose(file);
}

// Load the linked list from a binary file
void load_from_binary_file(forward_list_t *list, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }

    data_t data;
    while (fread(&data, sizeof(data_t), 1, file) == 1) {
        push_front(list, data); // Insert at the front (reverse order)
    }

    fclose(file);
}
