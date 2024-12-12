#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"

// Initialize the store
void init_store(store_t *store) {
    store->head = NULL; // Initially, the list is empty
}

// Create a new node for the product
node_t *create_node(const char *name, float price, int amount) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (!node) {
        perror("Failed to create product node");
        exit(EXIT_FAILURE);
    }
    strncpy(node->product.name, name, MAX_NAME_LENGTH);
    node->product.name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    node->product.price = price;
    node->product.amount = amount;
    node->next = NULL;
    return node;
}

// Add a product to the store (insert at the front)
void add_product(store_t *store, const char *name, float price, int amount) {
    node_t *node = create_node(name, price, amount);
    node->next = store->head;
    store->head = node;
    printf("Product '%s' added to the store.\n", name);
}

// Display all products in the store
void display_products(store_t *store) {
    node_t *current = store->head;
    while (current != NULL) {
        printf("Product: %s, Price: $%.2f, Stock: %d\n",
               current->product.name, current->product.price, current->product.amount);
        current = current->next;
    }
}

// Save the linked list to a text file
void save_to_text_file(store_t *store, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }
    node_t *current = store->head;
    while (current) {
        fprintf(file, "%s %.2f %d\n", current->product.name, current->product.price, current->product.amount);
        current = current->next;
    }
    fclose(file);
    printf("Store saved to text file '%s'.\n", filename);
}

// Read the linked list from a text file
void read_from_text_file(store_t *store, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }
    char name[MAX_NAME_LENGTH];
    float price;
    int amount;
    while (fscanf(file, "%s %f %d", name, &price, &amount) == 3) {
        add_product(store, name, price, amount);
    }
    fclose(file);
    printf("Store loaded from text file '%s'.\n", filename);
}

// Save the linked list to a binary file
void save_to_binary_file(store_t *store, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }
    node_t *current = store->head;
    while (current) {
        fwrite(&current->product, sizeof(product_t), 1, file);
        current = current->next;
    }
    fclose(file);
    printf("Store saved to binary file '%s'.\n", filename);
}

// Read the linked list from a binary file
void read_from_binary_file(store_t *store, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }
    product_t product;
    while (fread(&product, sizeof(product_t), 1, file) == 1) {
        add_product(store, product.name, product.price, product.amount);
    }
    fclose(file);
    printf("Store loaded from binary file '%s'.\n", filename);
}

// Free all memory used by the store
void free_store(store_t *store) {
    node_t *current = store->head;
    while (current != NULL) {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }
    store->head = NULL;
}
