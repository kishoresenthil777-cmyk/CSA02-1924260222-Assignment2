
#include <stdio.h>

/* Original Q5 method:
   Checks every divisor up to square root */
int prime_original(unsigned long n, unsigned long *count)
{
    *count = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i <= n / i; i++)
    {
        (*count)++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

/* Redesigned method:
   Checks 2 once, then skips all even divisors */
int prime_redesigned(unsigned long n, unsigned long *count)
{
    *count = 0;

    if (n < 2)
        return 0;

    /* Check the only even prime */
    (*count)++;

    if (n % 2 == 0)
        return n == 2;

    /* Check only odd divisors */
    for (unsigned long i = 3; i <= n / i; i += 2)
    {
        (*count)++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    unsigned long tickets[] = {
        97, 100, 7919, 1000003
    };

    int total = sizeof(tickets) / sizeof(tickets[0]);

    unsigned long old_count, new_count;

    printf("Q7 - PRIME VERIFICATION REDESIGN\n");
    printf("================================\n");

    printf("\nTicket\t\tResult\t\tOriginal\tRedesigned\n");

    for (int i = 0; i < total; i++)
    {
        unsigned long n = tickets[i];

        int old_result = prime_original(n, &old_count);
        int new_result = prime_redesigned(n, &new_count);

        printf("%lu\t\t%s\t\t%lu\t\t%lu\n",
               n,
               old_result ? "Prime" : "Not Prime",
               old_count,
               new_count);

        if (old_result != new_result)
        {
            printf("ERROR: Results do not match!\n");
            return 1;
        }
    }

    printf("\nAll original and redesigned results match.\n");

    return 0;
}
