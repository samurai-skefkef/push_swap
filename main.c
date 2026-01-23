#include "push_swap.h"

int valid_string(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (i > 0 && str[i] == '"' && str[i + 1] == '\0')
            return (1);
        
        i++;
    }
}

int is_valid(int argc, char **argv)
{
    int i;

    i = 2;
    while (i <= argc)
    {
        if (*argv[0] == '"')
        {

        }
        i++;
    }
}

int main(int argc, char **argv)
{

}