//Ebad Ali Siddiqui
//24K-0882
//Question 5.


#include <stdio.h>

int main() {
    int count;

    printf("Enter the number of values: ");
    scanf("%d", &count);

    int values[count];
    
    for (int i = 0; i < count; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    printf("\nHorizontal Histogram:\n");
    for (int i = 0; i < count; i++) {
        printf("Value %d: ", i + 1);
        for (int j = 0; j < values[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\nVertical Histogram:\n");

    int max = values[0];
    for (int i = 1; i < count; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }

    for (int i = max; i > 0; i--) {
        for (int j = 0; j < count; j++) {
            if (values[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    return 0;
}
