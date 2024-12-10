/**Name: Ebad Ali Siddiqui
  *Roll Number:24K-0882
  *Question 1
*/

#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 4

struct Employee
{
    int employeeCode;
    char employeeName[50];
    char dateOfJoining[11]; // Format: DD-MM-YYYY
};

void EmployeeDetails(struct Employee *emp);
void CurrentDate(int *day, int *month, int *year);
int calculateTenure(int joinDay, int joinMonth, int joinYear, int currentDay, int currentMonth, int currentYear);
void displayTenure(struct Employee employees[], int n, int currentDay, int currentMonth, int currentYear);

int main()
{
    struct Employee employees[MAX_EMPLOYEES];
    int currentDay, currentMonth, currentYear;

    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        printf("\nEnter details for Employee %d:\n", i + 1);
        EmployeeDetails(&employees[i]);
    }

    CurrentDate(&currentDay, &currentMonth, &currentYear);

    displayTenure(employees, MAX_EMPLOYEES, currentDay, currentMonth, currentYear);

    return 0;
}

void EmployeeDetails(struct Employee *emp)
{
    printf("Enter Employee Code: ");
    scanf("%d", &(*emp).employeeCode); // Accessing members using (*ptr).member

    printf("Enter Employee Name: ");
    scanf("%s", (*emp).employeeName);

    printf("Enter Date of Joining (DD-MM-YYYY): ");
    scanf("%s", (*emp).dateOfJoining);
}

void CurrentDate(int *day, int *month, int *year)
{
    printf("\nEnter the Current Date (DD-MM-YYYY): ");
    scanf("%d-%d-%d", day, month, year);
}

int calculateTenure(int joinDay, int joinMonth, int joinYear, int currentDay, int currentMonth, int currentYear)
{
    int years = currentYear - joinYear;
    int months = currentMonth - joinMonth;
    int days = currentDay - joinDay;

    if (days < 0)
    {
        months--;
        days += 30; // Assuming 30 days in a month for simplicity
    }
    if (months < 0)
    {
        years--;
        months += 12; // Adjusting for year difference
    }

    return years;
}

void displayTenure(struct Employee employees[], int n, int currentDay, int currentMonth, int currentYear)
{
    printf("\nEmployees with Tenure > 3 years:\n");
    printf("---------------------------------\n");

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int joinDay, joinMonth, joinYear;
        sscanf(employees[i].dateOfJoining, "%d-%d-%d", &joinDay, &joinMonth, &joinYear);

        int tenure = calculateTenure(joinDay, joinMonth, joinYear, currentDay, currentMonth, currentYear);

        if (tenure > 3)
        {
            count++;
            printf("Employee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Date of Joining: %s\n", employees[i].dateOfJoining);
            printf("Tenure: %d years\n", tenure);
            printf("---------------------------------\n");
        }
    }

    printf("\nTotal Employees with Tenure > 3 years: %d\n", count);
}
