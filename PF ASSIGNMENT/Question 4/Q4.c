//Ebad Ali Siddiqui
//24K-0882
//Question 4.


#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

int haveSameCharacters(char *word1, char *word2) {
    int count[256] = {0};

    for (int i = 0; word1[i] != '\0'; i++) {
        count[(int)word1[i]]++;
    }

    for (int i = 0; word2[i] != '\0'; i++) {
        count[(int)word2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the number of words: ");
    scanf("%d", &n);

    char words[MAX_WORDS][MAX_LENGTH];
    int processed[MAX_WORDS] = {0};

    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    for (int i = 0; i < n; i++) {
        if (!processed[i]) {
            printf("[ %s", words[i]);
            processed[i] = 1;
			
            for (int j = i + 1; j < n; j++) {
                if (!processed[j] && haveSameCharacters(words[i], words[j])) {
                    printf(", %s", words[j]);
                    processed[j] = 1;
                }
            }
            printf(" ]\n");
        }
    }

    return 0;
}
