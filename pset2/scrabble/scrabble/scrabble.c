#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *player_input);

int main(void) {
    
    char player1_input[50];
    char player2_input[50];
    
    printf("Player 1: ");
    scanf("%49s", player1_input);
    
    printf("\nPlayer 2: ");
    scanf("%49s", player2_input);
    
    int score1 = compute_score(player1_input);
    int score2 = compute_score(player2_input);
    
    if(score1 > score2) {
        printf("\nPlayer 1 Wins!\n");
    } else if(score1 < score2) {
        printf("\nPlayer 2 Wins!\n");
    } else {
        printf("\nTie!\n");
    }

    return 0;
}

int compute_score(char *player_input) {
    
    int score = 0;
    long len = strlen(player_input);
    
    for(int i = 0; i < len; i++) {
        if(isupper(player_input[i])) { // Is upper in the position i?
            score += POINTS[player_input[i] - 'A']; // score = score + POINTS in the player input position char minus the value of the char 'A', giving the position of the point.
        } else if(islower(player_input[i])) {
            score += POINTS[player_input[i] - 'a']; // same as upper
        }
    }
    
    return score;
}
