#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int characterCount = 0;
    int wordCount = 0;
    int lineCount = 0;
    if (argc > 1 && argv[1] == NULL)
    {
        fprintf(stderr, "Usage: wc <file-name>");
        return EXIT_FAILURE;
    }
    
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "File '%s' does not exist. Please enter a valid filename.", argv[1]);
        return EXIT_FAILURE;
    }

    int c;
    bool isInWord = false;

    while((c = fgetc(file)) != EOF)
    {
        characterCount++;
        if (c == '\n')
        {
            lineCount++;
        }
        
        if (isspace(c))
        {
            if (isInWord)
            {
                wordCount++;
                isInWord = false;
            }
        }
        else
        {
            isInWord = true;
        }
    }

    // File ended in word
    if (isInWord)
    {
        wordCount++;
    }

    if (ferror(file))
    {
        perror(argv[1]);
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);

    printf("Rader: %d\t Ord: %d\t Tecken: %d\n", lineCount, wordCount, characterCount);
    return EXIT_SUCCESS;
}