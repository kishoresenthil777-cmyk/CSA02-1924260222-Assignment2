
#include <stdio.h>

int main(void)
{
    int price[] = {100, 250, 199};
    int qty[] = {2, 4, 3};
    int senior[] = {1, 0, 1};

    int total, net;

    printf("JAN AUSHADHI PHARMACY BILLING\n");
    printf("-----------------------------\n");

    for (int i = 0; i < 3; i++)
    {
        total = price[i] * qty[i]
              - price[i] * qty[i] * 15 / 100 * senior[i]
              + price[i] * qty[i] * 5 / 100;

        net = total > 1000 ? total - 50 : total;

        printf("\nBill %d\n", i + 1);
        printf("Price: Rs.%d\n", price[i]);
        printf("Quantity: %d\n", qty[i]);
        printf("Senior citizen: %s\n",
               senior[i] ? "Yes" : "No");
        printf("Total: Rs.%d\n", total);
        printf("Net amount: Rs.%d\n", net);
    }

    // Do not execute this statement:
    // count = count++ + 1;
    // It causes undefined behaviour in C.

    return 0;
}
