#include "stdio.h"

void to_binary(unsigned long);

int main()
{
    unsigned int number;
    
    printf("Enter an interger (q to quite): \n");
    
    while (scanf("%ul", &number) == 1) {
        printf("Binary equivalent: ");
        to_binary(number);
        putchar('\n');
        printf("Enter an interger (q to quite): \n");
    }
    printf("Done\n");
    
    return 0;
}

void to_binary(unsigned long n)
{
    int r;
    r = n % 2;
    if (n >= 2)
        to_binary(n / 2);
    putchar('0' + r);
    
    return;
}
