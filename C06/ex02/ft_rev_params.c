#include <unistd.h>

void    ft_putstr(char *str)
{
    int i;

    i = -1;
    while(str[++i])
    {
        write(1, &str[i], 1);
    }
}

int main(int argc, char **argv)
{
    argc--;
    while(argc > 0)
    {
        ft_putstr(argv[argc]);
        write(1, "\n", 2);
        argc--;
    }
}
