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

    // Save to files
    save_to_text_file(&store, "list.txt");
    save_to_binary_file(&store, "list.bin");

    // Free the store and read from files
    free_store(&store);

    printf("\nReading from text file:\n");
    read_from_text_file(&store, "list.txt");
    display_products(&store);

    free_store(&store);

    printf("\nReading from binary file:\n");
    read_from_binary_file(&store, "list.bin");
    display_products(&store);

    // Free all allocated memory
    free_store(&store);
    return 0;
}
