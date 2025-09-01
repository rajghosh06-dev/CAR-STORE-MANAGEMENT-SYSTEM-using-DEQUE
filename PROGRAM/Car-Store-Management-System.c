//using DEQUE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

typedef struct Car
{
    char modelName[SIZE];
    int modelYear;
    char brand[SIZE];
    char fuelType[SIZE];
    struct Car* prev;
    struct Car* next;
} Car;

Car *front = NULL, *rear = NULL;

//  Create a new car node
Car* createCar()
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    printf("Enter Model Name: ");
    scanf(" %[^\n]", newCar->modelName);
    printf("Enter Model Year (YYYY): ");
    scanf("%d", &newCar->modelYear);
    printf("Enter Brand: ");
    scanf(" %[^\n]", newCar->brand);
    printf("Enter Fuel Type (Petrol/Diesel): ");
    scanf(" %[^\n]", newCar->fuelType);
    newCar->prev = newCar->next = NULL;
    return newCar;
}

// Add car at rear (new stock)
void addRear()
{
    Car* newCar = createCar();
    if (!rear)
    {
        front = rear = newCar;
    }
    else
    {
        rear->next = newCar;
        newCar->prev = rear;
        rear = newCar;
    }
    printf("Car added at rear.\n");
}

// Add priority car at front
void addFront() 
{
    Car* newCar = createCar();
    if (!front)
    {
        front = rear = newCar;
    }
    else
    {
        newCar->next = front;
        front->prev = newCar;
        front = newCar;
    }
    printf("Priority car added at front.\n");
}

// Sell car from front (old stock)
void sellFront()
{
    if (!front)
    {
        printf("No cars in store.\n");
        return;
    }
    Car* temp = front;
    front = front->next;
    if (front)
        front->prev = NULL;
    else
        rear = NULL;
    printf("Sold car: %s (%d)\n", temp->modelName, temp->modelYear);
    free(temp);
}

// Sell car from rear (latest stock)
void sellRear()
{
    if (!rear)
    {
        printf("No cars in store.\n");
        return;
    }
    Car* temp = rear;
    rear = rear->prev;
    if (rear)
        rear->next = NULL;
    else
        front = NULL;
    printf("Sold car: %s (%d)\n", temp->modelName, temp->modelYear);
    free(temp);
}

// Search for a car by model name
void searchCar()
{
    if (!front)
    {
        printf("No cars in store.\n");
        return;
    }
    char searchName[SIZE];
    printf("Enter Model Name to search: ");
    scanf(" %[^\n]", searchName);
    Car* temp = front;
    while (temp)
    {
        if (strcmp(temp->modelName, searchName) == 0)
        {
            printf("\nCar Found:\n");
            printf("Model Name: %s\n", temp->modelName);
            printf("Model Year: %d\n", temp->modelYear);
            printf("Brand     : %s\n", temp->brand);
            printf("Fuel Type : %s\n", temp->fuelType);
            return;
        }
        temp = temp->next;
    }
    printf("Car not found.\n");
}

// Display all cars in tabular format
void displayCars()
{
    if (!front)
    {
        printf("No cars in store.\n");
        return;
    }
    printf("\nCar Inventory:\n");
    printf("%-20s %-10s %-15s %-10s\n", "Model Name", "Year", "Brand", "Fuel");
    
    Car* temp = front;
    while (temp)
    {
        printf("%-20s %-10d %-15s %-10s\n", temp->modelName, temp->modelYear, temp->brand, temp->fuelType);
        temp = temp->next;
    }
}

// Delete all cars
void deleteAll()
{
    Car* temp = front;
    while (temp)
    {
        Car* next = temp->next;
        free(temp);
        temp = next;
    }
    front = rear = NULL;
    printf("All cars deleted from store.\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n\t CAR STORE MENU\n");
        printf("1. Add New Car at Rear\n");
        printf("2. Add Priority Car at Front\n");
        printf("3. Sell Car from Front\n");
        printf("4. Sell Car from Rear\n");
        printf("5. Search Car\n");
        printf("6. Display All Cars\n");
        printf("7. Delete All Cars\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: addRear();
                    break;
            case 2: addFront();
                    break;
            case 3: sellFront();
                    break;
            case 4: sellRear();
                    break;
            case 5: searchCar();
                    break;
            case 6: displayCars();
                    break;
            case 7: deleteAll();
                    break;
            case 8: printf("Exiting application.\n");
                    break;
            default: printf("Invalid choice. Try again.\n");
                    break;
        }
    } while (choice != 8);
    return 0;
}