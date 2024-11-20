#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 50
#define MAX_ORDERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int amount;
} product_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int orders[MAX_ORDERS];
    int ordersAmount;
} customer_t;

typedef struct {
    product_t products[MAX_PRODUCTS];
    int productsAmount;
    customer_t customers[MAX_CUSTOMERS];
    int customerAmount;
} store_t;

void init_store(store_t *store) {
    store->productsAmount = 0;
    store->customerAmount = 0;
}

void addProduct(store_t *store, const char *name, float price, int amount) {
    if (store->productsAmount < MAX_PRODUCTS) {
        product_t *product = &store->products[store->productsAmount++];
        strncpy(product->name, name, MAX_NAME_LENGTH);
        product->price = price;
        product->amount = amount;
        printf("Product '%s' added \n", name);
    } else {
        printf("Store product list is full!\n");
    }
}

void placeOrder(store_t *store, const char *customerName, const char *productName) {
    int productIndex = -1;
    for (int i = 0; i < store->productsAmount; i++) {
        if (strcmp(store->products[i].name, productName) == 0) {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1) {
        printf("Product '%s' not found in store!\n", productName);
        return;
    }

    if (store->products[productIndex].amount <= 0) {
        printf("Product '%s' is out of stock!\n", productName);
        return;
    }

    int customerIndex = -1;
    for (int i = 0; i < store->customerAmount; i++) {
        if (strcmp(store->customers[i].name, customerName) == 0) {
            customerIndex = i;
            break;
        }
    }

    if (customerIndex == -1) {
        if (store->customerAmount < MAX_CUSTOMERS) {
            customer_t *customer = &store->customers[store->customerAmount++];
            strncpy(customer->name, customerName, MAX_NAME_LENGTH);
            customer->ordersAmount = 0;
            customerIndex = store->customerAmount - 1;
        } else {
            printf("Customer list is full!\n");
            return;
        }
    }

    customer_t *customer = &store->customers[customerIndex];
    if (customer->ordersAmount < MAX_ORDERS) {
        customer->orders[customer->ordersAmount++] = productIndex;
        store->products[productIndex].amount--; // Reduce product quantity
        printf("Order placed: %s ordered '%s'.\n", customerName, productName);
    } else {
        printf("Customer order list is full!\n");
    }
}

void listOrdersByCustomer(const store_t *store, const char *customerName) {
    for (int i = 0; i < store->customerAmount; i++) {
        if (strcmp(store->customers[i].name, customerName) == 0) {
            printf("Orders by %s:\n", customerName);
            customer_t customer = store->customers[i];
            for (int j = 0; j < customer.ordersAmount; j++) {
                int productIndex = customer.orders[j];
                printf("  - %s (Price: $%.2f)\n", store->products[productIndex].name, store->products[productIndex].price);
            }
            return;
        }
    }
    printf("Customer %s not found.\n", customerName);
}


int main() {
    store_t store;
    init_store(&store);


    addProduct(&store, "Computer", 871.20, 10);
    addProduct(&store, "Printer", 250, 20);
    addProduct(&store, "Scanner", 123.40, 50);

    // Place some orders
    placeOrder(&store, "Alice", "Computer");
    placeOrder(&store, "Alice", "Scanner");
    placeOrder(&store, "Bob", "Printer");
    placeOrder(&store, "Bob", "Scanner");

    listOrdersByCustomer(&store, "Angela");
    listOrdersByCustomer(&store, "Bob");
    listOrdersByCustomer(&store, "Alice");
}