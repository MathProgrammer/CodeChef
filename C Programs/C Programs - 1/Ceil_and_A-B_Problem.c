#include <stdio.h>

int main()
{
    unsigned int num_a, num_b, difference;
    scanf("%u %u",&num_a, &num_b);

    difference = num_a - num_b;

    //Changing the last digit of difference - If it is 9, subtracting 1 so that only one digit changes. In all other cases, add 1
    difference = (difference%10 == 9) ? difference - 1:  difference + 1;
    printf("%u\n",difference);
    return 0;
}
