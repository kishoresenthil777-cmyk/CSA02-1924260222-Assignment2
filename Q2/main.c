
#include <stdio.h>

#define N 1000

int senior[N];
int eligible[N];
int disability[N];

int server_calls = 0;
int eligible_checks = 0;
int senior_checks = 0;

/* Simulates slow server verification */
int verify_disability_card(int i)
{
    server_calls++;
    return disability[i];
}

/* Counts eligibility checks */
int check_eligible(int i)
{
    eligible_checks++;
    return eligible[i];
}

/* Counts senior citizen checks */
int check_senior(int i)
{
    senior_checks++;
    return senior[i];
}

int main(void)
{
    int i;
    int concession;

    /* Generate 1000 sample passengers */
    for (i = 0; i < N; i++)
    {
        senior[i] = (i % 4 == 0);
        eligible[i] = (i % 5 != 0);
        disability[i] = (i % 10 == 0);
    }

    printf("SHORT-CIRCUIT EVALUATION\n");
    printf("------------------------\n");

    /* Experiment 1: && short-circuit */
    eligible_checks = 0;

    for (i = 0; i < N; i++)
    {
        if (senior[i] && check_eligible(i))
        {
            /* Eligible senior passenger */
        }
    }

    printf("\n1. AND (&&) Experiment\n");
    printf("Eligibility function calls: %d\n",
           eligible_checks);

    /* Experiment 2: || short-circuit */
    senior_checks = 0;

    for (i = 0; i < N; i++)
    {
        if (disability[i] || check_senior(i))
        {
            /* Passenger satisfies at least one condition */
        }
    }

    printf("\n2. OR (||) Experiment\n");
    printf("Senior check function calls: %d\n",
           senior_checks);

    /* Experiment 3: Senior condition first */
    server_calls = 0;
    eligible_checks = 0;
    concession = 0;

    for (i = 0; i < N; i++)
    {
        if ((senior[i] && check_eligible(i)) ||
            verify_disability_card(i))
        {
            concession++;
        }
    }

    printf("\n3. Senior condition first\n");
    printf("Server verification calls: %d\n", server_calls);
    printf("Eligibility checks: %d\n", eligible_checks);
    printf("Concessions granted: %d\n", concession);

    /* Experiment 4: Server verification first */
    server_calls = 0;
    eligible_checks = 0;
    concession = 0;

    for (i = 0; i < N; i++)
    {
        if (verify_disability_card(i) ||
            (senior[i] && check_eligible(i)))
        {
            concession++;
        }
    }

    printf("\n4. Server verification first\n");
    printf("Server verification calls: %d\n", server_calls);
    printf("Eligibility checks: %d\n", eligible_checks);
    printf("Concessions granted: %d\n", concession);

    /* Experiment 5: Difference between && and & */
    eligible_checks = 0;

    for (i = 0; i < N; i++)
    {
        if (senior[i] && check_eligible(i))
        {
            /* Logical AND */
        }
    }

    printf("\n5. Logical AND (&&)\n");
    printf("Function calls: %d\n", eligible_checks);

    eligible_checks = 0;

    for (i = 0; i < N; i++)
    {
        if (senior[i] & check_eligible(i))
        {
            /* Bitwise AND */
        }
    }

    printf("\n6. Bitwise AND (&)\n");
    printf("Function calls: %d\n", eligible_checks);

    return 0;
}
