#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 5

typedef struct {
    int flightNumber;
    char destination[50];
    float price;
} Flight;

void displayFlights(Flight flights[], int size) {
    printf("Available Flights:\n");
    for (int i = 0; i < size; i++) {
        printf("Flight %d: %s - $%.2f\n", flights[i].flightNumber, flights[i].destination, flights[i].price);
    }
}

char getGrade(float price) {
    if (price > 300) {
        return 'A';
    } else if (price > 200) {
        return 'B';
    } else {
        return 'C';
    }
}

int main() {
    Flight flights[MAX_FLIGHTS] = {
        {101, "New York", 200.00},
        {102, "Los Angeles", 300.00},
        {103, "Chicago", 150.00},
        {104, "Miami", 250.00},
        {105, "San Francisco", 400.00}
    };

    int choice;
    char name[50];
    int validChoice = 0;
    float userMoney;
    float bagWeight;

    displayFlights(flights, MAX_FLIGHTS);

    // Get user money with validation
    while (1) {
        printf("Enter the amount of money you have: $");
        if (scanf("%f", &userMoney) == 1 && userMoney > 0) {
            break;
        } else {
            printf("SORRY! The   price range for ticket is  $150 to $400 .\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }

    while (!validChoice) {
        printf("Enter the flight number you want to purchase: ");
        if (scanf("%d", &choice) == 1 && choice >= 101 && choice <= 105) {
            validChoice = 1;
        } else {
            printf("Invalid flight number! Please try again.\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }

    // Find the flight details based on the choice
    Flight selectedFlight;
    int i = 0;
    while (i < MAX_FLIGHTS) {
        if (flights[i].flightNumber == choice) {
            selectedFlight = flights[i];
            break;
        }
        i++;
    }

    // Check if the user has enough money
    if (userMoney < selectedFlight.price) {
        printf("You do not have enough money to purchase this ticket!\n");
        return 1;
    }

    // Get the bag weight with validation
    while (1) {
        printf("Enter the weight of your carry bag (0 to 10 kg): ");
        if (scanf("%f", &bagWeight) == 1 && bagWeight >= 0 && bagWeight <= 10) {
            break;
        } else {
            printf("Invalid weight! Please enter a weight between 0 and 10 kg.\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }

    printf("Enter your name: ");
    scanf(" %[^\n]", name);  // Read string with spaces

    char grade = getGrade(selectedFlight.price);

    printf("Purchasing ticket...\n");
    printf("Ticket Details:\n");
    printf("Name: %s\n", name);
    printf("Flight Number: %d\n", selectedFlight.flightNumber);
    printf("Destination: %s\n", selectedFlight.destination);
    printf("Price: $%.2f\n", selectedFlight.price);
    printf("Carry Bag Weight: %.2f kg\n", bagWeight);
    printf("Grade: %c\n", grade);
    printf("Thank you for your purchase!\n");

    return 0;
}
