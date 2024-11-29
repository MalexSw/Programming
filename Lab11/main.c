#include <stdio.h>
#include <string.h>

// Constants to define maximum allowable products, customers, orders, and name length
#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 50
#define MAX_ORDERS 100
#define MAX_NAME_LENGTH 50

// Struct to represent a product in the store
typedef struct {
    char name[MAX_NAME_LENGTH];  // Name
    float price;                 // Price
    int amount;                  // Available stock
} product_t;

// Struct to represent a customer and their order history
typedef struct {
    char name[MAX_NAME_LENGTH];  // Customer name
    int orders[MAX_ORDERS];      // Indices of products ordered by the customer
    int ordersAmount;            // Number of orders placed by the customer
} customer_t;

// Struct to represent the store with its products and customers
typedef struct {
    product_t products[MAX_PRODUCTS];  // Array of products in the store
    int productsAmount;                // Current number of products in the store
    customer_t customers[MAX_CUSTOMERS]; // Array of customers
    int customerAmount;                // Current number of customers
} store_t;

// Initializes the store by setting product and customer counts to zero
void init_store(store_t *store) {
    store->productsAmount = 0;
    store->customerAmount = 0;
}

// Adds a new product to the store
void addProduct(store_t *store, const char *name, float price, int amount) {
    if (store->productsAmount < MAX_PRODUCTS) {
        product_t *product = &store->products[store->productsAmount++]; // Point to the next free slot
        strncpy(product->name, name, MAX_NAME_LENGTH);  // Copy product name
        product->price = price;  // Set product price
        product->amount = amount;  // Set initial stock
        printf("Product '%s' added \n", name);
    } else {
        printf("Store product list is full!\n");
    }
}

// Places an order for a customer
void placeOrder(store_t *store, const char *customerName, const char *productName) {
    int productIndex = -1;
    // Locate the product in the store
    for (int i = 0; i < store->productsAmount; i++) {
        if (strcmp(store->products[i].name, productName) == 0) {
            productIndex = i;
            break;
        }
    }

    // Handle product not found
    if (productIndex == -1) {
        printf("Product '%s' not found in store!\n", productName);
        return;
    }

    // Check if the product is in stock
    if (store->products[productIndex].amount <= 0) {
        printf("Product '%s' is out of stock!\n", productName);
        return;
    }

    int customerIndex = -1;
    // Locate the customer in the store
    for (int i = 0; i < store->customerAmount; i++) {
        if (strcmp(store->customers[i].name, customerName) == 0) {
            customerIndex = i;
            break;
        }
    }

    // If customer is new, add them to the store
    if (customerIndex == -1) {
        if (store->customerAmount < MAX_CUSTOMERS) {
            customer_t *customer = &store->customers[store->customerAmount++];
            strncpy(customer->name, customerName, MAX_NAME_LENGTH);  // Copy customer name
            customer->ordersAmount = 0;  // Initialize order count
            customerIndex = store->customerAmount - 1;
        } else {
            printf("Customer list is full!\n");
            return;
        }
    }

    // Add the order to the customer's order history
    customer_t *customer = &store->customers[customerIndex];
    if (customer->ordersAmount < MAX_ORDERS) {
        customer->orders[customer->ordersAmount++] = productIndex; // Store product index
        store->products[productIndex].amount--;  // Reduce stock
        printf("Order placed: %s ordered '%s'.\n", customerName, productName);
    } else {
        printf("Customer order list is full!\n");
    }
}

// Lists all orders placed by a customer
void listOrdersByCustomer(const store_t *store, const char *customerName) {
    for (int i = 0; i < store->customerAmount; i++) {
        if (strcmp(store->customers[i].name, customerName) == 0) {
            printf("Orders by %s:\n", customerName);
            customer_t customer = store->customers[i];
            // Loop through the customer's orders and print product details
            for (int j = 0; j < customer.ordersAmount; j++) {
                int productIndex = customer.orders[j];
                printf("  - %s (Price: $%.2f)\n", store->products[productIndex].name, store->products[productIndex].price);
            }
            return;
        }
    }
    // Handle case where customer is not found
    printf("Customer %s not found.\n", customerName);
}

int main() {
    store_t store;
    init_store(&store);  // Initialize the store

    // Add products to the store
    addProduct(&store, "Computer", 871.20, 10);
    addProduct(&store, "Printer", 250, 20);
    addProduct(&store, "Scanner", 123.40, 50);

    // Place some orders
    placeOrder(&store, "Alice", "Computer");
    placeOrder(&store, "Alice", "Scanner");
    placeOrder(&store, "Bob", "Printer");
    placeOrder(&store, "Bob", "Scanner");

    // List orders for specific customers
    listOrdersByCustomer(&store, "Angela");
    listOrdersByCustomer(&store, "Bob");
    listOrdersByCustomer(&store, "Alice");

    return 0;
}