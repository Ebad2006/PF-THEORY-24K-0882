//Ebad Ali Siddiqui
//24K-0882
//Question 2.


#include <stdio.h>
#include <string.h>

#define MAX_CHAR 128
#define MAX_SLOGANS 100
#define MAX_LENGTH 100

void analyzeCharacterFrequency(char *slogan) {
    int frequency[MAX_CHAR] = {0};
    
    for (int i = 0; i < strlen(slogan); i++) {
        char ch = slogan[i];
        frequency[(int)ch]++;
    }
    
    printf("Character frequencies for \"%s\":\n", slogan);
    for (int i = 0; i < MAX_CHAR; i++) {
        if (frequency[i] > 0) {
            printf("'%c': %d, ", (char)i, frequency[i]);
        }
    }
    printf("\n\n");
}

int main() {
    int numSlogans;
    printf("Enter the number of slogans: ");
    scanf("%d", &numSlogans);
    getchar();

    char slogans[MAX_SLOGANS][MAX_LENGTH];

    for (int i = 0; i < numSlogans; i++) {
        printf("Enter slogan %d: ", i + 1);
        fgets(slogans[i], MAX_LENGTH, stdin);
        slogans[i][strcspn(slogans[i], "\n")] = '\0';
    }

    for (int i = 0; i < numSlogans; i++) {
        analyzeCharacterFrequency(slogans[i]);
    }

    return 0;
}
