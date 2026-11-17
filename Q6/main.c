
#include <stdio.h>

#define MAX_MONTHS 360
#define EPSILON 0.0000001

typedef struct
{
    int months;
    double total_interest;
    double final_balance;
    int completed;
} LoanResult;

/* Calculate loan repayment using a while loop */
LoanResult calculate_loan(double principal,
                          double rate,
                          double repayment,
                          int show_schedule)
{
    LoanResult result = {0, 0.0, principal, 0};

    double balance = principal;

    /* Check whether the loan can ever be repaid */
    if (repayment <= balance * rate + EPSILON)
    {
        result.final_balance = balance;
        return result;
    }

    printf("\n");

    if (show_schedule)
    {
        printf("MONTHLY LOAN REPAYMENT SCHEDULE\n");
        printf("-----------------------------------------------\n");
        printf("Month\tOpening\t\tInterest\tPayment\t\tBalance\n");
    }

    /* Continue until the balance becomes zero */
    while (balance > EPSILON)
    {
        /* Safety limit */
        if (result.months >= MAX_MONTHS)
        {
            printf("\nSafety limit reached: loan not fully repaid.\n");
            break;
        }

        double interest = balance * rate;
        double amount_due = balance + interest;

        /* Adjust the last payment */
        double actual_payment = repayment;

        if (actual_payment > amount_due)
        {
            actual_payment = amount_due;
        }

        double opening_balance = balance;

        balance = amount_due - actual_payment;

        if (balance < EPSILON)
        {
            balance = 0.0;
        }

        result.months++;
        result.total_interest += interest;

        if (show_schedule)
        {
            printf("%d\tRs.%.2f\tRs.%.2f\tRs.%.2f\tRs.%.2f\n",
                   result.months,
                   opening_balance,
                   interest,
                   actual_payment,
                   balance);
        }
    }

    result.final_balance = balance;

    if (balance <= EPSILON)
    {
        result.completed = 1;
    }

    return result;
}

int main(void)
{
    double principal = 10000.0;
    double rate = 0.02;
    double repayment = 2000.0;

    printf("SELF-HELP GROUP MICRO-LOAN\n");
    printf("==========================\n");

    printf("Principal: Rs.%.2f\n", principal);
    printf("Monthly interest rate: %.2f%%\n", rate * 100);
    printf("Monthly repayment: Rs.%.2f\n", repayment);

    /* Display the full repayment schedule */
    LoanResult result = calculate_loan(
        principal, rate, repayment, 1
    );

    printf("\nLOAN SUMMARY\n");
    printf("-----------------------------\n");

    if (result.completed)
    {
        printf("Loan status: Fully repaid\n");
    }
    else
    {
        printf("Loan status: Not fully repaid\n");
    }

    printf("Number of months: %d\n", result.months);
    printf("Total interest paid: Rs.%.2f\n",
           result.total_interest);
    printf("Remaining balance: Rs.%.2f\n",
           result.final_balance);

    /* Growth investigation */
    double payments[] = {
        2000, 1000, 500, 250, 201, 200, 199
    };

    int n = sizeof(payments) / sizeof(payments[0]);

    printf("\nGROWTH INVESTIGATION\n");
    printf("--------------------------------\n");
    printf("Repayment\tMonths\tStatus\n");

    for (int i = 0; i < n; i++)
    {
        LoanResult test = calculate_loan(
            principal, rate, payments[i], 0
        );

        printf("Rs.%.2f\t%d\t%s\n",
               payments[i],
               test.months,
               test.completed ? "Completed" : "Not completed");
    }

    return 0;
}
