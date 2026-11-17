
#include <stdio.h>

unsigned long checks = 0;

/* Version 1: Original for loop (2 to n-1) */
int prime_original(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i < n; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

/* Version 2: Optimized for loop (up to square root) */
int prime_for(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i <= n / i; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

/* Version 3: Optimized while loop */
int prime_while(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    unsigned long i = 2;

    while (i <= n / i)
    {
        checks++;

        if (n % i == 0)
            return 0;

        i++;
    }

    return 1;
}

/* Version 4: Optimized do-while loop */
int prime_do_while(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    /* Handle 2 and 3 separately */
    if (n < 4)
        return 1;

    unsigned long i = 2;

    do
    {
        checks++;

        if (n % i == 0)
            return 0;

        i++;

    } while (i <= n / i);

    return 1;
}

int main(void)
{
    unsigned long tickets[] = {97, 100, 7919, 1000003};

    int total = sizeof(tickets) / sizeof(tickets[0]);

    printf("LUCKY DRAW TICKET VERIFICATION\n");
    printf("==============================\n");

    for (int k = 0; k < total; k++)
    {
        unsigned long n = tickets[k];

        printf("\nTicket Number: %lu\n", n);

        int p = prime_original(n);
        printf("Original FOR:  %s, divisions = %lu\n",
               p ? "Prime" : "Not Prime", checks);

        p = prime_for(n);
        printf("Optimized FOR: %s, divisions = %lu\n",
               p ? "Prime" : "Not Prime", checks);

        p = prime_while(n);
        printf("Optimized WHILE: %s, divisions = %lu\n",
               p ? "Prime" : "Not Prime", checks);

        p = prime_do_while(n);
        printf("Optimized DO-WHILE: %s, divisions = %lu\n",
               p ? "Prime" : "Not Prime", checks);
    }

    return 0;
}
