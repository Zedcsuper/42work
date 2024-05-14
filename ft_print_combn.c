
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_combn_recursive(int n, int index, int start, int *array)
{
    int i;
    if (index == n)
    {
        for (i = 0; i < n; i++)
            ft_putchar(array[i] + '0');
        if (array[0] < 10 - n)
        {
            ft_putchar(',');
            ft_putchar(' ');
        }
        return;
    }
    for (i = start; i <= 9; i++)
    {
        array[index] = i;
        ft_print_combn_recursive(n, index + 1, i + 1, array);
    }
}

void ft_print_combn(int n)
{
    int array[n];
    ft_print_combn_recursive(n, 0, 0, array);
}

int main()
{
    int n = 3; // Change n to the desired number of digits
    ft_print_combn(n);
    return 0;
}

