
#include <stdio.h>

/* Method 1: Grade using else-if ladder */
char grade_ladder(int marks)
{
    if (marks < 0 || marks > 100)
        return '?';
    else if (marks >= 90)
        return 'S';
    else if (marks >= 80)
        return 'A';
    else if (marks >= 70)
        return 'B';
    else if (marks >= 60)
        return 'C';
    else if (marks >= 50)
        return 'D';
    else
        return 'F';
}

/* Method 2: Grade using switch statement */
char grade_switch(int marks)
{
    if (marks < 0 || marks > 100)
        return '?';

    switch (marks / 10)
    {
        case 10:
        case 9:
            return 'S';

        case 8:
            return 'A';

        case 7:
            return 'B';

        case 6:
            return 'C';

        case 5:
            return 'D';

        default:
            return 'F';
    }
}

/* Scholarship classification example */
void scholarship(char grade, int income)
{
    if (grade == '?')
    {
        printf("Invalid marks\n");
    }
    else if (income <= 200000)
    {
        if (grade == 'S' || grade == 'A')
            printf("Scholarship: Full scholarship\n");
        else if (grade == 'B' || grade == 'C')
            printf("Scholarship: Partial scholarship\n");
        else
            printf("Scholarship: Not eligible\n");
    }
    else
    {
        printf("Scholarship: Not eligible\n");
    }
}

int main(void)
{
    int marks[] = {100, 90, 89, 0, -1, 101,
                   80, 79, 70, 69, 60, 59, 50, 49};

    int n = sizeof(marks) / sizeof(marks[0]);

    printf("UNIVERSITY GRADE CLASSIFIER\n");
    printf("---------------------------\n");

    printf("\nELSE-IF LADDER RESULTS\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d : %c\n",
               marks[i], grade_ladder(marks[i]));
    }

    printf("\nSWITCH RESULTS\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d : %c\n",
               marks[i], grade_switch(marks[i]));
    }

    printf("\nSCHOLARSHIP CLASSIFICATION\n");

    scholarship(grade_switch(95), 150000);
    scholarship(grade_switch(75), 150000);
    scholarship(grade_switch(45), 150000);
    scholarship(grade_switch(95), 300000);

    return 0;
}
