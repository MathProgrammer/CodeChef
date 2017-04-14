#include <stdio.h>
#define MASK_1 0x5555
#define MASK_2 0x3333
#define MASK_3 0x0F0F
#define MASK_4 0x00FF

short find_minimum_no_of_dishes(unsigned int);
short population_count(short);

int main()
{
    short no_of_test_cases, i, no_of_dishes;
    unsigned int total_price;

    scanf("%hu", &no_of_test_cases);
    for(i = 0; i < no_of_test_cases; i++)
    {
        scanf("%u",&total_price);
        no_of_dishes = find_minimum_no_of_dishes(total_price);
        printf("%hu\n",no_of_dishes);
    }
    return 0;
}

short find_minimum_no_of_dishes(unsigned int total_price)
{
    /*The minimum number is the number of 1s in the binary representation of a number. However, there's a constraint. We can only use numbers till 2048.
    So, the following greedy strategy is used - Use as many 2048s as possible. This is optimal because we are only using one number.
    When the price left is less than 2048, we count the number of 1s in it's binary representation.
    The answer is p/2048 + pop_count(p%2048), where pop_count(x) is the number of 1s in it's binary representation.*/
    return (total_price/(1 << 11) + population_count(total_price%(1 << 11)));
}

short population_count(short x)
{
    short population_count = x;

    population_count = (population_count&MASK_1) + ((population_count >> 1)&MASK_1);
    population_count = (population_count&MASK_2) + ((population_count >> 2)&MASK_2);
    population_count = (population_count&MASK_3) + ((population_count >> 4)&MASK_3);
    population_count = (population_count&MASK_4) + ((population_count >> 8)&MASK_4);
    return population_count;
}
