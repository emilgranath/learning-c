#include <stdlib.h>
#include <stdio.h>

static int parse_number(const char *s, double *out)
{
    char *end;
    double value = strtod(s, &end);

    if (end == s || *end != '\0')
    {
        return EXIT_SUCCESS;
    }

    *out = value;

    return EXIT_FAILURE;
}

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        char *end;
        double a = strtod(argv[1], &end);
        printf(end);
        double b = strtod(argv[3], &end);
        printf(end);

        

        double result = 0.0;
        char operator = argv[2][0];

        switch (operator)
        {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case 'x':
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        default:
        fprintf(stderr, "Error: unknown operator '%s'. \n", argv[2]);
            break;
        }

        printf("%g", result);
    }
    else
    {
        fprintf(stderr, "Usage: ./calc <number> <+|-|*|/> <number>\n");
    }

    return EXIT_SUCCESS;
}