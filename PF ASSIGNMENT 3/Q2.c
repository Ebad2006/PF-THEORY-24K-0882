#include <stdio.h>

struct Player
{
    int ballScore[12];
    char PlayerName[25];
    int TotalScore;
};

typedef struct Player Player;

int validateScore(int Score);
void PlayGame(Player *player);
void findWinner(Player p1, Player p2);
void displayMatchScore(Player p1, Player p2);

int main()
{
    printf("Starting Match\n");
    Player p1, p2;

    p1.TotalScore = 0;
    p2.TotalScore = 0;

    printf("Enter Player 1 Name: ");
    scanf("%24s", p1.PlayerName);

    printf("Enter Player 2 Name: ");
    scanf("%24s", p2.PlayerName);

    printf("\nScore For Player 1\n");
    PlayGame(&p1);

    printf("\nScore For Player 2\n");
    PlayGame(&p2);

    printf("\nMatch Scoreboard:\n");
    displayMatchScore(p1, p2);

    findWinner(p1, p2);

    return 0;
}

int validateScore(int Score)
{
    if (Score >= 0 && Score <= 6)
    {
        return 1;
    }
    return 0;
}

void PlayGame(Player *player)
{
    for (int i = 0; i < 12; i++)
    {
        printf("Enter score for ball %d: ", i + 1);
        scanf("%d", &(player->ballScore[i]));
        if (validateScore(player->ballScore[i]))
        {
            player->TotalScore += player->ballScore[i];
        }
        else
        {
            printf("Invalid score! ball %d ignored.\n", i + 1);
            player->ballScore[i] = 0; // Reset invalid score to 0
        }
    }
}

void findWinner(Player p1, Player p2)
{
    if (p1.TotalScore > p2.TotalScore)
    {
        printf("The Winner Is %s\n", p1.PlayerName);
    }
    else if (p1.TotalScore < p2.TotalScore)
    {
        printf("The Winner Is %s\n", p2.PlayerName);
    }
    else
    {
        printf("It's a tie\n");
    }
}

void displayMatchScore(Player p1, Player p2)
{
    printf("Performance Of Player %s\n", p1.PlayerName);
    for (int j = 0; j < 12; j++)
    {
        printf("%d Ball Score: %d\n", j + 1, p1.ballScore[j]);
    }
    printf("Total Score: %d\n", p1.TotalScore);
    printf("Average Score: %.2f\n", (float)p1.TotalScore / 12);

    printf("\nPerformance Of Player %s\n", p2.PlayerName);
    for (int j = 0; j < 12; j++)
    {
        printf("%d Ball Score: %d\n", j + 1, p2.ballScore[j]);
    }
    printf("Total Score: %d\n", p2.TotalScore);
    printf("Average Score: %.2f\n", (float)p2.TotalScore / 12);
}
