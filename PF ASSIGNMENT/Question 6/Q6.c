//Ebad Ali Siddiqui
//24K-0882
//Question 6.


#include <stdio.h>

int determineMatchsticksToPick(int N) {
    if (N % 5 == 0) {
        return -1; 
    } else {
        return N % 5;
    }
}

int main() {
    int N;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &N);
    
    int result = determineMatchsticksToPick(N);
    
    if (result == -1) {
        printf("A cannot guarantee a win.\n");
    } else {
        printf("A should pick %d matchsticks to guarantee a win.\n", result);
    }
    
    return 0;
}
