#include <stdio.h>

#define MAXIMUM_SIZE 100001
short find_remainder_with_9(char[]);
int min(int, int);
int main()
{
    unsigned int no_of_test_cases, i;
    char current_number[MAXIMUM_SIZE];
    short answer;

    scanf("%u", &no_of_test_cases);

    for(i = 0; i < no_of_test_cases; i++)
    {
        scanf("%s",current_number);
        answer = find_remainder_with_9(current_number);
        printf("%hu\n",answer);
    }

    return 0;
}

short find_remainder_with_9(char current_number[])
{
    short remainder_with_9 = 0;
    unsigned long i, sum = 0;

    for(i = 0; current_number[i] != '\0'; i++)
    {
        sum = (sum + current_number[i] - '0');
    }

    //Single digit numbers have to become 9, not 0.
    //Returning the smallest value. 0,1,2,3,4,-4,-3,-2,-1
    if( (sum >= 9) || ((current_number[1] == '\0') ) )
    {
        remainder_with_9 = min(9-(sum)%9, sum%9);
    }
    else
    {
        remainder_with_9 = 9 - (sum)%9;
    }
    return remainder_with_9;
}

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}
