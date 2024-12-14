#include "store.h"

int main() {
    store_t store;
    init_store(&store);

    add_product(&store, "Computer", 871.20, 10);
    add_product(&store, "Printer", 250.00, 20);
    add_product(&store, "Scanner", 123.40, 50);

    printf("Available products:\n");
    list_products(&store);

    printf("\nPlacing an order for 'Computer':\n");
    place_order(&store, "Computer");

    printf("\nAvailable products after order:\n");
    list_products(&store);

    printf("\nRemoving 'Printer' from the store:\n");
    remove_product(&store, "Printer");

    printf("\nAvailable products after removal:\n");
    list_products(&store);

    free_store(&store);
    return 0;
}
