// Main file: main.c
#include <stdio.h>
#include "store.h"

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
