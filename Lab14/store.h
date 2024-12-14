#ifndef STORE_H
#define STORE_H

#define MAX_NAME_LENGTH 50

// Struct to represent a product in the store
typedef struct product_t {
    char name[MAX_NAME_LENGTH];  // Name
    float price;                 // Price
    int amount;                  // Available stock
} product_t;

// Node structure for singly linked list
typedef struct node_t {
    product_t product;          // Product data
    struct node_t *next;        // Pointer to the next node
} node_t;

// Store structure with linked list for products
typedef struct {
    node_t *head;               // Head of the product linked list
} store_t;

// Function prototypes
void init_store(store_t *store);
void add_product(store_t *store, const char *name, float price, int amount);
void display_products(store_t *store);
void save_to_text_file(store_t *store, const char *filename);
void read_from_text_file(store_t *store, const char *filename);
void save_to_binary_file(store_t *store, const char *filename);
void read_from_binary_file(store_t *store, const char *filename);
void free_store(store_t *store);

#endif // STORE_H
