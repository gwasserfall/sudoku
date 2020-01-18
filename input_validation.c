#include "sudoku.h"

int validate_input(int argc, char **argv)
{
    // argc must be 10
    if (argc != 10)
    {
        printf("argc must be 10");
        return (false);
    }

    argv++;
    while (*argv)
    {
        printf("%s\n", *argv);
        if (ft_strlen(*argv) != 9)
        {
            printf("Invlaid line length\n");
            return (false);
        }

        if (!is_valid_line(*argv))
        {
            printf("Invalid line\n");
            return (false);
        }

        argv++;
    }
    return (true);
}

int is_valid_line(char *line)
{
    while (*line)
    {
        if (!is_valid_digit(*line))
            return (false);
        line++;
    }
    return (true);
}

int is_valid_digit(char c)
{
    if (c == '.' || (c >= '1' && c <= '9'))
        return (true);
    return (false);
}