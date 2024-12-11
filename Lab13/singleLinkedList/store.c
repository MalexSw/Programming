// Source file: store.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"

// Initialize the store
void init_store(store_t *store) {
    store->head = NULL; 
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

// Find a product in the store by name
node_t *find_product(store_t *store, const char *name) {
    node_t *current = store->head;
    while (current != NULL) {
        if (strcmp(current->product.name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Place an order for a product
void place_order(store_t *store, const char *name) {
    node_t *product_node = find_product(store, name);
    if (!product_node) {
        printf("Product '%s' not found in the store!\n", name);
        return;
    }
    if (product_node->product.amount > 0) {
        product_node->product.amount--;
        printf("Order placed for product '%s'. Remaining stock: %d\n",
               name, product_node->product.amount);
    } else {
        printf("Product '%s' is out of stock!\n", name);
    }
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
