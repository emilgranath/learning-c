#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int MAX_GUESSES = 7;
    srand((unsigned)time(NULL));
    int secret = rand() % 100 + 1;
    int numberGuessed;
    int numberOfGuesses = 0;

    printf("Guess the number that the computer has selected: ");
    scanf("%d", &numberGuessed);

    while (numberGuessed != secret)
    {
        numberOfGuesses++;
        if (numberOfGuesses >= MAX_GUESSES)
        {
            printf("You're out of guesses, the correct answer was: %d\n", secret);
            return EXIT_SUCCESS;
        }

        if (numberGuessed > secret)
        {
            printf("Your guess it to high!\n");
        }
        else if (numberGuessed < secret)
        {
            printf("Your guess is to low!\n");
        }
        else
        {
            printf("You guessed correct!\n");
            return EXIT_SUCCESS;
        }

        printf("Guess again (you have %d guesses left): ", MAX_GUESSES - numberOfGuesses);
        scanf("%d", &numberGuessed);
    }

    return EXIT_SUCCESS;
}
