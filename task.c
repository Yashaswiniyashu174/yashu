#include <stdio.h>

int main() {
    char customer_name[50];
    int customer_id;
    float units_consumed, bill_amount = 0, surcharge = 0, total_bill;
printf("Enter customer name: ");
    scanf("%s", customer_name);
    printf("Enter customer ID: ");
    scanf("%d", &customer_id);
    printf("Enter total units consumed: ");
    scanf("%f", &units_consumed);
bill_amount = 100;
   if (units_consumed <= 100) {
        bill_amount += units_consumed * 5;
    } else if (units_consumed <= 300) {
        bill_amount += 100 * 5 + (units_consumed - 100) * 7;
    } else {
        bill_amount += 100 * 5 + 200 * 7 + (units_consumed - 300) * 10;
    }

    if (bill_amount > 1800) {
        surcharge = bill_amount * 0.05;
    }
total_bill = bill_amount + surcharge;
printf("\n--- Electricity Bill ---\n");
    printf("Customer Name: %s\n", customer_name);
    printf("Customer ID: %d\n", customer_id);
    printf("Units Consumed: %.2f\n", units_consumed);
    printf("Bill Amount: %.2f\n", bill_amount);
    if (surcharge > 0) {
        printf("Surcharge: %.2f\n", surcharge);
    }
    printf("Total Bill: %.2f\n", total_bill);

    return 0;
}

