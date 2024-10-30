//Ebad Ali Siddiqui
//24K-0882
//Question 1.



#include <stdio.h>

void main() {
    int arr1[50], n, i, j = 0, sml, sml2nd;

    printf("Input the size of the array : ");
    scanf("%d", &n);

    printf("Input %d elements in the array (value must be <9999) :\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr1[i]);
    }

    sml = arr1[0];
    for (i = 0; i < n; i++) {
        if (sml > arr1[i]) {
            sml = arr1[i];
            j = i;
        }
    }
	
	sml2nd = 99999;
    for (i = 0; i < n; i++) {
        if (i == j) {
            i++;
            i--;
        } else {
            if (sml2nd > arr1[i]) {
                sml2nd = arr1[i];
            }
        }
    }
    
	printf("The Second smallest element in the array is :  %d \n\n", sml2nd);
}
