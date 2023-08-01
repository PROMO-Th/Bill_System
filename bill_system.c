#include <stdio.h>
#include <string.h>

void menu()
{
    printf("Menu:\n");
    printf("Milkshakes:\n");
    printf("1. Chocolate milkshake - LKR 220\n");
    printf("2. Nutella milkshake - LKR 420\n");
    printf("3. Strawberry milkshake - LKR 250\n");
    printf("4. Vanilla milkshake - LKR 220\n");
    printf("5. Coffee milkshake - LKR 220\n");
    printf("6. Avocado milkshake - LKR 250\n");
    printf("7. Mango milkshake - LKR 250\n");
    printf("Fresh Fruit Juices:\n");
    printf("8. Watermelon - LKR 170\n");
    printf("9. Narang - LKR 150\n");
    printf("10. Mango - LKR 170\n");
    printf("11. Lime - LKR 150\n");
    printf("12. Avocado - LKR 170\n");
    printf("13. Pineapple - LKR 170\n");
    printf("14. Mix fruit - LKR 200\n");
    printf("15. Papaya - LKR 170\n");
    printf("16. Amberella - LKR 170\n");
    printf("17. Apple - LKR 200\n");
    printf("Faluda:\n");
    printf("18. Faluda - LKR 250\n");
}

const char* name(int number)
{
    const char* names[] = {"Chocolate milkshake", "Nutella milkshake", "Strawberry milkshake", "Vanilla milkshake",
        "Coffee milkshake", "Avocado milkshake", "Mango milkshake", "Watermelon", "Narang", "Mango",
        "Lime", "Avocado", "Pineapple", "Mix fruit", "Papaya", "Amberella", "Apple", "Faluda"};

    if (number >= 1 && number <= 18)
    {
        return names[number - 1];
    }

    return "Unknown";
}

float bill(int numbers[], int quantity)
{
    float total = 0.0;
    float price[] = {220, 420, 250, 220, 220, 250, 250, 170, 150, 170, 150, 170, 170, 200, 170, 170, 200, 250};

    for (int i = 0; i < quantity; i++)
    {
        total += price[numbers[i] - 1];
    }

    return total;
}

int main()
{
    int max = 50;
    int numbers[max];
    int quantity = 0;
    int choice;

    menu();

    printf("\nEnter the item numbers you want to order (separated by space, 0 to stop): ");

    while (1)
    {
        scanf("%d", &choice);

        if (choice == 0)
          {
            break;
          }

        if (choice < 1 || choice > 18)
          {
            printf("Invalid item number. Please enter a valid item number or 0 to stop.\n");
            continue;
          }

        numbers[quantity++] = choice;
    }

    if (quantity == 0)
     {
        printf("No items selected. Exiting...\n");
        return 0;
     }

    printf("\nYou ordered the following items:\n");
    for (int i = 0; i < quantity; i++)
     {
        printf("%d. %s\n", i + 1, name(numbers[i]));
     }

    float total = bill(numbers, quantity);
    printf("\nTotal bill: LKR %.2f\n", total);

    float payment;
    printf("\nEnter the cash amount: LKR ");
    scanf("%f", &payment);

    if (payment < total)
     {
        printf("Insufficient cash provided. Payment not accepted.\n");
        return 0;
     }

    float balance = payment - total;
    printf("Payment successful. Balance: LKR %.2f\n", balance);

    printf("\nThank you for ordering.\n");

    return 0;
}
