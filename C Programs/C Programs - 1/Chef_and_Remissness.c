#include <stdio.h>

int max(int, int);
int main()
{
    short no_of_test_cases, i;
    int minimum_visits, maximum_visits, count_of_A, count_of_B;
    scanf("%hu",&no_of_test_cases);
    for(i = 0; i < no_of_test_cases; i++)
    {
        scanf("%d %d",&count_of_A, &count_of_B);
        minimum_visits = max(count_of_A, count_of_B);
        maximum_visits = count_of_A + count_of_B;
        printf("%d\t%d\n",minimum_visits, maximum_visits);
    }
    return 0;
}

int max(int a,int b)
{
   return (a > b) ? a : b;
}
