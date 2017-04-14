#include <stdio.h>
unsigned int find_greatest_traingular_number_less_than(unsigned int);
int main()
{
    short i, no_of_test_cases;
    unsigned int max_height, no_of_coins;
    scanf("%hu",&no_of_test_cases);

    for(i = 1; i <=no_of_test_cases; i++)
    {
        scanf("%u", &no_of_coins);
        max_height = find_greatest_traingular_number_less_than(no_of_coins);
        printf("%u\n",max_height);
    }
    return 0;
}

unsigned int find_greatest_traingular_number_less_than(unsigned int no_of_coins)
{
    unsigned int i, height ;
    for(i = 1; i*(i+1)/2 <= no_of_coins; i++); //Greatest T(n) <= no of coins

    if(i*(i+1)/2 != no_of_coins)
    {
        height = i - 1;
    }
    else
    {
        height = i;
    }
    return height;
}
