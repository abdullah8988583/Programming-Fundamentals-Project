#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

char board[3][3];
const char PLAYER = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

char player1Name[50], player2Name[50];
int difficulty = 1;

void printlogo();
void resetboard();
void printboard();
int checkfreespaces();
void playermove();
void player2move();
void computermove();
char checkwinner();
void printwinner(char);
void printwinnerpvp(char);
void chooseDifficulty();


void displayResults() {
    FILE *resultsFile = fopen("results.txt", "r"); 
    if (!resultsFile) {
    printf("Error: No results file found.\n");
    return;
    }

    char line[256];
     printf("\n------------------------------------------------");
    printf("\n|               Game Results                  |\n");
    printf("------------------------------------------------\n");

    while (fgets(line, sizeof(line), resultsFile)) {
        printf("%s", line); 
    }

    printf("------------------------------------------------\n");
    fclose(resultsFile); 
}

int main() {
    printlogo();
    srand(time(0)); 

    printf("Enter Player 1 Name: ");
    scanf("%s",player1Name);

    char winner = ' ';
    char response;
    int choice;

    do {
        printf("Enter the mode you want to select\n");
        printf("1. Player vs Computer\n2. Player vs Player\n");
        printf("3. View Results\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
        chooseDifficulty(); 
        do {
        winner = ' ';
        response = ' ';
        resetboard();

    while (winner == ' ' && checkfreespaces() != 0) {
        printboard();

        printf("%s's Turn (X):\n",player1Name);
        playermove();
        winner = checkwinner();
        if (winner != ' ' || checkfreespaces() == 0) break;

        computermove();
        winner = checkwinner();
        if (winner != ' ' || checkfreespaces() == 0) break;
                }

        printboard();
        printwinner(winner);

        printf("\nWould you like to play again (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);

        }while (response == 'Y');
        } else if (choice == 2) { // Player vs Player
        printf("Enter Player 2 Name: ");
        scanf("%s", player2Name);

        do {
        winner = ' ';
        response = ' ';
        resetboard();

        while (winner == ' ' && checkfreespaces() != 0) {
        printboard();
        printf("%s's Turn (X):\n", player1Name);
        playermove();
        winner = checkwinner();
        if (winner != ' ' || checkfreespaces() == 0) break;

        printboard();
        printf("%s's Turn (O):\n", player2Name);
        player2move();
        winner = checkwinner();
        if (winner != ' ' || checkfreespaces() == 0) break;
                }

        printwinnerpvp(winner);

        printf("\nWould you like to play again (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);

    } while (response == 'Y');
        } else if (choice == 3) { 
            displayResults();
        }
    } while (choice != 4);

    printf("Thanks for playing.\n");
    return 0;
}

void chooseDifficulty() {
    printf("Select difficulty level:\n");
    printf("1. Easy\n2. Medium\n3. Hard\n");
    scanf("%d", &difficulty);
}

void resetboard() {
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
    board[i][j] = ' ';
    }
    }
}

void printboard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int checkfreespaces() {
    int freespaces = 9;
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
    if (board[i][j] != ' ') {
    freespaces--;
    }
    }
    }
    return freespaces;
}

void playermove() {
    int x, y;
    do {
        printf("Enter x-axis move (1-3): ");
        scanf("%d", &x);
        printf("Enter y-axis move (1-3): ");
        scanf("%d", &y);

        x--; y--;
        if (x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] != ' ') {
        printf("Invalid move! Try again.\n");
        } else {
        board[x][y] = PLAYER;
        break;
    }
    } while (1);
}

void player2move() {
    int x, y;
    do {
    printf("Enter x-axis move (1-3): ");
    scanf("%d", &x);
    printf("Enter y-axis move (1-3): ");
    scanf("%d", &y);

    x--; y--;
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] != ' ') {
    printf("Invalid move! Try again.\n");
    } else {
    board[x][y] = PLAYER2;
    break;
    }
    } while (1);
}

