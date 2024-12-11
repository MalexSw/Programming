#include "store.h"

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
    node->data.name[MAX_NAME_LENGTH - 1] = '\0';
    node->data.price = price;
    node->data.amount = amount;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Add a new product to the store
void add_product(store_t *store, const char *name, float price, int amount) {
    product_node_t *new_node = create_product_node(name, price, amount);

    if (store->head == NULL) {
        store->head = store->tail = new_node;
    } else {
        store->tail->next = new_node;
        new_node->prev = store->tail;
        store->tail = new_node;
    }
    printf("Product '%s' added to the store.\n", name);
}

// Remove a product from the store
void remove_product(store_t *store, const char *name) {
    product_node_t *current = store->head;

    while (current != NULL && strcmp(current->data.name, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Product '%s' not found in the store.\n", name);
        return;
    }

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        store->head = current->next;
    }
    if (current->next) {
        current->next->prev = current->prev;
    } else {
        store->tail = current->prev;
    }

    free(current);
    printf("Product '%s' removed from the store.\n", name);
}

// Place an order for a product
void place_order(store_t *store, const char *productName) {
    product_node_t *current = store->head;

    while (current != NULL && strcmp(current->data.name, productName) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Product '%s' not found in the store.\n", productName);
        return;
    }

    if (current->data.amount <= 0) {
        printf("Product '%s' is out of stock.\n", productName);
        return;
    }

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
