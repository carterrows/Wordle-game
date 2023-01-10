// Wordle game recreation
// 'x' for gray, '-' for yellow, '+' for green

#include <stdio.h>
#include <string.h>

void get_guess(int round, char guess[]);
int print_info(char key[], char guess[]);
int check_letter(char key[], char guess[], int index);

int main()
{
    char key[10];
    char guess[10];

    printf("\nEnter key word:\t");
    scanf("%s", key);

    if(strlen(key) != 5)
    {
        printf("Only 5 letter words are allowed in Wordle.\n\n");
        return 0;
    }

    int i = 1;
    while(i <= 5)
    {
        get_guess(i, guess);
        if(strlen(guess) == 5)
        {
            if(print_info(key, guess) == 0)
            {
                printf("\n\nYou have won in %d attempt(s)!\nThe word was '%s'\n\n", i, key);
                return 0;
            }
            printf("\n");
            i++;
        }
        if(strlen(guess) != 5)
        {
            printf("Only 5 letter guesses are allowed.\n");
        }
    }
    
    printf("\nAll 5 attempts are used, you have lost :(\nThe word was '%s'\n\n", key);
    return 0;
}

void get_guess(int round, char guess[])
{
    printf("\nGuess #%d:\t", round);
    scanf("%s", guess);
}

int print_info(char key[], char guess[])
{
    int check = strcmp(key, guess);
    if(check == 0)
    {
        printf("Guess info:\t+ + + + +");
        return check;
    }
    printf("Guess info:\t");
    for(int i = 0; i < 5; i++)
    {
        if(guess[i] == key[i])
        {
            printf("+ ");
        }
        else if(check_letter(key, guess, i))
        {
            printf("- ");
        }
        else
        {
            printf("x ");
        }
    }
}

int check_letter(char key[], char guess[], int index)
{
    for(int i = 0; i < 5; i++)
    {
        if(guess[index] == key[i])
        {
            return 1;
        }
    }
    return 0;
}