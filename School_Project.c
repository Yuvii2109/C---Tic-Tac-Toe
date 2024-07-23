#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

void reset();
void print();
int free_check();
void player1_move();
void player2_move();
void computer();
char check_winner();
void print_winner(char);

int main()
{
    char winner = ' ';
    char str[20];
    printf("Multiplayer or Computer - ");
    scanf("%s", str);
    reset();
    while (winner == ' ' && free_check() != 0)
    {
        if (strcmp(str, "Multiplayer") == 0 || strcmp(str, "multiplayer") == 0) 
        {
            print();
            player1_move();
            winner = check_winner();
            if (winner != ' ' || free_check() == 0)
                break;

            player2_move();
            winner = check_winner();
            if (winner != ' ' || free_check() == 0)
                break;
        }
        else if (strcmp(str, "Computer") == 0 || strcmp(str, "computer") == 0) 
        {
            print();
            player1_move();
            winner = check_winner();
            if (winner != ' ' || free_check() == 0)
                break;

            computer();
            winner = check_winner();
            if (winner != ' ' || free_check() == 0)
                break;
        }
        else
        {
            printf("Enter a valid input");
        }
    }
    print();
    print_winner(winner);
    return 0;
}

void reset()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void print()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n___|___|___\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n___|___|___\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int free_check()
{
    int free = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                free--;
            }
        }
    }
    return free;
}

void player1_move()
{
    int x, y;
    while (1)
    {
        printf("Enter row (1-3) - ");
        scanf("%d", &x);
        x--;
        printf("Enter column (1-3) - ");
        scanf("%d", &y);
        y--;
        if (x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == ' ')
        {
            board[x][y] = PLAYER1;
            break;
        }
        else
        {
            printf("Invalid move\n");
        }
    }
}

void player2_move()
{
    int x, y;
    while (1)
    {
        printf("Enter row (1-3) - ");
        scanf("%d", &x);
        x--;
        printf("Enter column (1-3) - ");
        scanf("%d", &y);
        y--;
        if (x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == ' ')
        {
            board[x][y] = PLAYER2;
            break;
        }
        else
        {
            printf("Invalid move\n");
        }
    }
}

void computer()
{
    int x, y;
    srand(time(0));
    do
    {
        x = rand() % 3;
        y = rand() % 3;
    } while (board[x][y] != ' ');

    board[x][y] = COMPUTER;
}

char check_winner()
{
    // Row check
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];
    }
    // Column check
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i];
    }
    // Diagonal check
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[0][2];
    // In case of no winner
    return ' ';
}

void print_winner(char winner)
{
    if (winner == PLAYER1)
    {
        printf("Player 'X' wins\n");
    }
    else if (winner == PLAYER2)
    {
        printf("Player 'O' wins\n");
    }
    else if (winner == COMPUTER)
    {
        printf("Computer wins\n");
    }
    else if (free_check() == 0)
    {
        printf("It's a tie\n");
    }
}