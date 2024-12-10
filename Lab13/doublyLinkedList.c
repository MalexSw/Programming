#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum allowable name length for products and customers
#define MAX_NAME_LENGTH 50

// Struct to represent a product in the store (node data)
typedef struct {
    char name[MAX_NAME_LENGTH];  // Name
    float price;                 // Price
    int amount;                  // Available stock
} product_t;

// Node structure for doubly linked list
typedef struct product_node_t {
    product_t data;                 // Product data
    struct product_node_t *prev;    // Pointer to the previous node
    struct product_node_t *next;    // Pointer to the next node
} product_node_t;

// Store structure containing a doubly linked list of products
typedef struct {
    product_node_t *head;  // Pointer to the first product
    product_node_t *tail;  // Pointer to the last product
} store_t;

// Function prototypes
void init_store(store_t *store);
product_node_t *create_product_node(const char *name, float price, int amount);
void add_product(store_t *store, const char *name, float price, int amount);
void remove_product(store_t *store, const char *name);
void place_order(store_t *store, const char *productName);
void list_products(const store_t *store);
void free_store(store_t *store);

// Main function
int main() {
    store_t store;
    init_store(&store);  // Initialize the store

    // Add products to the store
    add_product(&store, "Computer", 871.20, 10);
    add_product(&store, "Printer", 250.00, 20);
    add_product(&store, "Scanner", 123.40, 50);

    // List available products
    printf("Available products:\n");
    list_products(&store);

    // Place an order
    printf("\nPlacing an order for 'Computer':\n");
    place_order(&store, "Computer");

    // List available products after placing the order
    printf("\nAvailable products after order:\n");
    list_products(&store);

    // Remove a product
    printf("\nRemoving 'Printer' from the store:\n");
    remove_product(&store, "Printer");

    // List products after removal
    printf("\nAvailable products after removal:\n");
    list_products(&store);

    // Free all allocated memory
    free_store(&store);
    return 0;
}

// Initialize the store
void init_store(store_t *store) {
    store->head = NULL;
    store->tail = NULL;
}

// Create a new product node
product_node_t *create_product_node(const char *name, float price, int amount) {
    product_node_t *node = (product_node_t *)malloc(sizeof(product_node_t));
    if (!node) {
        perror("Failed to allocate memory for product node");
        exit(EXIT_FAILURE);
    }
    strncpy(node->data.name, name, MAX_NAME_LENGTH);
    node->data.name[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null termination
    node->data.price = price;
    node->data.amount = amount;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Add a new product to the store
void add_product(store_t *store, const char *name, float price, int amount) {
    product_node_t *new_node = create_product_node(name, price, amount);

    // If the store is empty
    if (store->head == NULL) {
        store->head = store->tail = new_node;
    } else {
        // Add the new node to the end of the list
        store->tail->next = new_node;
        new_node->prev = store->tail;
        store->tail = new_node;
    }
    printf("Product '%s' added to the store.\n", name);
}

// Remove a product from the store
void remove_product(store_t *store, const char *name) {
    product_node_t *current = store->head;

    // Traverse the list to find the product
    while (current != NULL && strcmp(current->data.name, name) != 0) {
        current = current->next;
    }

    // If the product was not found
    if (current == NULL) {
        printf("Product '%s' not found in the store.\n", name);
        return;
    }

    // Remove the node
    if (current->prev) {
        current->prev->next = current->next;
    } else {
        store->head = current->next;  // Removing the head
    }
    if (current->next) {
        current->next->prev = current->prev;
    } else {
        store->tail = current->prev;  // Removing the tail
    }

    free(current);
    printf("Product '%s' removed from the store.\n", name);
}

// Place an order for a product
void place_order(store_t *store, const char *productName) {
    product_node_t *current = store->head;

    // Traverse the list to find the product
    while (current != NULL && strcmp(current->data.name, productName) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Product '%s' not found in the store.\n", productName);
        return;
    }

    // Check if the product is in stock
    if (current->data.amount <= 0) {
        printf("Product '%s' is out of stock.\n", productName);
        return;
    }

    // Reduce the stock and confirm the order
    current->data.amount--;
    printf("Order placed for product '%s'. Remaining stock: %d\n", productName, current->data.amount);
}

// List all products in the store
void list_products(const store_t *store) {
    product_node_t *current = store->head;

    if (current == NULL) {
        printf("The store is empty.\n");
        return;
    }

    while (current != NULL) {
        printf("Product: %s | Price: $%.2f | Stock: %d\n",
               current->data.name, current->data.price, current->data.amount);
        current = current->next;
    }
}

// Free all memory used by the store
void free_store(store_t *store) {
    product_node_t *current = store->head;

    while (current != NULL) {
        product_node_t *to_free = current;
        current = current->next;
        free(to_free);
    }

    store->head = NULL;
    store->tail = NULL;
    printf("Store memory freed.\n");
}
