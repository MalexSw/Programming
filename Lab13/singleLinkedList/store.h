// Header file: store.h
#ifndef STORE_H
#define STORE_H

#include <stdbool.h>

#define MAX_NAME_LENGTH 50

// Struct to represent a product in the store
typedef struct product_t {
    char name[MAX_NAME_LENGTH];  // Name
    float price;                 // Price
    int amount;                  // Available stock
} product_t;

// Node structure for singly linked list
typedef struct node_t {
    product_t product;          
    struct node_t *next;        // Pointer to the next node
} node_t;

// Store structure with linked list for products
typedef struct {
    node_t *head;               // Head of the product linked list
} store_t;

// Function prototypes
void init_store(store_t *store);
node_t *create_node(const char *name, float price, int amount);
void add_product(store_t *store, const char *name, float price, int amount);
void display_products(store_t *store);
node_t *find_product(store_t *store, const char *name);
void place_order(store_t *store, const char *name);
void free_store(store_t *store);

#endif // STORE_H