void computermove() {
    int x, y;

    if (checkfreespaces() > 0) {
    if (difficulty == 1) { // Easy: Random move
    do {
    x = rand() % 3;
    y = rand() % 3;
    } while (board[x][y] != ' ');

    } else if (difficulty == 2) { // Medium: Block player
    for (x = 0; x < 3; x++) {
    for (y = 0; y < 3; y++) {
    if (board[x][y] == ' ') {
    board[x][y] = PLAYER;
    if (checkwinner() == PLAYER) {
    board[x][y] = COMPUTER;
    return;
    }
    board[x][y] = ' ';
    }
    }
    }
    do {
    x = rand() % 3;
    y = rand() % 3;
    } while (board[x][y] != ' ');

    } else if (difficulty == 3) { // Hard: Try to win or block
    for (x = 0; x < 3; x++) {
    for (y = 0; y < 3; y++) {
    if (board[x][y] == ' ') {
    board[x][y] = COMPUTER;
    if (checkwinner() == COMPUTER) return;
    board[x][y] = PLAYER;
    if (checkwinner() == PLAYER) {
    board[x][y] = COMPUTER;
    return;
    }
    board[x][y] = ' ';
    }
    }
    }
    do {
    x = rand() % 3;
    y = rand() % 3;
    } while (board[x][y] != ' ');
    }

    board[x][y] = COMPUTER;
    }
}

char checkwinner() {
    for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
    return board[i][0];
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
    return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
    return board[0][0];
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
    return board[0][2];
    return ' ';
}

void printwinner(char winner) {
	FILE *resultsFile = fopen("results.txt", "a"); // Open file in append mode
    if (!resultsFile) {
    printf("Error: Could not open results file.\n");
    return;
    }
    if (winner == PLAYER) {
    printf("%s Wins!\n", player1Name);
    fprintf(resultsFile, "Mode: Player vs Computer\nPlayer 1: %s\nComputer\nWinner: %s\nDifficulty: %d\n\n", player1Name, player1Name, difficulty);
    } else if (winner == COMPUTER) {
    printf("Computer Wins!\n");
    fprintf(resultsFile, "Mode: Player vs Computer\nPlayer 1: %s\nComputer\nWinner: %s\nDifficulty: %d\n\n", player1Name,difficulty);
    } else {
    printf("It's a Tie!\n");
    fprintf(resultsFile, "Mode: Player vs Computer\nPlayer 1: %s\nComputer\nResult: Tie\nDifficulty: %d\n\n", player1Name, difficulty);
    }
    fclose(resultsFile);
}

void printwinnerpvp(char winner) {
	FILE *resultsFile = fopen("results.txt", "a"); // Open file in append mode
    if (!resultsFile) {
    printf("Error: Could not open results file.\n");
    return;
    }

    if (winner == PLAYER) {
    printf("%s Wins!\n", player1Name);
    fprintf(resultsFile, "Mode: Player vs Player\nPlayer 1: %s\nPlayer 2: %s\nWinner: %s\n\n", player1Name, player2Name, player1Name);
    } else if (winner == PLAYER2) {
    printf("%s Wins!\n", player2Name);
    fprintf(resultsFile, "Mode: Player vs Player\nPlayer 1: %s\nPlayer 2: %s\nWinner: %s\n\n", player1Name, player2Name, player2Name);
    } else {
    printf("It's a Tie!\n");
    fprintf(resultsFile, "Mode: Player vs Player\nPlayer 1: %s\nPlayer 2: %s\nResult: Tie\n\n", player1Name, player2Name);
    }
    fclose(resultsFile);
    }


void printlogo() {
    printf("\n%s", CYAN);
    printf("************************\n");
    printf("*     %sTIC TAC TOE%s      *\n", RED, CYAN);
    printf("************************\n");
    printf("%s       |     |     \n", GREEN);
    printf("   X   |  O  |  X   \n");
    printf(" ______|_____|______\n");
    printf("       |     |      \n");
    printf("   O   |  X  |  O   \n");
    printf(" ______|_____|______\n");
    printf("       |     |      \n");
    printf("   X   |  O  |  X   \n");
    printf("       |     |      \n");
    printf("%s****************************%s\n", CYAN, RESET);
}
