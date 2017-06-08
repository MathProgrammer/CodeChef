#include <stdio.h>

int main()
{
    int number_of_multiples = 0, number, number_of_numbers, k;
    scanf("%d %d",&number_of_numbers, &k);

    while(number_of_numbers--)
    {
        scanf("%d",&number);
        number_of_multiples += (number%k == 0 ? 1 : 0);
    }
    printf("%d\n",number_of_multiples);
    return 0;
}
