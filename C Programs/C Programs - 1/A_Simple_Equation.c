#include <stdio.h>

int main()
{
    int N, a, a_bound, b, b_bound, c, c_bound, no_of_test_cases, i;
    long long no_of_solutions;
    scanf("%d",&no_of_test_cases);

    for(i = 1; i <= no_of_test_cases; i++)
    {
        scanf("%d %d %d %d",&N, &a_bound, &b_bound, &c_bound);
        no_of_solutions = 0;

        for(a = 0; a <= a_bound; a++)
        {
            for(b = 0; b <= b_bound; b++)
            {
                c = N - (a + b); //If this c is less than c_bound, then for a and b fixed, all c smaller than it satisfies the equation

                if(c >= 0)
                {
                    no_of_solutions += (c <= c_bound ? c : c_bound) + 1;//1 is added because we start counting from 0
                }

            }
        }

        printf("%lld\n",no_of_solutions);
    }
    return 0;
}
