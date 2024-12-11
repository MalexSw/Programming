#ifndef STORE_H
#define STORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Struct to represent a product in the store
typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int amount;
} product_t;

// Node structure for doubly linked list
typedef struct product_node_t {
    product_t data;
    struct product_node_t *prev;
    struct product_node_t *next;
} product_node_t;

// Store structure containing a doubly linked list of products
typedef struct {
    product_node_t *head;
    product_node_t *tail;
} store_t;

// Function prototypes
void init_store(store_t *store);
product_node_t *create_product_node(const char *name, float price, int amount);
void add_product(store_t *store, const char *name, float price, int amount);
void remove_product(store_t *store, const char *name);
void place_order(store_t *store, const char *productName);
void list_products(const store_t *store);
void free_store(store_t *store);

#endif // STORE_H
