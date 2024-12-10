#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// Main function
int main() {
    store_t store;
    init_store(&store);

    // Add products to the store
    add_product(&store, "Computer", 871.20, 10);
    add_product(&store, "Printer", 250.00, 20);
    add_product(&store, "Scanner", 123.40, 50);

    // Display all products
    printf("Products in the store:\n");
    display_products(&store);

    // Place orders
    place_order(&store, "Computer");
    place_order(&store, "Printer");
    place_order(&store, "Nonexistent");  // Invalid order

    // Display products after orders
    printf("\nProducts after orders:\n");
    display_products(&store);

    // Free all allocated memory
    free_store(&store);
    return 0;
}


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
