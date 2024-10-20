// 24UAM310:C program to implement product list.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100     
#define NAME_LENGTH 50  
#define FILENAME "products.txt"

struct Product {
    int id;
    char name[NAME_LENGTH];
    float price;
};

struct Product productList[MAX_PRODUCTS];
int productCount = 0;       

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Product list is full!\n");
        return;
    }

    struct Product p;
    printf("Enter product ID: ");
    scanf("%d", &p.id);
    getchar();
    printf("Enter product name: ");
    fgets(p.name, NAME_LENGTH, stdin);
    p.name[strcspn(p.name, "\n")] = 0;  
    printf("Enter product price: ");
    scanf("%f", &p.price);

    productList[productCount++] = p;    
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products to display!\n");
        return;
    }

    printf("\nProduct List:\n");
    printf("ID\tName\t\tPrice\n");
    int i;
	for (i = 0; i < productCount; i++)
	{
        printf("%d\t%s\t\t%.2f\n", productList[i].id, productList[i].name, productList[i].price);
    }
}

void saveToFile() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    int i;
	for (i = 0; i < productCount; i++)
	{
        fprintf(file, "%d %s %.2f\n", productList[i].id, productList[i].name, productList[i].price);
    }

    fclose(file);
    printf("Product list saved to file successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    productCount = 0;
    while (fscanf(file, "%d %s %f", &productList[productCount].id, productList[productCount].name, &productList[productCount].price) != EOF) {
        productCount++;
    }

    fclose(file);
    printf("Product list loaded from file successfully!\n");
}

void searchProduct() {
    if (productCount == 0) {
        printf("No products to search!\n");
        return;
    }

    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);

    int i;
	for (i = 0; i < productCount; i++)
 	{
        printf("Product found=\n");
        printf("Product ID\tProduct Name\tProduct Price\n");
        if (productList[i].id == id) {
            printf("\t%d\t%s\t\t%.2f\n", productList[i].id, productList[i].name, productList[i].price);
            return;
        }
    }

    printf("Product with ID %d not found!\n", id);
}

void deleteProduct() {
    if (productCount == 0) {
        printf("No products to delete!\n");
        return;
    }

    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    int i,j;
	for (i = 0; i < productCount; i++)
 	{
        if (productList[i].id == id) {
            for (j = i; j < productCount - 1; j++) {
                productList[j] = productList[j + 1];
            }
            productCount--;
            printf("Product with ID %d deleted successfully!\n", id);
            return;
        }
    }

    printf("Product with ID %d not found!\n", id);
}

int main() {
    int ch;

    while (1) {
        printf("\nShopping Mall Product List\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Search Product by ID\n");
        printf("6. Delete Product by ID\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                loadFromFile();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                deleteProduct();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

